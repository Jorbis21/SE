##############################################################################
## Filename:          C:\Users\marti\OneDrive\Documentos\4\proyectFinal\SE/drivers/altavoz_v1_00_a/data/altavoz_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Sat Dec 16 12:14:52 2023 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "altavoz" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
