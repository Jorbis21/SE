##############################################################################
## Filename:          C:\SE\motorola/drivers/leds_v1_00_a/data/leds_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Wed Jun 26 12:14:39 2024 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "leds" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
