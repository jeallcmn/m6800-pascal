/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20180105 (64-bit version)
 * Copyright (c) 2000 - 2018 Intel Corporation
 * 
 * Disassembling to symbolic ASL+ operators
 *
 * Disassembly of ssdt2.dat, Wed Apr 17 20:33:03 2019
 *
 * Original Table Header:
 *     Signature        "SSDT"
 *     Length           0x00000160 (352)
 *     Revision         0x01
 *     Checksum         0x78
 *     OEM ID           "Intel"
 *     OEM Table ID     "zpodd"
 *     OEM Revision     0x00001000 (4096)
 *     Compiler ID      "INTL"
 *     Compiler Version 0x20120711 (538052369)
 */
DefinitionBlock ("", "SSDT", 1, "Intel", "zpodd", 0x00001000)
{
    External (_SB_.PCI0.SAT0, UnknownObj)
    External (_SB_.PCI0.SAT0.PRT1, DeviceObj)
    External (FDTP, IntObj)
    External (GL08, FieldUnitObj)
    External (GPE3, FieldUnitObj)
    External (PFLV, FieldUnitObj)
    External (RTD3, FieldUnitObj)

    OperationRegion (ECBX, SystemIO, 0xB2, 0x02)
    Field (ECBX, ByteAcc, NoLock, Preserve)
    {
        ECSI,   8, 
        ECSD,   8
    }

    If ((RTD3 == Zero))
    {
        Scope (\_SB.PCI0.SAT0.PRT1)
        {
            Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
            {
                If ((Arg0 == ToUUID ("bdfaef30-aebb-11de-8a39-0800200c9a66")))
                {
                    Switch (ToInteger (Arg2))
                    {
                        Case (Zero)
                        {
                            Switch (ToInteger (Arg1))
                            {
                                Case (One)
                                {
                                    If ((PFLV == FDTP))
                                    {
                                        Return (Buffer (One)
                                        {
                                             0x00                                             // .
                                        })
                                    }

                                    Return (Buffer (One)
                                    {
                                         0x0F                                             // .
                                    })
                                }
                                Default
                                {
                                    Return (Buffer (One)
                                    {
                                         0x00                                             // .
                                    })
                                }

                            }
                        }
                        Case (One)
                        {
                            Return (One)
                        }
                        Case (0x02)
                        {
                            ECSD = 0x55
                            ECSI = 0xE2
                            Return (One)
                        }
                        Case (0x03)
                        {
                            ECSD = 0xAA
                            ECSI = 0xE2
                            Return (One)
                        }
                        Default
                        {
                            Return (Zero)
                        }

                    }
                }
                Else
                {
                    Return (Zero)
                }
            }
        }

        Scope (\_GPE)
        {
            Method (_L13, 0, NotSerialized)  // _Lxx: Level-Triggered GPE
            {
                If ((PFLV == FDTP))
                {
                    Return (Zero)
                }

                GPE3 = Zero
                \GL08 |= 0x10
                Notify (\_SB.PCI0.SAT0, 0x82) // Device-Specific Change
                Return (Zero)
            }
        }
    }
}

