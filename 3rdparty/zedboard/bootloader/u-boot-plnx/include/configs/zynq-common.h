/*
 * (C) Copyright 2012 Michal Simek <monstr@monstr.eu>
 * (C) Copyright 2013 Xilinx, Inc.
 *
 * Common configuration options for all Zynq boards.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ZYNQ_COMMON_H
#define __CONFIG_ZYNQ_COMMON_H

#error "Included!"
/* CPU clock */
#ifndef CONFIG_CPU_FREQ_HZ
# define CONFIG_CPU_FREQ_HZ	800000000
#endif

/* Cache options */
#define CONFIG_SYS_L2CACHE_OFF
#ifndef CONFIG_SYS_L2CACHE_OFF
# define CONFIG_SYS_L2_PL310
# define CONFIG_SYS_PL310_BASE		0xf8f02000
#endif

#define ZYNQ_SCUTIMER_BASEADDR		0xF8F00600
#define CONFIG_SYS_TIMERBASE		ZYNQ_SCUTIMER_BASEADDR
#define CONFIG_SYS_TIMER_COUNTS_DOWN
#define CONFIG_SYS_TIMER_COUNTER	(CONFIG_SYS_TIMERBASE + 0x4)

/* Serial drivers */
#define CONFIG_BAUDRATE		115200
/* The following table includes the supported baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE  \
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400}

#define CONFIG_ARM_DCC
#define CONFIG_ZYNQ_SERIAL

/* Ethernet driver */
#if defined(CONFIG_ZYNQ_GEM)
# define CONFIG_MII
# define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
# define CONFIG_PHY_MARVELL
# define CONFIG_PHY_REALTEK
# define CONFIG_PHY_XILINX
# define CONFIG_BOOTP_BOOTPATH
# define CONFIG_BOOTP_GATEWAY
# define CONFIG_BOOTP_HOSTNAME
# define CONFIG_BOOTP_MAY_FAIL
#endif

/* SPI */
#ifdef CONFIG_ZYNQ_SPI
#endif

/* QSPI */
#ifdef CONFIG_ZYNQ_QSPI
# define CONFIG_SF_DEFAULT_SPEED	30000000
# define CONFIG_SF_DUAL_FLASH
#endif

/* NOR */
#ifndef CONFIG_SYS_NO_FLASH
# define CONFIG_SYS_FLASH_BASE		0xE2000000
# define CONFIG_SYS_FLASH_SIZE		(16 * 1024 * 1024)
# define CONFIG_SYS_MAX_FLASH_BANKS	1
# define CONFIG_SYS_MAX_FLASH_SECT	512
# define CONFIG_SYS_FLASH_ERASE_TOUT	1000
# define CONFIG_SYS_FLASH_WRITE_TOUT	5000
# define CONFIG_FLASH_SHOW_PROGRESS	10
# define CONFIG_SYS_FLASH_CFI
# undef CONFIG_SYS_FLASH_EMPTY_INFO
# define CONFIG_FLASH_CFI_DRIVER
# undef CONFIG_SYS_FLASH_PROTECTION
# define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#endif

#ifdef CONFIG_NAND_ZYNQ
#define CONFIG_CMD_NAND_LOCK_UNLOCK
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_ONFI_DETECTION
#define CONFIG_MTD_DEVICE
#endif

/* MMC */
#if defined(CONFIG_ZYNQ_SDHCI)
# define CONFIG_GENERIC_MMC
# define CONFIG_ZYNQ_SDHCI_MAX_FREQ	52000000
#endif

#ifdef CONFIG_USB_EHCI_ZYNQ
# define CONFIG_EHCI_IS_TDI

