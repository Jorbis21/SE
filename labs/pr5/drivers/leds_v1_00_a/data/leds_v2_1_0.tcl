##############################################################################
## Filename:          U:\hlocal\git\SE\extraordinaria\proyecto/drivers/leds_v1_00_a/data/leds_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Mon Jun 10 16:38:40 2024 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "leds" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
