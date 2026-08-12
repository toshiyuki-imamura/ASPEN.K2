#DSYMVU#GH200_480GB#GH200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "DSYMVU on a <GH200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GH200_480GB-DSYMVU.eps"
plot   "log-ASPEN.K2-1.12-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*1832.77?$5:-1000) t "log-ASPEN.K2-1.12-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*1832.77?$5:-1000) t "log-CUDA-13.2-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-DSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*1832.77?$5:-1000) t "log-CUDA-13.2-DSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" 
clear
set term png
set output "plot-data-GH200_480GB-DSYMVU.png"
plot   "log-ASPEN.K2-1.12-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*1832.77?$5:-1000) t "log-ASPEN.K2-1.12-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*1832.77?$5:-1000) t "log-CUDA-13.2-DSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-DSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*1832.77?$5:-1000) t "log-CUDA-13.2-DSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" 
clear
exit