# define CONFIG_SYS_DFU_DATA_BUF_SIZE	0x600000
# define DFU_DEFAULT_POLL_TIMEOUT	300
# define CONFIG_USB_CABLE_CHECK
# define CONFIG_CMD_THOR_DOWNLOAD
# define CONFIG_THOR_RESET_OFF
# define CONFIG_USB_FUNCTION_THOR
/* # define DFU_ALT_INFO_RAM \
	"dfu_ram_info=" \
	"set dfu_alt_info " \
	"${kernel_image} ram 0x3000000 0x500000\\\\;" \
	"${devicetree_image} ram 0x2A00000 0x20000\\\\;" \
	"${ramdisk_image} ram 0x2000000 0x600000\0" \
	"dfu_ram=run dfu_ram_info && dfu 0 ram 0\0" \
	"thor_ram=run dfu_ram_info && thordown 0 ram 0\0" 

# if defined(CONFIG_ZYNQ_SDHCI)
#  define DFU_ALT_INFO_MMC \
	"dfu_mmc_info=" \
	"set dfu_alt_info " \
	"${kernel_image} fat 0 1\\\\;" \
	"${devicetree_image} fat 0 1\\\\;" \
	"${ramdisk_image} fat 0 1\0" \
	"dfu_mmc=run dfu_mmc_info && dfu 0 mmc 0\0" \
	"thor_mmc=run dfu_mmc_info && thordown 0 mmc 0\0" 

#  define DFU_ALT_INFO	\
	DFU_ALT_INFO_RAM \
	DFU_ALT_INFO_MMC
# else
#  define DFU_ALT_INFO	\
	DFU_ALT_INFO_RAM
# endif 
#endif 

#if !defined(DFU_ALT_INFO)
# define DFU_ALT_INFO
#endif */

#if defined(CONFIG_ZYNQ_SDHCI) || defined(CONFIG_ZYNQ_USB)
# define CONFIG_SUPPORT_VFAT
# define CONFIG_FAT_WRITE
# define CONFIG_DOS_PARTITION
#endif

/* NAND */
#ifdef CONFIG_NAND_ZYNQ
# define CONFIG_CMD_NAND_LOCK_UNLOCK
# define CONFIG_SYS_MAX_NAND_DEVICE 1
# define CONFIG_SYS_NAND_ONFI_DETECTION
# define CONFIG_MTD_DEVICE
#endif

#if defined(CONFIG_ZYNQ_I2C0) || defined(CONFIG_ZYNQ_I2C1)
#define CONFIG_SYS_I2C_ZYNQ
#endif

/* I2C */
#if defined(CONFIG_SYS_I2C_ZYNQ)
# define CONFIG_SYS_I2C
# define CONFIG_SYS_I2C_ZYNQ_SPEED		100000
# define CONFIG_SYS_I2C_ZYNQ_SLAVE		0
#endif

/* EEPROM */
#ifdef CONFIG_ZYNQ_EEPROM
# define CONFIG_CMD_EEPROM
# define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		1
# define CONFIG_SYS_I2C_EEPROM_ADDR		0x54
# define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	4
# define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	5
# define CONFIG_SYS_EEPROM_SIZE			1024 /* Bytes */
# define CONFIG_SYS_I2C_MUX_ADDR		0x74
# define CONFIG_SYS_I2C_MUX_EEPROM_SEL		0x4
#endif

/* Total Size of Environment Sector */
#define CONFIG_ENV_SIZE			(128 << 10)

/* Allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

/* Environment */
#ifndef CONFIG_ENV_IS_NOWHERE
# ifndef CONFIG_SYS_NO_FLASH
/* Environment in NOR flash */
#  define CONFIG_ENV_IS_IN_FLASH
# elif defined(CONFIG_ZYNQ_QSPI)
/* Environment in Serial Flash */
#  define CONFIG_ENV_IS_IN_SPI_FLASH
# elif defined(CONFIG_NAND_ZYNQ)
/* Environment in NAND flash */
#  define CONFIG_ENV_IS_IN_NAND
# elif defined(CONFIG_SYS_NO_FLASH)
#  define CONFIG_ENV_IS_NOWHERE
# endif

# define CONFIG_ENV_SECT_SIZE		CONFIG_ENV_SIZE

/* cc108 requires to be 0xF00000 to have boot.bin with bitstream included */
# ifndef CONFIG_ENV_OFFSET
#  define CONFIG_ENV_OFFSET		0xE0000
# endif
#endif

/* enable preboot to be loaded before CONFIG_BOOTDELAY */
#define CONFIG_PREBOOT

/* Default environment */

