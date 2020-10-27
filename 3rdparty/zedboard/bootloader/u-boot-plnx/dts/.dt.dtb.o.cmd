cmd_dts/dt.dtb.o := /home/yaniv/share/hiSkyDev_04.08.20/3rdparty/zedboard/toolchain/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc -Wp,-MD,dts/.dt.dtb.o.d  -nostdinc -isystem /home/yaniv/share/hiSkyDev_04.08.20/3rdparty/zedboard/toolchain/gcc-arm-linux-gnueabi/bin/../lib/gcc/arm-linux-gnueabihf/6.2.1/include -Iinclude   -I./arch/arm/include -include ./include/linux/kconfig.h -D__KERNEL__ -D__UBOOT__ -D__ASSEMBLY__ -g -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -fno-pic -mno-unaligned-access -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe -march=armv7-a -D__LINUX_ARM_ARCH__=7 -I./arch/arm/mach-zynq/include   -c -o dts/dt.dtb.o dts/dt.dtb.S

source_dts/dt.dtb.o := dts/dt.dtb.S

deps_dts/dt.dtb.o := \

dts/dt.dtb.o: $(deps_dts/dt.dtb.o)

$(deps_dts/dt.dtb.o):
