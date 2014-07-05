#! /bin/bash
ci init.c
ci cleanup.c
ci header.h
ci decleration.h
ci open.c
ci scull_write.c
ci release.c

read v

co init.c
co cleanup.c
co header.h
co decleration.h
co open.c
co scull_write.c
co release.c
read v
#ifndef DEBUG
#DEFINE DEBUG
#endif
make
read v

insmod ./modules/ravi.ko nod=10 quantum_size=8 qset_size=8 data_size=0 device_size=1024
dmesg
read v
lsmod
read v
./application_cdriver
rmmod ./modles/ravi
dmesg | tail -2
read v
dmesg -c
rm -rf init.c cleanup.c header.h declarations.c modules.order modules Module.symvers
