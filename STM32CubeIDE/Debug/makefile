################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include timing/subdir.mk
-include stm/subdir.mk
-include spi/subdir.mk
-include net/subdir.mk
-include mcp2515/subdir.mk
-include gpio/subdir.mk
-include can/subdir.mk
-include buffer/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/STM32469I-Discovery/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Application/User/gui/subdir.mk
-include Application/User/generated/subdir.mk
-include Application/User/TouchGFX/target/generated/subdir.mk
-include Application/User/TouchGFX/target/subdir.mk
-include Application/User/TouchGFX/App/subdir.mk
-include Application/User/subdir.mk
-include Application/Startup/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32F469I-DISCO-REV-AU1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F469I-DISCO-REV-AU1.elf \

MAP_FILES += \
STM32F469I-DISCO-REV-AU1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F469I-DISCO-REV-AU1.list \

OBJCOPY_HEX += \
STM32F469I-DISCO-REV-AU1.hex \


# All Target
all: main-build

# Main-build Target
main-build: STM32F469I-DISCO-REV-AU1.elf secondary-outputs

# Tool invocations
STM32F469I-DISCO-REV-AU1.elf STM32F469I-DISCO-REV-AU1.map: $(OBJS) $(USER_OBJS) C:\Users\nuc\Desktop\FirstInfotainmentAU1\STM32CubeIDE\STM32F469NIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "STM32F469I-DISCO-REV-AU1.elf" @"objects.list" $(USER_OBJS) -Wl,--start-group $(LIBS) -Wl,--end-group -mcpu=cortex-m4 -T"C:\Users\nuc\Desktop\FirstInfotainmentAU1\STM32CubeIDE\STM32F469NIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F469I-DISCO-REV-AU1.map" -Wl,--gc-sections -static -LC:/git/STM32F469-dk/stm32f469i_disco/STM32F469I-DISCO-REV-AU1/Middlewares/ST/touchgfx/lib/core/cortex_m4f/gcc -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\Middlewares\ST\touchgfx\lib\core\cortex_m4f\gcc" -LC:/git/stm32f469i_disco/STM32F469I-DISCO-REV-AU1/Middlewares/ST/touchgfx/lib/core/cortex_m4f/gcc -LC:/Users/Francesco/Downloads/FirstInfotainmentAU1/FirstInfotainmentAU1/Middlewares/ST/touchgfx/lib/core/cortex_m4f/gcc -LC:/Users/nuc/Desktop/FirstInfotainmentAU1/Middlewares/ST/touchgfx/lib/core/cortex_m4f/gcc -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\buffer" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\can" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\filter" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\gpio" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\mcp2515" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\pid" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\spi" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\timing" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\lib\util" -L"C:\Users\nuc\Desktop\FirstInfotainmentAU1\mmr_core\app\stm" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F469I-DISCO-REV-AU1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F469I-DISCO-REV-AU1.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F469I-DISCO-REV-AU1.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32F469I-DISCO-REV-AU1.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32F469I-DISCO-REV-AU1.elf STM32F469I-DISCO-REV-AU1.hex STM32F469I-DISCO-REV-AU1.list STM32F469I-DISCO-REV-AU1.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
