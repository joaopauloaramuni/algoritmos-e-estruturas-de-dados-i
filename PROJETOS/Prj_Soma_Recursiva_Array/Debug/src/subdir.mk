################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Prj_Soma_Recursiva_Array.c 

C_DEPS += \
./src/Prj_Soma_Recursiva_Array.d 

OBJS += \
./src/Prj_Soma_Recursiva_Array.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Prj_Soma_Recursiva_Array.d ./src/Prj_Soma_Recursiva_Array.o

.PHONY: clean-src

