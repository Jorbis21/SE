################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
ProyectoFinal.elf.size \

ELFCHECK += \
ProyectoFinal.elf.elfcheck \


# All Target
all: ProyectoFinal.elf secondary-outputs

# Tool invocations
ProyectoFinal.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: MicroBlaze gcc linker
	mb-gcc -Wl,--no-relax -Wl,-T -Wl,../src/lscript.ld -L../../peripheral_tests_bsp_0/microblaze_0/lib -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -o"ProyectoFinal.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

ProyectoFinal.elf.size: ProyectoFinal.elf
	@echo Invoking: MicroBlaze Print Size
	mb-size ProyectoFinal.elf  |tee "ProyectoFinal.elf.size"
	@echo Finished building: $@
	@echo ' '

ProyectoFinal.elf.elfcheck: ProyectoFinal.elf
	@echo Invoking: Xilinx ELF Check
	elfcheck ProyectoFinal.elf -hw ../../proyecto_hw_platform/system.xml -pe microblaze_0  |tee "ProyectoFinal.elf.elfcheck"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) ProyectoFinal.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
