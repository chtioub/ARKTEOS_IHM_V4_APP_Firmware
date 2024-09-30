################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.cpp 

OBJS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__generated/%.o TouchGFX/generated/images/src/__generated/%.su TouchGFX/generated/images/src/__generated/%.cyclo: ../TouchGFX/generated/images/src/__generated/%.cpp TouchGFX/generated/images/src/__generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/s.ernaut/Mes_Docs_SER/_Softs/Boot_Softs_cartes.git/ARKTEOS_IHM_V4_APP_Firmware/App/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated:
	-$(RM) ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_slider_horizontal_thick_round_dark.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_40_40_FFFFFF.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_backspace_40_40_FFFFFF.svg.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

