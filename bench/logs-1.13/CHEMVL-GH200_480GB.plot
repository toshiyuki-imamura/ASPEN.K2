#CHEMVL#GH200_480GB#GH200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "CHEMVL on a <GH200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GH200_480GB-CHEMVL.eps"
plot   "log-ASPEN.K2-1.13-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*7280.4?$5:-1000) t "log-ASPEN.K2-1.13-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*7280.4?$5:-1000) t "log-CUDA-13.4-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-CHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*7280.4?$5:-1000) t "log-CUDA-13.4-CHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" 
clear
set term png
set output "plot-data-GH200_480GB-CHEMVL.png"
plot   "log-ASPEN.K2-1.13-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*7280.4?$5:-1000) t "log-ASPEN.K2-1.13-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*7280.4?$5:-1000) t "log-CUDA-13.4-CHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-CHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*7280.4?$5:-1000) t "log-CUDA-13.4-CHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" 
clear
exit
