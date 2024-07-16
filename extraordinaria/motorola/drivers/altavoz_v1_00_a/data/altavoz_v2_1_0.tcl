##############################################################################
## Filename:          C:\SE\motorola/drivers/altavoz_v1_00_a/data/altavoz_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Wed Jun 26 12:26:38 2024 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "altavoz" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
