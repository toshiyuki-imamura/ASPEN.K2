#DSYMVU#GB200#GB200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "DSYMVU on a <GB200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GB200-DSYMVU.eps"
plot   "log-ASPEN.K2-1.13-DSYMVU-GB200-for-2026:10:01-14:46:08" u 2:($5<2*3325.07?$5:-1000) t "log-ASPEN.K2-1.13-DSYMVU-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-DSYMVU-GB200-for-2026:10:01-14:46:08" u 2:($5<2*3325.07?$5:-1000) t "log-CUDA-13.3-DSYMVU-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-DSYMVUnoAtomic-GB200-for-2026:10:01-14:46:08" u 2:($5<2*3325.07?$5:-1000) t "log-CUDA-13.3-DSYMVUnoAtomic-GB200-for-2026:10:01-14:46:08" 
clear
set term png
set output "plot-data-GB200-DSYMVU.png"
plot   "log-ASPEN.K2-1.13-DSYMVU-GB200-for-2026:10:01-14:46:08" u 2:($5<2*3325.07?$5:-1000) t "log-ASPEN.K2-1.13-DSYMVU-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-DSYMVU-GB200-for-2026:10:01-14:46:08" u 2:($5<2*3325.07?$5:-1000) t "log-CUDA-13.3-DSYMVU-GB200-for-2026:10:01-14:46:08" , "log-CUDA-13.3-DSYMVUnoAtomic-GB200-for-2026:10:01-14:46:08" u 2:($5<2*3325.07?$5:-1000) t "log-CUDA-13.3-DSYMVUnoAtomic-GB200-for-2026:10:01-14:46:08" 
clear
exit
