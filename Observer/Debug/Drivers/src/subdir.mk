################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/Observer.c \
../Drivers/src/ObserverClient1.c \
../Drivers/src/ObserverClient2.c \
../Drivers/src/PollDataClient.c \
../Drivers/src/PollerTimer.c \
../Drivers/src/device.c \
../Drivers/src/poller.c 

OBJS += \
./Drivers/src/Observer.o \
./Drivers/src/ObserverClient1.o \
./Drivers/src/ObserverClient2.o \
./Drivers/src/PollDataClient.o \
./Drivers/src/PollerTimer.o \
./Drivers/src/device.o \
./Drivers/src/poller.o 

C_DEPS += \
./Drivers/src/Observer.d \
./Drivers/src/ObserverClient1.d \
./Drivers/src/ObserverClient2.d \
./Drivers/src/PollDataClient.d \
./Drivers/src/PollerTimer.d \
./Drivers/src/device.d \
./Drivers/src/poller.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o Drivers/src/%.su: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/inc" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/CMSIS/device" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/CMSIS/core" -I"C:/Users/Heba Elbeshbeshy/Downloads/SMBE 4th/Embedded/Tasks/Observer/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-src

clean-Drivers-2f-src:
	-$(RM) ./Drivers/src/Observer.d ./Drivers/src/Observer.o ./Drivers/src/Observer.su ./Drivers/src/ObserverClient1.d ./Drivers/src/ObserverClient1.o ./Drivers/src/ObserverClient1.su ./Drivers/src/ObserverClient2.d ./Drivers/src/ObserverClient2.o ./Drivers/src/ObserverClient2.su ./Drivers/src/PollDataClient.d ./Drivers/src/PollDataClient.o ./Drivers/src/PollDataClient.su ./Drivers/src/PollerTimer.d ./Drivers/src/PollerTimer.o ./Drivers/src/PollerTimer.su ./Drivers/src/device.d ./Drivers/src/device.o ./Drivers/src/device.su ./Drivers/src/poller.d ./Drivers/src/poller.o ./Drivers/src/poller.su

.PHONY: clean-Drivers-2f-src

