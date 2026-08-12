#SSYMVU#GB200#GB200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "SSYMVU on a <GB200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GB200-SSYMVU.eps"
plot   "log-ASPEN.K2-1.12-SSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*6986.92?$5:-1000) t "log-ASPEN.K2-1.12-SSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-SSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*6986.92?$5:-1000) t "log-CUDA-13.1-SSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-SSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" u 2:($5<2*6986.92?$5:-1000) t "log-CUDA-13.1-SSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" 
clear
set term png
set output "plot-data-GB200-SSYMVU.png"
plot   "log-ASPEN.K2-1.12-SSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*6986.92?$5:-1000) t "log-ASPEN.K2-1.12-SSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-SSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*6986.92?$5:-1000) t "log-CUDA-13.1-SSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-SSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" u 2:($5<2*6986.92?$5:-1000) t "log-CUDA-13.1-SSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" 
clear
exit
