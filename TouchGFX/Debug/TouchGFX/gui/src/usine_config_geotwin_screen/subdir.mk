################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.cpp \
../TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.cpp 

OBJS += \
./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.o \
./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.o 

CPP_DEPS += \
./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.d \
./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/usine_config_geotwin_screen/%.o TouchGFX/gui/src/usine_config_geotwin_screen/%.su TouchGFX/gui/src/usine_config_geotwin_screen/%.cyclo: ../TouchGFX/gui/src/usine_config_geotwin_screen/%.cpp TouchGFX/gui/src/usine_config_geotwin_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/s.ernaut/Mes_Docs_SER/_Softs/Boot_Softs_cartes.git/ARKTEOS_IHM_V4_APP_Firmware/App/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-usine_config_geotwin_screen

clean-TouchGFX-2f-gui-2f-src-2f-usine_config_geotwin_screen:
	-$(RM) ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.cyclo ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.d ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.o ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinPresenter.su ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.cyclo ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.d ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.o ./TouchGFX/gui/src/usine_config_geotwin_screen/Usine_config_geotwinView.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-usine_config_geotwin_screen

