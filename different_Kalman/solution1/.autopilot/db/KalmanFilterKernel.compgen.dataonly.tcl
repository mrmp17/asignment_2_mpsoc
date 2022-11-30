# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_AXI_CPU {
q { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
r { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
}
dict set axilite_register_dict AXI_CPU $port_AXI_CPU


