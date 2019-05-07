#!/bin/sh



umount -f /dev/mmcblk0p1
mkdir -p /media/jon/syslinux
mount -o flush,sync /dev/mmcblk0p1 /media/jon/syslinux

cp bios_patcher.c32 /media/jon/syslinux
cp syslinux.cfg /media/jon/syslinux

umount /dev/mmcblk0p1

sleep 1

qemu-system-x86_64 -hda /dev/mmcblk0 -acpitable file=../test-acpi-tables/DSDT.aml

