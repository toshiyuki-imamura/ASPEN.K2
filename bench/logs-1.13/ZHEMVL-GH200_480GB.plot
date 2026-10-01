#ZHEMVL#GH200_480GB#GH200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "ZHEMVL on a <GH200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GH200_480GB-ZHEMVL.eps"
plot   "log-ASPEN.K2-1.13-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*3648.06?$5:-1000) t "log-ASPEN.K2-1.13-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*3648.06?$5:-1000) t "log-CUDA-13.4-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-ZHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*3648.06?$5:-1000) t "log-CUDA-13.4-ZHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" 
clear
set term png
set output "plot-data-GH200_480GB-ZHEMVL.png"
plot   "log-ASPEN.K2-1.13-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*3648.06?$5:-1000) t "log-ASPEN.K2-1.13-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*3648.06?$5:-1000) t "log-CUDA-13.4-ZHEMVL-GH200_480GB-for-2026:09:30-20:07:43" , "log-CUDA-13.4-ZHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" u 2:($5<2*3648.06?$5:-1000) t "log-CUDA-13.4-ZHEMVLnoAtomic-GH200_480GB-for-2026:09:30-20:07:43" 
clear
exit
