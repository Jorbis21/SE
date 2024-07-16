##############################################################################
## Filename:          U:\hlocal\PABLO\SE\labs\pr3/drivers/my_plb_peripheral_v1_00_a/data/my_plb_peripheral_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Thu Dec 14 11:35:54 2023 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "my_plb_peripheral" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
