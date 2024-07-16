##############################################################################
## Filename:          C:\SE\motorola/drivers/motor_hw_v1_00_a/data/motor_hw_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Tue Jun 25 23:35:05 2024 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "motor_hw" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
