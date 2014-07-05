INSTALLDIR= modules
ifneq ($(KERNELRELEASE),)
	obj-m := nit.o
nit-objs := init.o cleanup.o scullopen.o scullrelease.o scullwrite.o scullread.o sculllseek.o

else
	KERNDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
	rm -rf $(INSTALLDIR)

endif

