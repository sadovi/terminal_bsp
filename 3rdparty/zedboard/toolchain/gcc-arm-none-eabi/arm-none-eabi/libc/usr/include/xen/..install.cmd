cmd_/proj/esdt_sdk/gnu_abe/ABE/builds/lin/arm/arm-none-eabi/builds/destdir/x86_64-unknown-linux-gnu/arm-none-eabi/libc/usr/include/xen/.install := /bin/sh scripts/headers_install.sh /proj/esdt_sdk/gnu_abe/ABE/builds/lin/arm/arm-none-eabi/builds/destdir/x86_64-unknown-linux-gnu/arm-none-eabi/libc/usr/include/xen ./include/uapi/xen evtchn.h gntalloc.h gntdev.h privcmd.h; /bin/sh scripts/headers_install.sh /proj/esdt_sdk/gnu_abe/ABE/builds/lin/arm/arm-none-eabi/builds/destdir/x86_64-unknown-linux-gnu/arm-none-eabi/libc/usr/include/xen ./include/xen ; /bin/sh scripts/headers_install.sh /proj/esdt_sdk/gnu_abe/ABE/builds/lin/arm/arm-none-eabi/builds/destdir/x86_64-unknown-linux-gnu/arm-none-eabi/libc/usr/include/xen ./include/generated/uapi/xen ; for F in ; do echo "\#include <asm-generic/$$F>" > /proj/esdt_sdk/gnu_abe/ABE/builds/lin/arm/arm-none-eabi/builds/destdir/x86_64-unknown-linux-gnu/arm-none-eabi/libc/usr/include/xen/$$F; done; touch /proj/esdt_sdk/gnu_abe/ABE/builds/lin/arm/arm-none-eabi/builds/destdir/x86_64-unknown-linux-gnu/arm-none-eabi/libc/usr/include/xen/.install
