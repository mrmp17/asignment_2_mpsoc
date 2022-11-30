############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project different_Kalman
set_top KalmanFilterKernel
add_files src/kalman_2/vitis/KF_kernel.cpp
add_files src/kalman_2/vitis/KF_kernel.h
add_files src/kalman_2/vitis/matrix_ops.h
add_files -tb src/hls_src/data.h
add_files -tb src/kalman_2/vitis/kf_test.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu3eg-sbva484-1-i}
create_clock -period 10 -name default
source "./different_Kalman/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl vhdl -format ip_catalog -output /home/tjaz/Pictures/KalmanFilterKernel.zip
