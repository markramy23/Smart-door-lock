################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HMI_ECU_main.c \
../gpio.c \
../my_keypad.c \
../my_lcd.c \
../timer1.c \
../uart.c 

OBJS += \
./HMI_ECU_main.o \
./gpio.o \
./my_keypad.o \
./my_lcd.o \
./timer1.o \
./uart.o 

C_DEPS += \
./HMI_ECU_main.d \
./gpio.d \
./my_keypad.d \
./my_lcd.d \
./timer1.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


