################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/buzzer.c \
../src/keypad.c \
../src/lcd.c \
../src/leds.c \
../src/motor.c \
../src/tragaperras.c \
../src/xbram_example.c \
../src/xgpio_tapp_example.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/buzzer.o \
./src/keypad.o \
./src/lcd.o \
./src/leds.o \
./src/motor.o \
./src/tragaperras.o \
./src/xbram_example.o \
./src/xgpio_tapp_example.o 

C_DEPS += \
./src/buzzer.d \
./src/keypad.d \
./src/lcd.d \
./src/leds.d \
./src/motor.d \
./src/tragaperras.d \
./src/xbram_example.d \
./src/xgpio_tapp_example.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -Wl,--no-relax -I../../peripheral_tests_bsp_0/microblaze_0/include -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


