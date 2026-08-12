#SSYMVU#GH200_480GB#GH200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "SSYMVU on a <GH200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GH200_480GB-SSYMVU.eps"
plot   "log-ASPEN.K2-1.12-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*3626.06?$5:-1000) t "log-ASPEN.K2-1.12-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*3626.06?$5:-1000) t "log-CUDA-13.2-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-SSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*3626.06?$5:-1000) t "log-CUDA-13.2-SSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" 
clear
set term png
set output "plot-data-GH200_480GB-SSYMVU.png"
plot   "log-ASPEN.K2-1.12-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*3626.06?$5:-1000) t "log-ASPEN.K2-1.12-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*3626.06?$5:-1000) t "log-CUDA-13.2-SSYMVU-GH200_480GB-for-2026:08:06-23:34:02" , "log-CUDA-13.2-SSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" u 2:($5<2*3626.06?$5:-1000) t "log-CUDA-13.2-SSYMVUnoAtomic-GH200_480GB-for-2026:08:06-23:34:02" 
clear
exit
