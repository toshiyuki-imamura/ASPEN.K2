#SSYMVL#GB200#GB200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "SSYMVL on a <GB200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GB200-SSYMVL.eps"
plot   "log-ASPEN.K2-1.13-SSYMVL-GB200-for-2026:10:01-14:46:08" u 2:($5<2*5993.72?$5:-1000) t "log-ASPEN.K2-1.13-SSYMVL-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-SSYMVL-GB200-for-2026:10:01-14:46:08" u 2:($5<2*5993.72?$5:-1000) t "log-CUDA-13.3-SSYMVL-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-SSYMVLnoAtomic-GB200-for-2026:10:01-14:46:08" u 2:($5<2*5993.72?$5:-1000) t "log-CUDA-13.3-SSYMVLnoAtomic-GB200-for-2026:10:01-14:46:08" 
clear
set term png
set output "plot-data-GB200-SSYMVL.png"
plot   "log-ASPEN.K2-1.13-SSYMVL-GB200-for-2026:10:01-14:46:08" u 2:($5<2*5993.72?$5:-1000) t "log-ASPEN.K2-1.13-SSYMVL-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-SSYMVL-GB200-for-2026:10:01-14:46:08" u 2:($5<2*5993.72?$5:-1000) t "log-CUDA-13.3-SSYMVL-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-SSYMVLnoAtomic-GB200-for-2026:10:01-14:46:08" u 2:($5<2*5993.72?$5:-1000) t "log-CUDA-13.3-SSYMVLnoAtomic-GB200-for-2026:10:01-14:46:08" 
clear
exit
