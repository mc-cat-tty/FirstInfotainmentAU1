################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/nuc/Desktop/FirstInfotainmentAU1/Drivers/BSP/Components/ft6x06/ft6x06.c \
C:/Users/nuc/Desktop/FirstInfotainmentAU1/Drivers/BSP/Components/nt35510/nt35510.c 

C_DEPS += \
./Drivers/BSP/Components/ft6x06.d \
./Drivers/BSP/Components/nt35510.d 

OBJS += \
./Drivers/BSP/Components/ft6x06.o \
./Drivers/BSP/Components/nt35510.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ft6x06.o: C:/Users/nuc/Desktop/FirstInfotainmentAU1/Drivers/BSP/Components/ft6x06/ft6x06.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DSTM32F469xx -DDEBUG -c -I../../Core/Inc -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/Shared/inc" -I../../Drivers/CMSIS/Include -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Drivers/BSP/Components/Common -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/STM32469I-Discovery -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/core/net/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/gpio/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/util/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/timing/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/spi/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/mcp2515/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/can/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/buffer" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/filter/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/gpio/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/stm/inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/nt35510.o: C:/Users/nuc/Desktop/FirstInfotainmentAU1/Drivers/BSP/Components/nt35510/nt35510.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DSTM32F469xx -DDEBUG -c -I../../Core/Inc -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/Shared/inc" -I../../Drivers/CMSIS/Include -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Drivers/BSP/Components/Common -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/STM32469I-Discovery -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/core/net/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/gpio/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/util/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/timing/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/spi/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/mcp2515/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/can/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/buffer" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/filter/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/lib/gpio/inc" -I"C:/Users/nuc/Desktop/FirstInfotainmentAU1/mmr_core/app/stm/inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/ft6x06.cyclo ./Drivers/BSP/Components/ft6x06.d ./Drivers/BSP/Components/ft6x06.o ./Drivers/BSP/Components/ft6x06.su ./Drivers/BSP/Components/nt35510.cyclo ./Drivers/BSP/Components/nt35510.d ./Drivers/BSP/Components/nt35510.o ./Drivers/BSP/Components/nt35510.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

