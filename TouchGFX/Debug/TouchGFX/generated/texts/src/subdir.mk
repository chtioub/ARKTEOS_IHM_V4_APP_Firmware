################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/texts/src/LanguageDe.cpp \
../TouchGFX/generated/texts/src/LanguageFr.cpp \
../TouchGFX/generated/texts/src/LanguageGb.cpp \
../TouchGFX/generated/texts/src/LanguageNl.cpp \
../TouchGFX/generated/texts/src/LanguagePt.cpp \
../TouchGFX/generated/texts/src/Texts.cpp \
../TouchGFX/generated/texts/src/TypedTextDatabase.cpp 

OBJS += \
./TouchGFX/generated/texts/src/LanguageDe.o \
./TouchGFX/generated/texts/src/LanguageFr.o \
./TouchGFX/generated/texts/src/LanguageGb.o \
./TouchGFX/generated/texts/src/LanguageNl.o \
./TouchGFX/generated/texts/src/LanguagePt.o \
./TouchGFX/generated/texts/src/Texts.o \
./TouchGFX/generated/texts/src/TypedTextDatabase.o 

CPP_DEPS += \
./TouchGFX/generated/texts/src/LanguageDe.d \
./TouchGFX/generated/texts/src/LanguageFr.d \
./TouchGFX/generated/texts/src/LanguageGb.d \
./TouchGFX/generated/texts/src/LanguageNl.d \
./TouchGFX/generated/texts/src/LanguagePt.d \
./TouchGFX/generated/texts/src/Texts.d \
./TouchGFX/generated/texts/src/TypedTextDatabase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/texts/src/%.o TouchGFX/generated/texts/src/%.su TouchGFX/generated/texts/src/%.cyclo: ../TouchGFX/generated/texts/src/%.cpp TouchGFX/generated/texts/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/s.ernaut/Mes_Docs_SER/_Softs/Boot_Softs_cartes.git/ARKTEOS_IHM_V4_APP_Firmware/App/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-texts-2f-src

clean-TouchGFX-2f-generated-2f-texts-2f-src:
	-$(RM) ./TouchGFX/generated/texts/src/LanguageDe.cyclo ./TouchGFX/generated/texts/src/LanguageDe.d ./TouchGFX/generated/texts/src/LanguageDe.o ./TouchGFX/generated/texts/src/LanguageDe.su ./TouchGFX/generated/texts/src/LanguageFr.cyclo ./TouchGFX/generated/texts/src/LanguageFr.d ./TouchGFX/generated/texts/src/LanguageFr.o ./TouchGFX/generated/texts/src/LanguageFr.su ./TouchGFX/generated/texts/src/LanguageGb.cyclo ./TouchGFX/generated/texts/src/LanguageGb.d ./TouchGFX/generated/texts/src/LanguageGb.o ./TouchGFX/generated/texts/src/LanguageGb.su ./TouchGFX/generated/texts/src/LanguageNl.cyclo ./TouchGFX/generated/texts/src/LanguageNl.d ./TouchGFX/generated/texts/src/LanguageNl.o ./TouchGFX/generated/texts/src/LanguageNl.su ./TouchGFX/generated/texts/src/LanguagePt.cyclo ./TouchGFX/generated/texts/src/LanguagePt.d ./TouchGFX/generated/texts/src/LanguagePt.o ./TouchGFX/generated/texts/src/LanguagePt.su ./TouchGFX/generated/texts/src/Texts.cyclo ./TouchGFX/generated/texts/src/Texts.d ./TouchGFX/generated/texts/src/Texts.o ./TouchGFX/generated/texts/src/Texts.su ./TouchGFX/generated/texts/src/TypedTextDatabase.cyclo ./TouchGFX/generated/texts/src/TypedTextDatabase.d ./TouchGFX/generated/texts/src/TypedTextDatabase.o ./TouchGFX/generated/texts/src/TypedTextDatabase.su

.PHONY: clean-TouchGFX-2f-generated-2f-texts-2f-src

