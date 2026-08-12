__forceinline__ __device__ uint
urand( uint & x )
{
  const uint a=1103515245;
  const uint b=12345;
  const uint c=2147483647;
  return ( x = ( ( a * x + b ) & c ) );
}
