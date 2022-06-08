################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/inc" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/CMSIS/device" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/CMSIS/core" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.d ./src/main.o ./src/main.su ./src/syscalls.d ./src/syscalls.o ./src/syscalls.su ./src/system_stm32f4xx.d ./src/system_stm32f4xx.o ./src/system_stm32f4xx.su

.PHONY: clean-src

