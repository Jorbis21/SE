################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/my_plb_peripheral.c \
../src/my_plb_peripheral_selftest.c \
../src/pr3.c \
../src/xbram_example.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/my_plb_peripheral.o \
./src/my_plb_peripheral_selftest.o \
./src/pr3.o \
./src/xbram_example.o 

C_DEPS += \
./src/my_plb_peripheral.d \
./src/my_plb_peripheral_selftest.d \
./src/pr3.d \
./src/xbram_example.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -Wl,--no-relax -I../../peripheral_tests_bsp_0/microblaze_0/include -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '

