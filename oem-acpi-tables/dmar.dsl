/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20180105 (64-bit version)
 * Copyright (c) 2000 - 2018 Intel Corporation
 * 
 * Disassembly of dmar.dat, Wed Mar 27 17:55:47 2019
 *
 * ACPI Data Table [DMAR]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "DMAR"    [DMA Remapping table]
[004h 0004   4]                 Table Length : 00000080
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 0C
[00Ah 0010   6]                       Oem ID : "INTEL "
[010h 0016   8]                 Oem Table ID : "HSW "
[018h 0024   4]                 Oem Revision : 00000001
[01Ch 0028   4]              Asl Compiler ID : "INTL"
[020h 0032   4]        Asl Compiler Revision : 00000001

[024h 0036   1]           Host Address Width : 26
[025h 0037   1]                        Flags : 01
[026h 0038  10]                     Reserved : 00 00 00 00 00 00 00 00 00 00

[030h 0048   2]                Subtable Type : 0000 [Hardware Unit Definition]
[032h 0050   2]                       Length : 0020

[034h 0052   1]                        Flags : 01
[035h 0053   1]                     Reserved : 00
[036h 0054   2]           PCI Segment Number : 0000
[038h 0056   8]        Register Base Address : 00000000FED90000

[040h 0064   1]            Device Scope Type : 03 [IOAPIC Device]
[041h 0065   1]                 Entry Length : 08
[042h 0066   2]                     Reserved : 0000
[044h 0068   1]               Enumeration ID : 08
[045h 0069   1]               PCI Bus Number : F0

[046h 0070   2]                     PCI Path : 1F,00


[048h 0072   1]            Device Scope Type : 04 [Message-capable HPET Device]
[049h 0073   1]                 Entry Length : 08
[04Ah 0074   2]                     Reserved : 0000
[04Ch 0076   1]               Enumeration ID : 00
[04Dh 0077   1]               PCI Bus Number : F0

[04Eh 0078   2]                     PCI Path : 0F,00


[050h 0080   2]                Subtable Type : 0001 [Reserved Memory Region]
[052h 0082   2]                       Length : 0030

[054h 0084   2]                     Reserved : 0000
[056h 0086   2]           PCI Segment Number : 0000
[058h 0088   8]                 Base Address : 00000000CAF19000
[060h 0096   8]          End Address (limit) : 00000000CAF27FFF

[068h 0104   1]            Device Scope Type : 01 [PCI Endpoint Device]
[069h 0105   1]                 Entry Length : 08
[06Ah 0106   2]                     Reserved : 0000
[06Ch 0108   1]               Enumeration ID : 00
[06Dh 0109   1]               PCI Bus Number : 00

[06Eh 0110   2]                     PCI Path : 1D,00


[070h 0112   1]            Device Scope Type : 01 [PCI Endpoint Device]
[071h 0113   1]                 Entry Length : 08
[072h 0114   2]                     Reserved : 0000
[074h 0116   1]               Enumeration ID : 00
[075h 0117   1]               PCI Bus Number : 00

[076h 0118   2]                     PCI Path : 1A,00


[078h 0120   1]            Device Scope Type : 01 [PCI Endpoint Device]
[079h 0121   1]                 Entry Length : 08
[07Ah 0122   2]                     Reserved : 0000
[07Ch 0124   1]               Enumeration ID : 00
[07Dh 0125   1]               PCI Bus Number : 00

[07Eh 0126   2]                     PCI Path : 14,00


Raw Table Data: Length 128 (0x80)

  0000: 44 4D 41 52 80 00 00 00 01 0C 49 4E 54 45 4C 20  // DMAR......INTEL 
  0010: 48 53 57 20 00 00 00 00 01 00 00 00 49 4E 54 4C  // HSW ........INTL
  0020: 01 00 00 00 26 01 00 00 00 00 00 00 00 00 00 00  // ....&...........
  0030: 00 00 20 00 01 00 00 00 00 00 D9 FE 00 00 00 00  // .. .............
  0040: 03 08 00 00 08 F0 1F 00 04 08 00 00 00 F0 0F 00  // ................
  0050: 01 00 30 00 00 00 00 00 00 90 F1 CA 00 00 00 00  // ..0.............
  0060: FF 7F F2 CA 00 00 00 00 01 08 00 00 00 00 1D 00  // ................
  0070: 01 08 00 00 00 00 1A 00 01 08 00 00 00 00 14 00  // ................
