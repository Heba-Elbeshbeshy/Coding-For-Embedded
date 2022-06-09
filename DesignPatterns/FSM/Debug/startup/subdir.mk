################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 

S_DEPS += \
./startup/startup_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks_mo3ed/Labs/Lab_5_FSM/inc" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks_mo3ed/Labs/Lab_5_FSM/CMSIS/device" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks_mo3ed/Labs/Lab_5_FSM/CMSIS/core" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks_mo3ed/Labs/Lab_5_FSM/Drivers/inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_stm32.d ./startup/startup_stm32.o

.PHONY: clean-startup

