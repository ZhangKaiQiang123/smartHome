#外部编译Makefile模板：
#编译ubuntu用的内核模块时：make arch=arm
#编译开发板用的内核模块时：make 

#ifeq ($(KERNELRELEASE),)

arch ?= arm
ifeq ($(arch),arm)
KERNELDIR ?= /home/ubuntu/fsmp157a/kernel
else
KERNELDIR ?= /lib/modules/$(shell uname -r)/build/
endif

#KBUILD_EXTRA_SYMBOLS := /home/ubuntu/ldf/test/driver/demo2/Module.symvers

PWD := $(shell pwd)
mn ?= si7006_driver

all:
	@echo "################### driver.c #####################"
	make -C $(KERNELDIR) M=$(PWD) modules
	@echo "################### test.c #####################"
	arm-linux-gnueabihf-gcc test.c -Wall 

arm:
	make -C /home/ubuntu/fsmp157a/kernel/ M=$(PWD) modules

x86:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	@rm -rf  *.o  *.ko .*.cmd  *.mod.*  *.mod  modules.order  Module.symvers   .tmp_versions   *.out
	@echo "  CLEAN   complete."

install:
	@cp *.ko a.out ~/nfs/rootfs/
	@echo "  INSTALL   complete."

#else
obj-m := $(mn).o

#endif
