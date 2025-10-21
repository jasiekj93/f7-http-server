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
$(cube_dir)/Middlewares/Third_Party/FatFs/src/option/ccsbcs.c \
$(cube_dir)/Core/Src/sysmem.c \
$(cube_dir)/Core/Src/syscalls.c \
$(cube_dir)/USB_DEVICE/App/usb_device.c \
$(cube_dir)/USB_DEVICE/App/usbd_desc.c \
$(cube_dir)/USB_DEVICE/App/usbd_cdc_if.c \
$(cube_dir)/USB_DEVICE/Target/usbd_conf.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd_ex.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c \
$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c \
$(cube_dir)/LWIP/App/lwip.c \
$(cube_dir)/LWIP/Target/ethernetif.c \
$(cube_dir)/Drivers/BSP/Components/lan8742/lan8742.c \
$(cube_dir)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_eth.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/auth.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/ccp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/chap_ms.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/chap-md5.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/chap-new.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/demand.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/eap.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/eui64.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/fsm.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/ipcp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/ipv6cp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/lcp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/magic.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/mppe.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/multilink.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/ppp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/pppapi.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/pppcrypt.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/pppoe.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/pppol2tp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/pppos.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/upap.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/utils.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/vj.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/bridgeif.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/bridgeif_fdb.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ethernet.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/lowpan6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/lowpan6_ble.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/lowpan6_common.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/slipif.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/zepif.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/netif/ppp/ecp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/apps/http/httpd.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/apps/http/fs.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/netifapi.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/api_lib.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/netbuf.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/api_msg.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/sockets.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/tcpip.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/err.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/if_api.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/api/netdb.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/init.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/netif.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/pbuf.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/altcp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/mem.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/altcp_tcp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/sys.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/tcp_in.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/raw.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ip.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/udp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/stats.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/timeouts.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/tcp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/inet_chksum.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/memp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/def.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/altcp_alloc.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/tcp_out.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/dns.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/ethip6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_frag.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/icmp6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/inet6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/nd6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/mld6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_addr.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/ip6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/core/ipv6/dhcp6.c \
$(cube_dir)/Middlewares/Third_Party/LwIP/src/apps/mqtt/mqtt.c

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
-I$(cube_dir)/Drivers/CMSIS/Include \
-I$(cube_dir)/USB_DEVICE/App \
-I$(cube_dir)/USB_DEVICE/Target \
-I$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Core/Inc \
-I$(cube_dir)/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc \
-I$(cube_dir)/LWIP/App \
-I$(cube_dir)/LWIP/Target \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/system \
-I$(cube_dir)/Drivers/BSP/Components/lan8742 \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/netif/ppp \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/apps/http \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/lwip \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/lwip/apps \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/lwip/priv \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/lwip/prot \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/netif \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/compat/posix \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/compat/posix/net \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/compat/posix/sys \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/src/include/compat/stdc \
-I$(cube_dir)/Middlewares/Third_Party/LwIP/system/arch

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