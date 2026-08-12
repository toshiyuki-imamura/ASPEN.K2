#ZHEMVL#GB200#GB200 1GPUset key bottom
set grid
set pointsize 0.3
set yrange [0:]
set title "ZHEMVL on a <GB200 1GPU>"
set xlabel "[dimension]"
set ylabel "[GFLOPS]"
set term post eps color
set output "plot-data-GB200-ZHEMVL.eps"
plot   "log-ASPEN.K2-1.12-ZHEMVL-GB200-for-2026:08:10-11:38:52" u 2:($5<2*7544.8?$5:-1000) t "log-ASPEN.K2-1.12-ZHEMVL-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-ZHEMVL-GB200-for-2026:08:10-11:38:52" u 2:($5<2*7544.8?$5:-1000) t "log-CUDA-13.1-ZHEMVL-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-ZHEMVLnoAtomic-GB200-for-2026:08:10-11:38:52" u 2:($5<2*7544.8?$5:-1000) t "log-CUDA-13.1-ZHEMVLnoAtomic-GB200-for-2026:08:10-11:38:52" 
clear
set term png
set output "plot-data-GB200-ZHEMVL.png"
plot   "log-ASPEN.K2-1.12-ZHEMVL-GB200-for-2026:08:10-11:38:52" u 2:($5<2*7544.8?$5:-1000) t "log-ASPEN.K2-1.12-ZHEMVL-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-ZHEMVL-GB200-for-2026:08:10-11:38:52" u 2:($5<2*7544.8?$5:-1000) t "log-CUDA-13.1-ZHEMVL-GB200-for-2026:08:10-11:38:52" , "log-CUDA-13.1-ZHEMVLnoAtomic-GB200-for-2026:08:10-11:38:52" u 2:($5<2*7544.8?$5:-1000) t "log-CUDA-13.1-ZHEMVLnoAtomic-GB200-for-2026:08:10-11:38:52" 
clear
exit
