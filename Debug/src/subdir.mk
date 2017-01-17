################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CalculatingController.cpp \
../src/Calculator.cpp \
../src/ParsingController.cpp \
../src/PlotConfig.cpp \
../src/PlottingController.cpp \
../src/RowModel.cpp \
../src/RowParser.cpp \
../src/main.cpp 

OBJS += \
./src/CalculatingController.o \
./src/Calculator.o \
./src/ParsingController.o \
./src/PlotConfig.o \
./src/PlottingController.o \
./src/RowModel.o \
./src/RowParser.o \
./src/main.o 

CPP_DEPS += \
./src/CalculatingController.d \
./src/Calculator.d \
./src/ParsingController.d \
./src/PlotConfig.d \
./src/PlottingController.d \
./src/RowModel.d \
./src/RowParser.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


