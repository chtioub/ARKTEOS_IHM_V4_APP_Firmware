################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/configuration_screen/%.o TouchGFX/generated/gui_generated/src/configuration_screen/%.su TouchGFX/generated/gui_generated/src/configuration_screen/%.cyclo: ../TouchGFX/generated/gui_generated/src/configuration_screen/%.cpp TouchGFX/generated/gui_generated/src/configuration_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/s.ernaut/Mes_Docs_SER/_Softs/Boot_Softs_cartes.git/ARKTEOS_IHM_V4_APP_Firmware/App/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-configuration_screen

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-configuration_screen:
	-$(RM) ./TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.cyclo ./TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.d ./TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.o ./TouchGFX/generated/gui_generated/src/configuration_screen/ConfigurationViewBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-configuration_screen

