cmd_tools/mkimage := cc  -o tools/mkimage tools/aisimage.o tools/atmelimage.o tools/common/bootm.o tools/lib/crc32.o tools/default_image.o tools/lib/fdtdec_common.o tools/lib/fdtdec.o tools/fit_common.o tools/fit_image.o tools/common/image-fit.o tools/image-host.o tools/common/image.o tools/imagetool.o tools/imximage.o tools/kwbimage.o tools/lib/md5.o tools/lpc32xximage.o tools/mxsimage.o tools/omapimage.o tools/os_support.o tools/pblimage.o tools/pbl_crc32.o tools/vybridimage.o tools/lib/rc4.o tools/rkcommon.o tools/rkimage.o tools/rksd.o tools/rkspi.o tools/socfpgaimage.o tools/lib/sha1.o tools/lib/sha256.o tools/common/hash.o tools/ublimage.o tools/zynqimage.o tools/zynqmpimage.o tools/lib/libfdt/fdt.o tools/lib/libfdt/fdt_ro.o tools/lib/libfdt/fdt_rw.o tools/lib/libfdt/fdt_strerror.o tools/lib/libfdt/fdt_wip.o tools/lib/libfdt/fdt_region.o tools/lib/libfdt/fdt_sw.o tools/gpimage.o tools/gpimage-common.o tools/mkimage.o  
