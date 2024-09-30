################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.cpp \
../TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.cpp 

OBJS += \
./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.o \
./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.o 

CPP_DEPS += \
./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.d \
./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/usine_param_avances_screen/%.o TouchGFX/gui/src/usine_param_avances_screen/%.su TouchGFX/gui/src/usine_param_avances_screen/%.cyclo: ../TouchGFX/gui/src/usine_param_avances_screen/%.cpp TouchGFX/gui/src/usine_param_avances_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/s.ernaut/Mes_Docs_SER/_Softs/Boot_Softs_cartes.git/ARKTEOS_IHM_V4_APP_Firmware/App/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-usine_param_avances_screen

clean-TouchGFX-2f-gui-2f-src-2f-usine_param_avances_screen:
	-$(RM) ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.cyclo ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.d ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.o ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesPresenter.su ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.cyclo ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.d ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.o ./TouchGFX/gui/src/usine_param_avances_screen/Usine_param_avancesView.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-usine_param_avances_screen

