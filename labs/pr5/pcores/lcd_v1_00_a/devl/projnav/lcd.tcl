project new U:/hlocal/git/SE/extraordinaria/proyecto/pcores/lcd_v1_00_a/devl/projnav/lcd.xise;
project set family spartan3;
project set device xc3s1000;
project set package ft256;
project set speed -5;
project set top_level_module_type HDL;
project set synthesis_tool "XST (VHDL/Verilog)";
lib_vhdl new lcd_v1_00_a;
xfile add U:/hlocal/git/SE/extraordinaria/proyecto/pcores/lcd_v1_00_a/hdl/vhdl/lcd.vhd -lib_vhdl lcd_v1_00_a;
xfile add U:/hlocal/git/SE/extraordinaria/proyecto/pcores/lcd_v1_00_a/hdl/vhdl/user_logic.vhd -lib_vhdl lcd_v1_00_a;
lib_vhdl new proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/proc_common_pkg.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/ipif_pkg.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/or_muxcy.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/or_gate128.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/family_support.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pselect_f.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/counter_f.vhd -lib_vhdl proc_common_v3_00_a;
lib_vhdl new plbv46_slave_single_v1_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/plbv46_slave_single_v1_01_a/hdl/vhdl/plb_address_decoder.vhd -lib_vhdl plbv46_slave_single_v1_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/plbv46_slave_single_v1_01_a/hdl/vhdl/plb_slave_attachment.vhd -lib_vhdl plbv46_slave_single_v1_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/plbv46_slave_single_v1_01_a/hdl/vhdl/plbv46_slave_single.vhd -lib_vhdl plbv46_slave_single_v1_01_a;
lib_vhdl new proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/coregen_comp_defs.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/blk_mem_gen_wrapper.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/inferred_lut4.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_counter_bit.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_counter.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_counter_top.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_occ_counter.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_occ_counter_top.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_adder_bit.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_adder.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pf_dpram_select.vhd -lib_vhdl proc_common_v3_00_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/srl16_fifo.vhd -lib_vhdl proc_common_v3_00_a;
lib_vhdl new wrpfifo_v5_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/wrpfifo_v5_01_a/hdl/vhdl/pf_dly1_mux.vhd -lib_vhdl wrpfifo_v5_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/wrpfifo_v5_01_a/hdl/vhdl/blkmem_wrapper.vhd -lib_vhdl wrpfifo_v5_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/wrpfifo_v5_01_a/hdl/vhdl/wrpfifo_dp_cntl.vhd -lib_vhdl wrpfifo_v5_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/wrpfifo_v5_01_a/hdl/vhdl/ipif_control_wr_dre.vhd -lib_vhdl wrpfifo_v5_01_a;
xfile add C:/software/electronica/xilinx/14.1/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/wrpfifo_v5_01_a/hdl/vhdl/wrpfifo_top.vhd -lib_vhdl wrpfifo_v5_01_a;
project close;
