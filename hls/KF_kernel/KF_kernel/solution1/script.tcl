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
add_files -tb ../../src/hls_src/kf_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../../src/hls_src/data.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu3eg-sbva484-1-i}
create_clock -period 10 -name default
config_export -format ip_catalog -output /home/tjaz/ass2/asignment_2_mpsoc/ip/KalmanFilterKernel.zip -rtl vhdl
source "./KF_kernel/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl vhdl -format ip_catalog -output /home/tjaz/ass2/asignment_2_mpsoc/ip/KalmanFilterKernel.zip
