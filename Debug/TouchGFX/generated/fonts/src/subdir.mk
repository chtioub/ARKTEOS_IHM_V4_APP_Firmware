################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/fonts/src/ApplicationFontProvider.cpp \
../TouchGFX/generated/fonts/src/CachedFont.cpp \
../TouchGFX/generated/fonts/src/FontCache.cpp \
../TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.cpp \
../TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/GeneratedFont.cpp \
../TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.cpp \
../TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.cpp \
../TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.cpp \
../TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.cpp \
../TouchGFX/generated/fonts/src/UnmappedDataFont.cpp \
../TouchGFX/generated/fonts/src/VectorFontRendererBuffers.cpp 

OBJS += \
./TouchGFX/generated/fonts/src/ApplicationFontProvider.o \
./TouchGFX/generated/fonts/src/CachedFont.o \
./TouchGFX/generated/fonts/src/FontCache.o \
./TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.o \
./TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.o \
./TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.o \
./TouchGFX/generated/fonts/src/GeneratedFont.o \
./TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.o \
./TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.o \
./TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.o \
./TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.o \
./TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.o \
./TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.o \
./TouchGFX/generated/fonts/src/UnmappedDataFont.o \
./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.o 

CPP_DEPS += \
./TouchGFX/generated/fonts/src/ApplicationFontProvider.d \
./TouchGFX/generated/fonts/src/CachedFont.d \
./TouchGFX/generated/fonts/src/FontCache.d \
./TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.d \
./TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.d \
./TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.d \
./TouchGFX/generated/fonts/src/GeneratedFont.d \
./TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.d \
./TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.d \
./TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.d \
./TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.d \
./TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.d \
./TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.d \
./TouchGFX/generated/fonts/src/UnmappedDataFont.d \
./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/fonts/src/%.o TouchGFX/generated/fonts/src/%.su TouchGFX/generated/fonts/src/%.cyclo: ../TouchGFX/generated/fonts/src/%.cpp TouchGFX/generated/fonts/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-fonts-2f-src

clean-TouchGFX-2f-generated-2f-fonts-2f-src:
	-$(RM) ./TouchGFX/generated/fonts/src/ApplicationFontProvider.cyclo ./TouchGFX/generated/fonts/src/ApplicationFontProvider.d ./TouchGFX/generated/fonts/src/ApplicationFontProvider.o ./TouchGFX/generated/fonts/src/ApplicationFontProvider.su ./TouchGFX/generated/fonts/src/CachedFont.cyclo ./TouchGFX/generated/fonts/src/CachedFont.d ./TouchGFX/generated/fonts/src/CachedFont.o ./TouchGFX/generated/fonts/src/CachedFont.su ./TouchGFX/generated/fonts/src/FontCache.cyclo ./TouchGFX/generated/fonts/src/FontCache.d ./TouchGFX/generated/fonts/src/FontCache.o ./TouchGFX/generated/fonts/src/FontCache.su ./TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.cyclo ./TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_segoeui_20_4bpp_0.su ./TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.cyclo ./TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.d ./TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.o ./TouchGFX/generated/fonts/src/Font_segoeuib_19_8bpp_0.su ./TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.cyclo ./TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_segoeuib_30_4bpp_0.su ./TouchGFX/generated/fonts/src/GeneratedFont.cyclo ./TouchGFX/generated/fonts/src/GeneratedFont.d ./TouchGFX/generated/fonts/src/GeneratedFont.o ./TouchGFX/generated/fonts/src/GeneratedFont.su ./TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.cyclo ./TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_segoeui_20_4bpp.su ./TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.cyclo ./TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.d ./TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.o ./TouchGFX/generated/fonts/src/Kerning_segoeuib_19_8bpp.su ./TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.cyclo ./TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_segoeuib_30_4bpp.su ./TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.cyclo ./TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.d ./TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.o ./TouchGFX/generated/fonts/src/Table_segoeui_20_4bpp.su ./TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.cyclo ./TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.d ./TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.o ./TouchGFX/generated/fonts/src/Table_segoeuib_19_8bpp.su ./TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.cyclo ./TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.d ./TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.o ./TouchGFX/generated/fonts/src/Table_segoeuib_30_4bpp.su ./TouchGFX/generated/fonts/src/UnmappedDataFont.cyclo ./TouchGFX/generated/fonts/src/UnmappedDataFont.d ./TouchGFX/generated/fonts/src/UnmappedDataFont.o ./TouchGFX/generated/fonts/src/UnmappedDataFont.su ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.cyclo ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.d ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.o ./TouchGFX/generated/fonts/src/VectorFontRendererBuffers.su

.PHONY: clean-TouchGFX-2f-generated-2f-fonts-2f-src

