################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/altavoz.c \
../src/altavoz_selftest.c \
../src/keypad.c \
../src/keypad_selftest.c \
../src/lcd.c \
../src/lcd_selftest.c \
../src/leds.c \
../src/leds_selftest.c \
../src/motor_hw.c \
../src/motor_hw_selftest.c \
../src/testperiph.c \
../src/xbram_example.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/altavoz.o \
./src/altavoz_selftest.o \
./src/keypad.o \
./src/keypad_selftest.o \
./src/lcd.o \
./src/lcd_selftest.o \
./src/leds.o \
./src/leds_selftest.o \
./src/motor_hw.o \
./src/motor_hw_selftest.o \
./src/testperiph.o \
./src/xbram_example.o 

C_DEPS += \
./src/altavoz.d \
./src/altavoz_selftest.d \
./src/keypad.d \
./src/keypad_selftest.d \
./src/lcd.d \
./src/lcd_selftest.d \
./src/leds.d \
./src/leds_selftest.d \
./src/motor_hw.d \
./src/motor_hw_selftest.d \
./src/testperiph.d \
./src/xbram_example.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -Wl,--no-relax -I../../peripheral_tests_bsp_0/microblaze_0/include -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


