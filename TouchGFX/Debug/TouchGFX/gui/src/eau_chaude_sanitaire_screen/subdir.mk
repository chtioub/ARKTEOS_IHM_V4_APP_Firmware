################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.cpp \
../TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.cpp 

OBJS += \
./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.o \
./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.o 

CPP_DEPS += \
./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.d \
./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/eau_chaude_sanitaire_screen/%.o TouchGFX/gui/src/eau_chaude_sanitaire_screen/%.su TouchGFX/gui/src/eau_chaude_sanitaire_screen/%.cyclo: ../TouchGFX/gui/src/eau_chaude_sanitaire_screen/%.cpp TouchGFX/gui/src/eau_chaude_sanitaire_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/s.ernaut/Mes_Docs_SER/_Softs/Boot_Softs_cartes.git/ARKTEOS_IHM_V4_APP_Firmware/App/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-eau_chaude_sanitaire_screen

clean-TouchGFX-2f-gui-2f-src-2f-eau_chaude_sanitaire_screen:
	-$(RM) ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.cyclo ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.d ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.o ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.su ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.cyclo ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.d ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.o ./TouchGFX/gui/src/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-eau_chaude_sanitaire_screen

