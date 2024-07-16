################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/keypad.c \
../src/keypad_selftest.c \
../src/lcd.c \
../src/lcd_selftest.c \
../src/leds.c \
../src/leds_selftest.c \
../src/main.c \
../src/xbram_example.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/keypad.o \
./src/keypad_selftest.o \
./src/lcd.o \
./src/lcd_selftest.o \
./src/leds.o \
./src/leds_selftest.o \
./src/main.o \
./src/xbram_example.o 

C_DEPS += \
./src/keypad.d \
./src/keypad_selftest.d \
./src/lcd.d \
./src/lcd_selftest.d \
./src/leds.d \
./src/leds_selftest.d \
./src/main.d \
./src/xbram_example.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -Wl,--no-relax -I../../peripheral_tests_bsp_0/microblaze_0/include -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


