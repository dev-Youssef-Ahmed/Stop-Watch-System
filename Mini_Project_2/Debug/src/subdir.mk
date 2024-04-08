################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/interrupts.c \
../src/main.c \
../src/seven_segment.c \
../src/timer1.c 

OBJS += \
./src/interrupts.o \
./src/main.o \
./src/seven_segment.o \
./src/timer1.o 

C_DEPS += \
./src/interrupts.d \
./src/main.d \
./src/seven_segment.d \
./src/timer1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Youssef\Desktop\Youssef_Ahmed_85_All_Mini_Projects\Mini_Project_2\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