#ifndef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS	\
	"ethaddr=00:0a:35:00:01:22\0"	\
	"kernel_img=zImage\0"	\
	"kernel_addr=0x2080000\0" \
	"kernel_flash_addr=0x980000\0" \
	"kernel_size=0x500000\0"	\
	"ramdisk_img=zynq-ramdisk.gz\0"	\
	"ramdisk_addr=0x4000000\0"	\
	"ramdisk_flash_addr=0xEA0000\0" \
	"ramdisk_size=0x500000\0"	\
	"dtb_img=avnet-zynq-zed.dtb\0"	\
	"dtb_addr=0x2000000\0"	\
	"dtb_flash_addr=0xE80000\0" \
	"dtb_size=0x20000\0"	\
	"bit_img=download.bit.bin\0"	\
	"bit_addr=0x100000\0"	\
	"bit_flash_addr=0x40000\0"	\
	"bit_size=0x800000\0" \
	"fsbl_img=fsbl.bin\0"	\
	"fsbl_addr=0x2000000\0" \
	"fsbl_flash_addr=0x0\0" \
	"fsbl_size=0x40000\0"	\
	"uboot_img=u-boot.elf.bin\0"	\
	"uboot_addr=0x2000000\0" \
	"uboot_flash_addr=0x840000\0" \
	"uboot_size=0x100000\0"	\
	"bootenv=uEnv.txt\0" \
	"qspiboot=echo Copyin Linux from QSPI flash to RAM... && " \
		"sf probe 0 0 0 && " \
		"sf read ${kernel_addr} ${kernel_flash_addr} ${kernel_size} && " \
		"sf read ${dtb_addr} ${dtb_flash_addr} ${dtb_size} && " \
		"echo Copying ramdisk... && " \
		"sf read ${ramdisk_addr} ${ramdisk_flash_addr} ${ramdisk_size} && " \
		"bootz ${kernel_addr} ${ramdisk_addr} ${dtb_addr}\0" \
	"burn_kernel=echo Download and burn Linux Kernel... &&" \
		"tftpboot ${kernel_addr} ${kernel_img} &&" \
		"sf probe 0 0 0 && " \
		"sf write ${kernel_addr} ${kernel_flash_addr} ${kernel_size}\0" \
	"burn_ramdisk=echo Download and burn Linux Ramdisk... &&" \
		"tftpboot ${ramdisk_addr} ${kernel_img} &&" \
		"sf probe 0 0 0 && " \
		"sf write ${ramdisk_addr} ${ramdisk_flash_addr} ${ramdisk_size}\0" \
	"burn_dtb=echo Download and burn device tree &&" \
		"tftpboot ${dtb_addr} ${dtb_img} &&" \
		"sf probe 0 0 0 && " \
		"sf write ${dtb_addr} ${dtb_flash_addr} ${dtb_size}\0" \
	"burn_dtb=echo Download and burn BIT &&" \
		"tftpboot ${bit_addr} ${bit_img} &&" \
		"sf probe 0 0 0 && " \
		"sf write ${bit_addr} ${bit_flash_addr} ${bit_size}\0" \
	"burn_dtb=echo Download and burn FSBL &&" \
		"tftpboot ${fsbl_addr} ${fsbl_img} &&" \
		"sf probe 0 0 0 && " \
		"sf write ${fsbl_addr} ${fsbl_flash_addr} ${fsbl_size}\0" \
	"burn_dtb=echo Download and burn U-Boot &&" \
		"tftpboot ${uboot_addr} ${uboot_img} &&" \
		"sf probe 0 0 0 && " \
		"sf write ${uboot_addr} ${uboot_flash_addr} ${uboot_size}\0" \
	"bootcmd=run qspiboot\0"
#endif

/* default boot is according to the bootmode switch settings */
#if defined(CONFIG_CMD_ZYNQ_RSA)
#define CONFIG_BOOTCOMMAND		"run rsa_$modeboot"
#else
#define CONFIG_BOOTCOMMAND		"run $modeboot"
#endif
#define CONFIG_SYS_LOAD_ADDR		0 /* default? */

/* Miscellaneous configurable options */

#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_SYS_LONGHELP
#define CONFIG_CLOCKS
#define CONFIG_CMD_CLK
#define CONFIG_SYS_MAXARGS		32 /* max number of command args */
#define CONFIG_SYS_CBSIZE		2048 /* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)

#ifndef CONFIG_NR_DRAM_BANKS
# define CONFIG_NR_DRAM_BANKS		1
#endif

#define CONFIG_SYS_MEMTEST_START	0
#define CONFIG_SYS_MEMTEST_END		0x1000

#define CONFIG_SYS_INIT_RAM_ADDR	0xFFFF0000
#define CONFIG_SYS_INIT_RAM_SIZE	0x2000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR +\
					CONFIG_SYS_INIT_RAM_SIZE -\
					GENERATED_GBL_DATA_SIZE)

/* Enable the PL to be downloaded */
#define CONFIG_FPGA
#define CONFIG_FPGA_XILINX
#define CONFIG_FPGA_ZYNQPL
#define CONFIG_CMD_FPGA_LOADMK
#define CONFIG_CMD_FPGA_LOADP
#define CONFIG_CMD_FPGA_LOADBP
#define CONFIG_CMD_FPGA_LOADFS

