##############################################################################
## Filename:          C:\SE\motorola/drivers/lcd_v1_00_a/data/lcd_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Wed Jun 26 11:42:56 2024 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "lcd" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
