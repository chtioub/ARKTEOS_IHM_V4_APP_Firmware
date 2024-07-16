################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/containers/Barre_titre.cpp \
../TouchGFX/gui/src/containers/Bouton_on_off_toggle.cpp \
../TouchGFX/gui/src/containers/Erreurs_alertes.cpp \
../TouchGFX/gui/src/containers/PaveNumerique.cpp \
../TouchGFX/gui/src/containers/SwipeDetectContainer.cpp 

OBJS += \
./TouchGFX/gui/src/containers/Barre_titre.o \
./TouchGFX/gui/src/containers/Bouton_on_off_toggle.o \
./TouchGFX/gui/src/containers/Erreurs_alertes.o \
./TouchGFX/gui/src/containers/PaveNumerique.o \
./TouchGFX/gui/src/containers/SwipeDetectContainer.o 

CPP_DEPS += \
./TouchGFX/gui/src/containers/Barre_titre.d \
./TouchGFX/gui/src/containers/Bouton_on_off_toggle.d \
./TouchGFX/gui/src/containers/Erreurs_alertes.d \
./TouchGFX/gui/src/containers/PaveNumerique.d \
./TouchGFX/gui/src/containers/SwipeDetectContainer.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/containers/%.o TouchGFX/gui/src/containers/%.su TouchGFX/gui/src/containers/%.cyclo: ../TouchGFX/gui/src/containers/%.cpp TouchGFX/gui/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-containers

clean-TouchGFX-2f-gui-2f-src-2f-containers:
	-$(RM) ./TouchGFX/gui/src/containers/Barre_titre.cyclo ./TouchGFX/gui/src/containers/Barre_titre.d ./TouchGFX/gui/src/containers/Barre_titre.o ./TouchGFX/gui/src/containers/Barre_titre.su ./TouchGFX/gui/src/containers/Bouton_on_off_toggle.cyclo ./TouchGFX/gui/src/containers/Bouton_on_off_toggle.d ./TouchGFX/gui/src/containers/Bouton_on_off_toggle.o ./TouchGFX/gui/src/containers/Bouton_on_off_toggle.su ./TouchGFX/gui/src/containers/Erreurs_alertes.cyclo ./TouchGFX/gui/src/containers/Erreurs_alertes.d ./TouchGFX/gui/src/containers/Erreurs_alertes.o ./TouchGFX/gui/src/containers/Erreurs_alertes.su ./TouchGFX/gui/src/containers/PaveNumerique.cyclo ./TouchGFX/gui/src/containers/PaveNumerique.d ./TouchGFX/gui/src/containers/PaveNumerique.o ./TouchGFX/gui/src/containers/PaveNumerique.su ./TouchGFX/gui/src/containers/SwipeDetectContainer.cyclo ./TouchGFX/gui/src/containers/SwipeDetectContainer.d ./TouchGFX/gui/src/containers/SwipeDetectContainer.o ./TouchGFX/gui/src/containers/SwipeDetectContainer.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-containers

