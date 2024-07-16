/*****************************************************************************
* Filename:          U:\hlocal\git\SE\extraordinaria\proyecto/drivers/leds_v1_00_a/src/leds.h
* Version:           1.00.a
* Description:       leds Driver Header File
* Date:              Mon Jun 10 16:38:40 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/

#ifndef LEDS_H
#define LEDS_H

/***************************** Include Files *******************************/

#include "xbasic_types.h"
#include "xstatus.h"
#include "xil_io.h"

/************************** Constant Definitions ***************************/

#define ROJO_R 0
#define ROJO_G 255
#define ROJO_B 255

#define VERDE_R 255
#define VERDE_G 0
#define VERDE_B 255

#define AZUL_R 255
#define AZUL_G 255
#define AZUL_B 0

#define BLANCO_R 0
#define BLANCO_G 0
#define BLANCO_B 0

#define NEGRO_R 255
#define NEGRO_G 255
#define NEGRO_B 255

/**
 * User Logic Slave Space Offsets
 * -- SLV_REG0 : user logic slave module register 0
 * -- SLV_REG1 : user logic slave module register 1
 * -- SLV_REG2 : user logic slave module register 2
 */
#define LEDS_USER_SLV_SPACE_OFFSET (0x00000000)
#define LEDS_SLV_REG0_OFFSET (LEDS_USER_SLV_SPACE_OFFSET + 0x00000000)
#define LEDS_SLV_REG1_OFFSET (LEDS_USER_SLV_SPACE_OFFSET + 0x00000004)
#define LEDS_SLV_REG2_OFFSET (LEDS_USER_SLV_SPACE_OFFSET + 0x00000008)

/**************************** Type Definitions *****************************/


/***************** Macros (Inline Functions) Definitions *******************/

/**
 *
 * Write a value to a LEDS register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the LEDS device.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void LEDS_mWriteReg(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Data)
 *
 */
#define LEDS_mWriteReg(BaseAddress, RegOffset, Data) \
 	Xil_Out32((BaseAddress) + (RegOffset), (Xuint32)(Data))

/**
 *
 * Read a value from a LEDS register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the LEDS device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	Xuint32 LEDS_mReadReg(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define LEDS_mReadReg(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (RegOffset))


/**
 *
 * Write/Read 32 bit value to/from LEDS user logic slave registers.
 *
 * @param   BaseAddress is the base address of the LEDS device.
 * @param   RegOffset is the offset from the slave register to write to or read from.
 * @param   Value is the data written to the register.
 *
 * @return  Data is the data from the user logic slave register.
 *
 * @note
 * C-style signature:
 * 	void LEDS_mWriteSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Value)
 * 	Xuint32 LEDS_mReadSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define LEDS_mWriteSlaveReg0(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (LEDS_SLV_REG0_OFFSET) + (RegOffset), (Xuint32)(Value))
#define LEDS_mWriteSlaveReg1(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (LEDS_SLV_REG1_OFFSET) + (RegOffset), (Xuint32)(Value))
#define LEDS_mWriteSlaveReg2(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (LEDS_SLV_REG2_OFFSET) + (RegOffset), (Xuint32)(Value))

#define LEDS_mReadSlaveReg0(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (LEDS_SLV_REG0_OFFSET) + (RegOffset))
#define LEDS_mReadSlaveReg1(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (LEDS_SLV_REG1_OFFSET) + (RegOffset))
#define LEDS_mReadSlaveReg2(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (LEDS_SLV_REG2_OFFSET) + (RegOffset))

/************************** Function Prototypes ****************************/


/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the LEDS instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus LEDS_SelfTest(void * baseaddr_p);

void LED_init();
void ledsDEMO();
void LED_ponColor(int R, int G, int B);

#endif /** LEDS_H */
