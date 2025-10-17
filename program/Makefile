# ------------------------------------------------
# @author Adrian Szczepanski
# @date 06-03-2023
# ------------------------------------------------

# Platform
# Uncomment if program platform must be diffrent than the solution
# PLATFORM := Pc32
# Uncomment if program support only specific platforms and otherwise must be skipped
# supported_platforms := Pc32 Pc64 ArmA7-Linux ArmA9-Linux Rpi64

# Target
target := program

# Directories
project_dir ?= ..
make_dir := $(project_dir)/make
external_dir := $(project_dir)/external
cube_dir := $(project_dir)/cube

# Sources 
cxx_sources :=  \
$(wildcard *.cpp) \

c_sources := \
$(cube_dir)/Core/Src/gpio.c \
$(cube_dir)/Core/Src/sdmmc.c \
$(cube_dir)/Core/Src/stm32f7xx_it.c \
$(cube_dir)/Core/Src/stm32f7xx_hal_msp.c \
$(cube_dir)/FATFS/App/fatfs.c \
$(cube_dir)/FATFS/Target/bsp_driver_sd.c \
$(cube_dir)/FATFS/Target/sd_diskio.c \
$(cube_dir)/FATFS/Target/fatfs_platform.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mmc.c \
$(cube_dir)/Core/Src/system_stm32f7xx.c \
$(cube_dir)/Middlewares/Third_Party/FatFs/src/diskio.c \
$(cube_dir)/Middlewares/Third_Party/FatFs/src/ff.c \
$(cube_dir)/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
$(cube_dir)/Middlewares/Third_Party/FatFs/src/option/syscall.c \
$(cube_dir)/Core/Src/sysmem.c \
$(cube_dir)/Core/Src/syscalls.c  

asm_sources := \
$(cube_dir)/startup_stm32f746xx.s

# Includes
cxx_includes := \
-I. \
-I$(cube_dir)/FATFS/Target \
-I$(cube_dir)/FATFS/App \
-I$(cube_dir)/Core/Inc \
-I$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Inc \
-I$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy \
-I$(cube_dir)/Middlewares/Third_Party/FatFs/src \
-I$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Core/Inc \
-I$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc \
-I$(cube_dir)/Drivers/CMSIS/Device/ST/STM32F7xx/Include \
-I$(cube_dir)/Drivers/CMSIS/Include

# Defines
cxx_defs := \
-DUSE_HAL_DRIVER \
-DSTM32F746xx

# Additional objects
# additional_objects := \

# internal libraries
required_internal_libraries = \

# libraries
required_libraries = \

# external libraries
#	e.g. if include flag is '-I$(external_dir)/libFoo'
#	write 'libFoo'
external_library_include_path = \

external_library_flags = \

#	e.g. if link flag is '-L$(external_dir)/libFoo/lib'
#	write 'libFoo/lib'
external_library_paths = \

# Linker script
ldscript = $(cube_dir)/stm32f746nghx_flash.ld

# Uncomment if gcc should be used for compilation *.c files
use_gcc_for_c_files := 1

# Uncomment if you want to add custom flags for gcc or g++
# custom_c_flags :=
# custom_cxx_flags :=

# Uncomment if you want to add library flags and the end of the linking command (e.g. -pthread)
# terminating_libs := 

# Append rest of Makefile from template
include $(make_dir)/Program.mk