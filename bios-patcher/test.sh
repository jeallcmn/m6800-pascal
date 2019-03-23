#!/bin/sh

umount -f /dev/sdc1
mkdir -p /media/jon/syslinux
mount -o flush,sync /dev/sdc1 /media/jon/syslinux

cp bios_patcher.c32 /media/jon/syslinux
cp syslinux.cfg /media/jon/syslinux

umount /dev/sdc1

sleep 1

qemu-system-x86_64 -hda /dev/sdc -acpitable file=../test-acpi-tables/DSDT.aml

