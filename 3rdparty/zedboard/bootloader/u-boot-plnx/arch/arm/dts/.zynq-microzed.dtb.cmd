cmd_arch/arm/dts/zynq-microzed.dtb := mkdir -p arch/arm/dts/ ; cat arch/arm/dts/zynq-microzed.dts   | /home/build/tmp/hiSkyDev_04.08.20/3rdparty/zedboard/toolchain/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc -E -Wp,-MD,arch/arm/dts/.zynq-microzed.dtb.d.pre.tmp -nostdinc -I./arch/arm/dts -I./arch/arm/dts/include -Iinclude -I./include -I./arch/arm/include -include ./include/linux/kconfig.h -D__ASSEMBLY__ -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/dts/.zynq-microzed.dtb.dts.tmp - ; dtc -O dtb -o arch/arm/dts/zynq-microzed.dtb -b 0 -i arch/arm/dts/  -d arch/arm/dts/.zynq-microzed.dtb.d.dtc.tmp arch/arm/dts/.zynq-microzed.dtb.dts.tmp ; cat arch/arm/dts/.zynq-microzed.dtb.d.pre.tmp arch/arm/dts/.zynq-microzed.dtb.d.dtc.tmp > arch/arm/dts/.zynq-microzed.dtb.d

source_arch/arm/dts/zynq-microzed.dtb := arch/arm/dts/zynq-7000.dtsi

deps_arch/arm/dts/zynq-microzed.dtb := \

arch/arm/dts/zynq-microzed.dtb: $(deps_arch/arm/dts/zynq-microzed.dtb)

$(deps_arch/arm/dts/zynq-microzed.dtb):
