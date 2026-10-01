#DSYMVU#GH200_480GB#GH200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "DSYMVU on a <GH200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GH200_480GB-DSYMVU.eps"
plot   "log-ASPEN.K2-1.13-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*1832.34?$5:-1000) t "log-ASPEN.K2-1.13-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*1832.34?$5:-1000) t "log-CUDA-13.4-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-DSYMVUnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*1832.34?$5:-1000) t "log-CUDA-13.4-DSYMVUnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" 
clear
set term png
set output "plot-data-GH200_480GB-DSYMVU.png"
plot   "log-ASPEN.K2-1.13-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*1832.34?$5:-1000) t "log-ASPEN.K2-1.13-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*1832.34?$5:-1000) t "log-CUDA-13.4-DSYMVU-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-DSYMVUnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*1832.34?$5:-1000) t "log-CUDA-13.4-DSYMVUnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" 
clear
exit
