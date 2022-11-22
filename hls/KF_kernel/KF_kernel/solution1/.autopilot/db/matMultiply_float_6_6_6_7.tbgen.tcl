set moduleName matMultiply_float_6_6_6_7
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {matMultiply<float, 6, 6, 6>.7}
set C_modelType { void 0 }
set C_modelArgList {
	{ mat_in_L float 32 regular {array 36 { 1 3 } 1 1 }  }
	{ mat_in_R float 32 regular {array 6 { 1 3 } 1 1 }  }
	{ mat_out float 32 regular {array 36 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "mat_in_L", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "mat_in_R", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "mat_out", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ mat_in_L_address0 sc_out sc_lv 6 signal 0 } 
	{ mat_in_L_ce0 sc_out sc_logic 1 signal 0 } 
	{ mat_in_L_q0 sc_in sc_lv 32 signal 0 } 
	{ mat_in_R_address0 sc_out sc_lv 3 signal 1 } 
	{ mat_in_R_ce0 sc_out sc_logic 1 signal 1 } 
	{ mat_in_R_q0 sc_in sc_lv 32 signal 1 } 
	{ mat_out_address0 sc_out sc_lv 6 signal 2 } 
	{ mat_out_ce0 sc_out sc_logic 1 signal 2 } 
	{ mat_out_we0 sc_out sc_logic 1 signal 2 } 
	{ mat_out_d0 sc_out sc_lv 32 signal 2 } 
	{ grp_fu_3352_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_3352_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_3352_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_3352_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "mat_in_L_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "mat_in_L", "role": "address0" }} , 
 	{ "name": "mat_in_L_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mat_in_L", "role": "ce0" }} , 
 	{ "name": "mat_in_L_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mat_in_L", "role": "q0" }} , 
 	{ "name": "mat_in_R_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "mat_in_R", "role": "address0" }} , 
 	{ "name": "mat_in_R_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mat_in_R", "role": "ce0" }} , 
 	{ "name": "mat_in_R_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mat_in_R", "role": "q0" }} , 
 	{ "name": "mat_out_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "mat_out", "role": "address0" }} , 
 	{ "name": "mat_out_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mat_out", "role": "ce0" }} , 
 	{ "name": "mat_out_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mat_out", "role": "we0" }} , 
 	{ "name": "mat_out_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mat_out", "role": "d0" }} , 
 	{ "name": "grp_fu_3352_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_3352_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_3352_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_3352_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_3352_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_3352_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_3352_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_3352_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "matMultiply_float_6_6_6_7",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "313", "EstimateLatencyMax" : "313",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "mat_in_L", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "mat_in_R", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "mat_out", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.facc_32ns_32ns_1ns_32_3_no_dsp_1_U2", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	matMultiply_float_6_6_6_7 {
		mat_in_L {Type I LastRead 3 FirstWrite -1}
		mat_in_R {Type I LastRead 3 FirstWrite -1}
		mat_out {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "313", "Max" : "313"}
	, {"Name" : "Interval", "Min" : "313", "Max" : "313"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	mat_in_L { ap_memory {  { mat_in_L_address0 mem_address 1 6 }  { mat_in_L_ce0 mem_ce 1 1 }  { mat_in_L_q0 mem_dout 0 32 } } }
	mat_in_R { ap_memory {  { mat_in_R_address0 mem_address 1 3 }  { mat_in_R_ce0 mem_ce 1 1 }  { mat_in_R_q0 mem_dout 0 32 } } }
	mat_out { ap_memory {  { mat_out_address0 mem_address 1 6 }  { mat_out_ce0 mem_ce 1 1 }  { mat_out_we0 mem_we 1 1 }  { mat_out_d0 mem_din 1 32 } } }
}
