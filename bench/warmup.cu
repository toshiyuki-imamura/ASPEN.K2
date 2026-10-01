#include <stdio.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cuda.h>
#include <nvml.h>

__device__ float sumup0 = 0.;
__device__ float sumup  = 0.;

__global__ void
WarmUp_GPU_ ( const int iterations )
{

  float x[64];

  const float zero = (float)(iterations>>12);
  const float t    = sumup0;

  for ( int m=0; m<64; m++ ) { x[m] = zero; }

  __threadfence_system( );
#pragma unroll 1
  for ( int i=0; i<iterations; i++ ) {
  for ( int j=0; j<1024; j++ ) {
//  for ( int k=0; k<1024; k++ ) {

    for ( int m=0; m<64; m++ ) {
      asm volatile ( "fma.rn.f32 %0, %1, %2, %0;"
                   : "+f"(x[m]) : "f"(t), "f"(t) );
    }

//  }
  }
  }
  __threadfence_system( );
  if ( threadIdx.x == 0 ) {
    for ( int m=0; m<64; m++ ) { sumup *= x[m]; }
  }
  __threadfence_system( );
  __threadfence_system( );
  __threadfence_system( );
  __threadfence_system( );
}


nvmlDevice_t
GetDeviceHandle ( const int device_id )
{
  nvmlDevice_t device;
  nvmlDeviceGetHandleByIndex( device_id, &device );
  return device;
}

int
GetBlockSize( const int device_id )
{
  struct cudaDeviceProp deviceProp;
  int numBlocks;

  cudaGetDeviceProperties ( &deviceProp, device_id );
  const int numbers_MPs = deviceProp.multiProcessorCount;

  cudaOccupancyMaxActiveBlocksPerMultiprocessor ( &numBlocks, WarmUp_GPU_, 256, 0 );

  const int totalBlocks = numbers_MPs * numBlocks;

  return totalBlocks;
}

nvmlPstates_t
GetPState_on_GPU( const nvmlDevice_t device )
{
  nvmlPstates_t pState;
  nvmlDeviceGetPerformanceState ( device, &pState );
  return pState;
}

double
GetTemperature_on_GPU( const nvmlDevice_t device )
{
#if NVML_API_VERSION >= 12000
  nvmlThermalSettings_t ts;
  ts.version = NVML_THERMAL_SETTINGS_VER;
  nvmlDeviceGetThermalSettings( device, NVML_TEMPERATURE_GPU, &ts );
  return (double)ts.defaultTemprature;
#else
  unsigned int temp;
  nvmlDeviceGetTemperature( device, NVML_TEMPERATURE_GPU, &temp );
  return (double)temp;
#endif
}


extern "C" void
WarmUp_GPU ( const int device_id )
{
  nvmlReturn_t err = nvmlInit();
  if ( err != NVML_SUCCESS ) {
    return;
  }

  const nvmlDevice_t device = GetDeviceHandle ( device_id );
  const int totalBlocks = GetBlockSize( device_id );

  double temp[2];
  temp[0] = GetTemperature_on_GPU( device );

  for ( int itr = 64; itr <= 1024; itr *= 2, temp[0] = temp[1] ) {

    cudaDeviceSynchronize();
    WarmUp_GPU_ <<< 256, totalBlocks >>> ( itr ); 
    cudaDeviceSynchronize();

    const nvmlPstates_t pState = GetPState_on_GPU( device );
    if ( pState <= NVML_PSTATE_1 ) break;

    temp[1] = GetTemperature_on_GPU( device );
    const double ratio = fabs(temp[1]-temp[0])/temp[0];
    if ( temp[1] >= 36. && ratio < 0.10 ) break;

  }

  nvmlShutdown();
}

