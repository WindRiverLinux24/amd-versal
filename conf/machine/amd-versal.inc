#@TYPE: Machine inc.
#@NAME: versal layer

DEFAULTTUNE = "cortexa72"
require conf/machine/include/arm/armv8a/tune-cortexa72.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

BSP_XILINX_DERIVED:append = " amd-versal"

KERNEL_IMAGETYPE = "Image"
XILINX_DTB_FILES = " versal-vck190-rev1.1.dtb versal-vck190-rev1.1-x-ebm-01-revA.dtb \
						versal-vmk180-rev1.1.dtb versal-vmk180-rev1.1-x-ebm-01-revA.dtb"

KERNEL_DEVICETREE = "${@''.join('xilinx/%s ' % d for d in '${XILINX_DTB_FILES}'.split())}"

SERIAL_CONSOLE = "115200 ttyPS0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "6.6%"
PREFERRED_VERSION_linux-yocto-rt ?= "6.6%"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"

# variables needed by xilinx-bootbin
MACHINEOVERRIDES:prepend = "versal:"
SOC_FAMILY ?= "versal"
UBOOT_MACHINE ?= "xilinx_versal_virt_defconfig"
UBOOT_ELF = "u-boot.elf"

# wic support
WKS_FILE ?= "versal-sdimage.wks"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " Image ${XILINX_DTB_FILES} "

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE:virtclass-multilib-lib32 ?= "armv7athf-neon"
