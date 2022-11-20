############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project KF_kernel
set_top KalmanFilterKernel
add_files ../../src/hls_src/KF_kernel.cpp
add_files ../../src/hls_src/KF_kernel.h
add_files ../../src/hls_src/matrix_ops.h
add_files -tb ../../src/hls_src/kf_test.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu3eg-sbva484-1-i}
create_clock -period 10 -name default
#source "./KF_kernel/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