/* FIT support */
#define CONFIG_IMAGE_FORMAT_LEGACY /* enable also legacy image format */

/* FDT support */
#define CONFIG_DISPLAY_BOARDINFO_LATE

/* Extend size of kernel image for uncompression */
#define CONFIG_SYS_BOOTM_LEN	(60 * 1024 * 1024)

/* Boot FreeBSD/vxWorks from an ELF image */
#define CONFIG_SYS_MMC_MAX_DEVICE	1

#define CONFIG_SYS_LDSCRIPT  "arch/arm/mach-zynq/u-boot.lds"

/* Commands */
#if defined(CONFIG_CMD_ZYNQ_RSA)
#define CONFIG_SHA256
#endif

#undef CONFIG_BOOTM_NETBSD

#define CONFIG_SYS_HZ			1000

/* For development/debugging */
#ifdef DEBUG
# define CONFIG_CMD_REGINFO
# define CONFIG_PANIC_HANG
#endif

/* SPL part */
#define CONFIG_CMD_SPL
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_BOARD_INIT
#define CONFIG_SPL_RAM_DEVICE

#define CONFIG_SPL_LDSCRIPT	"arch/arm/mach-zynq/u-boot-spl.lds"

/* FPGA support */
#define CONFIG_SPL_FPGA_SUPPORT
#define CONFIG_SPL_FPGA_LOAD_ADDR      0x1000000
/* #define CONFIG_SPL_FPGA_BIT */
#ifdef CONFIG_SPL_FPGA_BIT
# define CONFIG_SPL_FPGA_LOAD_ARGS_NAME "download.bit"
#else
# define CONFIG_SPL_FPGA_LOAD_ARGS_NAME "fpga.bin"
#endif

/* MMC support */
#ifdef CONFIG_ZYNQ_SDHCI
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION     1
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME     "u-boot.img"
#endif

/* Disable dcache for SPL just for sure */
#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_DCACHE_OFF
#undef CONFIG_FPGA
#endif

/* Address in RAM where the parameters must be copied by SPL. */
#define CONFIG_SYS_SPL_ARGS_ADDR	0x10000000

#define CONFIG_SPL_FS_LOAD_ARGS_NAME		"system.dtb"
#define CONFIG_SPL_FS_LOAD_KERNEL_NAME		"uImage"

/* Not using MMC raw mode - just for compilation purpose */
#define CONFIG_SYS_MMCSD_RAW_MODE_ARGS_SECTOR	0
#define CONFIG_SYS_MMCSD_RAW_MODE_ARGS_SECTORS	0
#define CONFIG_SYS_MMCSD_RAW_MODE_KERNEL_SECTOR	0

/* qspi mode is working fine */
#ifdef CONFIG_ZYNQ_QSPI
#define CONFIG_SPL_SPI_LOAD
#define CONFIG_SYS_SPI_U_BOOT_OFFS	0x100000
#define CONFIG_SYS_SPI_ARGS_OFFS	0x200000
#define CONFIG_SYS_SPI_ARGS_SIZE	0x80000
#define CONFIG_SYS_SPI_KERNEL_OFFS	(CONFIG_SYS_SPI_ARGS_OFFS + \
					CONFIG_SYS_SPI_ARGS_SIZE)
#endif

#define CONFIG_SPL_RAM_DEVICE

/* for booting directly linux */

/* SP location before relocation, must use scratch RAM */
#define CONFIG_SPL_TEXT_BASE	0x0

/* 3 * 64kB blocks of OCM - one is on the top because of bootrom */
#define CONFIG_SPL_MAX_SIZE	0x30000

/* The highest 64k OCM address */
#define OCM_HIGH_ADDR	0xffff0000

/* On the top of OCM space */
#define CONFIG_SYS_SPL_MALLOC_START	OCM_HIGH_ADDR
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x2000

/*
 * SPL stack position - and stack goes down
 * 0xfffffe00 is used for putting wfi loop.
 * Set it up as limit for now.
 */
#define CONFIG_SPL_STACK	0xfffffe00

/* BSS setup */
#define CONFIG_SPL_BSS_START_ADDR	0x100000
#define CONFIG_SPL_BSS_MAX_SIZE		0x100000

#define CONFIG_SYS_UBOOT_START	CONFIG_SYS_TEXT_BASE

#endif /* __CONFIG_ZYNQ_COMMON_H */
