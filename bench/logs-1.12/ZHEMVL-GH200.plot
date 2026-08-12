set key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "ZHEMVL on a <>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GH200-ZHEMVL.eps"
plot   "log-ASPEN.K2-1.12-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" u 2:($5<2*3623.71?$5:-1000) t "log-ASPEN.K2-1.12-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" , "log-CUDA-13.2-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" u 2:($5<2*3623.71?$5:-1000) t "log-CUDA-13.2-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" , "log-CUDA-13.2-ZHEMVLnoAtomic-GH200_480GB-for-2026:08:02-08:28:25" u 2:($5<2*3623.71?$5:-1000) t "log-CUDA-13.2-ZHEMVLnoAtomic-GH200_480GB-for-2026:08:02-08:28:25" 
clear
set term png
set output "plot-data-GH200-ZHEMVL.png"
plot   "log-ASPEN.K2-1.12-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" u 2:($5<2*3623.71?$5:-1000) t "log-ASPEN.K2-1.12-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" , "log-CUDA-13.2-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" u 2:($5<2*3623.71?$5:-1000) t "log-CUDA-13.2-ZHEMVL-GH200_480GB-for-2026:08:02-08:28:25" , "log-CUDA-13.2-ZHEMVLnoAtomic-GH200_480GB-for-2026:08:02-08:28:25" u 2:($5<2*3623.71?$5:-1000) t "log-CUDA-13.2-ZHEMVLnoAtomic-GH200_480GB-for-2026:08:02-08:28:25" 
clear
exit
