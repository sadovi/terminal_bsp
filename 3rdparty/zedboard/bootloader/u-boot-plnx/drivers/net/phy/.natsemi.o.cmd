cmd_drivers/net/phy/natsemi.o := /home/yaniv/share/hiSkyDev_04.08.20/3rdparty/zedboard/toolchain/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc -Wp,-MD,drivers/net/phy/.natsemi.o.d  -nostdinc -isystem /home/yaniv/share/hiSkyDev_04.08.20/3rdparty/zedboard/toolchain/gcc-arm-linux-gnueabi/bin/../lib/gcc/arm-linux-gnueabihf/6.2.1/include -Iinclude   -I./arch/arm/include -include ./include/linux/kconfig.h -D__KERNEL__ -D__UBOOT__ -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral -Werror=date-time -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -fno-pic -mno-unaligned-access -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe -march=armv7-a -D__LINUX_ARM_ARCH__=7 -I./arch/arm/mach-zynq/include    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(natsemi)"  -D"KBUILD_MODNAME=KBUILD_STR(natsemi)" -c -o drivers/net/phy/natsemi.o drivers/net/phy/natsemi.c

source_drivers/net/phy/natsemi.o := drivers/net/phy/natsemi.c

deps_drivers/net/phy/natsemi.o := \
  include/phy.h \
    $(wildcard include/config/dm/eth.h) \
    $(wildcard include/config/phylib/10g.h) \
  include/linux/list.h \
  include/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/use/stdint.h) \
  include/linux/posix_types.h \
  arch/arm/include/asm/posix_types.h \
  arch/arm/include/asm/types.h \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/phys/64bit.h) \
    $(wildcard include/config/dma/addr/t/64bit.h) \
  /home/yaniv/share/hiSkyDev_04.08.20/3rdparty/zedboard/toolchain/gcc-arm-linux-gnueabi/lib/gcc/arm-linux-gnueabihf/6.2.1/include/stdbool.h \
  include/linux/poison.h \
  include/linux/mii.h \
  include/linux/ethtool.h \
  include/linux/mdio.h \

drivers/net/phy/natsemi.o: $(deps_drivers/net/phy/natsemi.o)

$(deps_drivers/net/phy/natsemi.o):
