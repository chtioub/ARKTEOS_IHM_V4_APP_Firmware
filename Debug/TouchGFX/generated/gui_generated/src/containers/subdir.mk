################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.o \
./TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.o \
./TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.o \
./TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.o \
./TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.d \
./TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.d \
./TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.d \
./TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.d \
./TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/containers/%.o TouchGFX/generated/gui_generated/src/containers/%.su TouchGFX/generated/gui_generated/src/containers/%.cyclo: ../TouchGFX/generated/gui_generated/src/containers/%.cpp TouchGFX/generated/gui_generated/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers:
	-$(RM) ./TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.d ./TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.o ./TouchGFX/generated/gui_generated/src/containers/Barre_titreBase.su ./TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.d ./TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.o ./TouchGFX/generated/gui_generated/src/containers/Bouton_on_off_toggleBase.su ./TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.d ./TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.o ./TouchGFX/generated/gui_generated/src/containers/Erreurs_alertesBase.su ./TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.d ./TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.o ./TouchGFX/generated/gui_generated/src/containers/PaveNumeriqueBase.su ./TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.d ./TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.o ./TouchGFX/generated/gui_generated/src/containers/SwipeDetectContainerBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

