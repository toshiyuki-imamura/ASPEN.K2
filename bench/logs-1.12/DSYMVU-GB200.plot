#DSYMVU#GB200#GB200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "DSYMVU on a <GB200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GB200-DSYMVU.eps"
plot   "log-ASPEN.K2-1.12-DSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*3444.47?$5:-1000) t "log-ASPEN.K2-1.12-DSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-DSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*3444.47?$5:-1000) t "log-CUDA-13.1-DSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-DSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" u 2:($5<2*3444.47?$5:-1000) t "log-CUDA-13.1-DSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" 
clear
set term png
set output "plot-data-GB200-DSYMVU.png"
plot   "log-ASPEN.K2-1.12-DSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*3444.47?$5:-1000) t "log-ASPEN.K2-1.12-DSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-DSYMVU-GB200-for-2026:08:10-11:38:52" u 2:($5<2*3444.47?$5:-1000) t "log-CUDA-13.1-DSYMVU-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-DSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" u 2:($5<2*3444.47?$5:-1000) t "log-CUDA-13.1-DSYMVUnoAtomic-GB200-for-2026:08:10-11:38:52" 
clear
exit
