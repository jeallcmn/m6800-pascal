/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20180105 (64-bit version)
 * Copyright (c) 2000 - 2018 Intel Corporation
 * 
 * Disassembly of lpit.dat, Wed Mar 27 17:55:47 2019
 *
 * ACPI Data Table [LPIT]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "LPIT"    [Low Power Idle Table]
[004h 0004   4]                 Table Length : 0000005C
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 16
[00Ah 0010   6]                       Oem ID : "DELL  "
[010h 0016   8]                 Oem Table ID : "CBX3   "
[018h 0024   4]                 Oem Revision : 00000000
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000005

[024h 0036   4]                Subtable Type : 00000000 [Native C-state Idle Structure]
[028h 0040   4]                       Length : 00000038
[02Ch 0044   2]                    Unique ID : 0000
[02Eh 0046   2]                     Reserved : 0000
[030h 0048   4]        Flags (decoded below) : 00000000
                              State Disabled : 0
                                  No Counter : 0

[034h 0052  12]                Entry Trigger : [Generic Address Structure]
[034h 0052   1]                     Space ID : 7F [FunctionalFixedHW]
[035h 0053   1]                    Bit Width : 01
[036h 0054   1]                   Bit Offset : 02
[037h 0055   1]         Encoded Access Width : 00 [Undefined/Legacy]
[038h 0056   8]                      Address : 0000000000000060

[040h 0064   4]                    Residency : 00007530
[044h 0068   4]                      Latency : 00000BB8
[048h 0072  12]            Residency Counter : [Generic Address Structure]
[048h 0072   1]                     Space ID : 7F [FunctionalFixedHW]
[049h 0073   1]                    Bit Width : 40
[04Ah 0074   1]                   Bit Offset : 00
[04Bh 0075   1]         Encoded Access Width : 00 [Undefined/Legacy]
[04Ch 0076   8]                      Address : 0000000000000632

[054h 0084   8]            Counter Frequency : 0000000000000000


Raw Table Data: Length 92 (0x5C)

  0000: 4C 50 49 54 5C 00 00 00 01 16 44 45 4C 4C 20 20  // LPIT\.....DELL  
  0010: 43 42 58 33 20 20 20 00 00 00 00 00 41 4D 49 2E  // CBX3   .....AMI.
  0020: 05 00 00 00 00 00 00 00 38 00 00 00 00 00 00 00  // ........8.......
  0030: 00 00 00 00 7F 01 02 00 60 00 00 00 00 00 00 00  // ........`.......
  0040: 30 75 00 00 B8 0B 00 00 7F 40 00 00 32 06 00 00  // 0u.......@..2...
  0050: 00 00 00 00 00 00 00 00 00 00 00 00              // ............
