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
proyecto_final.elf.size \

ELFCHECK += \
proyecto_final.elf.elfcheck \


# All Target
all: proyecto_final.elf secondary-outputs

# Tool invocations
proyecto_final.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: MicroBlaze gcc linker
	mb-gcc -Wl,--no-relax -Wl,-T -Wl,../src/lscript.ld -L../../peripheral_tests_bsp_0/microblaze_0/lib -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -o"proyecto_final.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

proyecto_final.elf.size: proyecto_final.elf
	@echo Invoking: MicroBlaze Print Size
	mb-size proyecto_final.elf  |tee "proyecto_final.elf.size"
	@echo Finished building: $@
	@echo ' '

proyecto_final.elf.elfcheck: proyecto_final.elf
	@echo Invoking: Xilinx ELF Check
	elfcheck proyecto_final.elf -hw ../../proyecto_hw_platform/system.xml -pe microblaze_0  |tee "proyecto_final.elf.elfcheck"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) proyecto_final.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
