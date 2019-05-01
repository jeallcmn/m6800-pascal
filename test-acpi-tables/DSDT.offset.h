/*
 * 
 * Intel ACPI Component Architecture
 * ASL+ Optimizing Compiler/Disassembler version 20180105 (64-bit version)
 * Copyright (c) 2000 - 2018 Intel Corporation
 * 
 * Compilation of "DSDT.dsl" - Fri Apr 12 14:01:42 2019
 * 
 */
#ifndef __AML_OFFSET_TABLE_H
#define __AML_OFFSET_TABLE_H

typedef struct {
    char                   *Pathname;      /* Full pathname (from root) to the object */
    unsigned short         ParentOpcode;   /* AML opcode for the parent object */
    unsigned long          NamesegOffset;  /* Offset of last nameseg in the parent namepath */
    unsigned char          Opcode;         /* AML opcode for the data */
    unsigned long          Offset;         /* Offset for the data */
    unsigned long long     Value;          /* Original value of the data (as applicable) */
} AML_OFFSET_TABLE_ENTRY;

#endif /* __AML_OFFSET_TABLE_H */

/*
 * Information specific to the supported object types:
 *
 * Integers:
 *    Opcode is the integer prefix, indicates length of the data
 *        (One of: BYTE, WORD, DWORD, QWORD, ZERO, ONE, ONES)
 *    Offset points to the actual integer data
 *    Value is the existing value in the AML
 *
 * Packages:
 *    Opcode is the package or var_package opcode
 *    Offset points to the package opcode
 *    Value is the package element count
 *
 * Operation Regions:
 *    Opcode is the address integer prefix, indicates length of the data
 *    Offset points to the region address
 *    Value is the existing address value in the AML
 *
 * Control Methods:
 *    Offset points to the method flags byte
 *    Value is the existing flags value in the AML
 *
 * Processors:
 *    Offset points to the first byte of the PBlock Address
 *
 * Resource Descriptors:
 *    Opcode is the descriptor type
 *    Offset points to the start of the descriptor
 *
 * Scopes/Devices/ThermalZones:
 *    Nameseg offset only
 */
AML_OFFSET_TABLE_ENTRY   DSDT_CBX3____OffsetTable[] =
{
    {"SMBS",                       0x0008, 0x00000169, 0x0B, 0x0000016E, 0x0000000000000580}, /* INTEGER */
    {"SMBL",                       0x0008, 0x00000171, 0x0A, 0x00000176, 0x0000000000000020}, /* INTEGER */
    {"PMBS",                       0x0008, 0x00000178, 0x0B, 0x0000017D, 0x0000000000001800}, /* INTEGER */
    {"GPBS",                       0x0008, 0x00000180, 0x0B, 0x00000185, 0x0000000000001C00}, /* INTEGER */
    {"SMIP",                       0x0008, 0x00000188, 0x0A, 0x0000018D, 0x00000000000000B2}, /* INTEGER */
    {"APCB",                       0x0008, 0x0000018F, 0x0C, 0x00000194, 0x00000000FEC00000}, /* INTEGER */
    {"APCL",                       0x0008, 0x00000199, 0x0B, 0x0000019E, 0x0000000000001000}, /* INTEGER */
    {"SMCR",                       0x0008, 0x000001A1, 0x0B, 0x000001A6, 0x0000000000001830}, /* INTEGER */
    {"HPTB",                       0x0008, 0x000001A9, 0x0C, 0x000001AE, 0x00000000FED00000}, /* INTEGER */
    {"HPTC",                       0x0008, 0x000001B3, 0x0C, 0x000001B8, 0x0000000lji;0FED1F404}, /* INTEGER */
    {"FLSZ",                       0x0008, 0x000001BD, 0x0C, 0x000001C2, 0x0000000000600000}, /* INTEGER */
    {"SRCB",                       0x0008, 0x000001C7, 0x0C, 0x000001CC, 0x00000000FED1C000}, /* INTEGER */
    {"RCLN",                       0x0008, 0x000001D1, 0x0B, 0x000001D6, 0x0000000000004000}, /* INTEGER */
    {"PEBS",                       0x0008, 0x000001D9, 0x0C, 0x000001DE, 0x00000000F8000000}, /* INTEGER */
    {"PELN",                       0x0008, 0x000001E3, 0x0C, 0x000001E8, 0x0000000004000000}, /* INTEGER */
    {"LAPB",                       0x0008, 0x000001ED, 0x0C, 0x000001F2, 0x00000000FEE00000}, /* INTEGER */
    {"EGPB",                       0x0008, 0x000001F7, 0x0C, 0x000001FC, 0x00000000FED19000}, /* INTEGER */
    {"MCHB",                       0x0008, 0x00000201, 0x0C, 0x00000206, 0x00000000FED10000}, /* INTEGER */
    {"VTBS",                       0x0008, 0x0000020B, 0x0C, 0x00000210, 0x00000000FED90000}, /* INTEGER */
    {"VTLN",                       0x0008, 0x00000215, 0x0B, 0x0000021A, 0x0000000000004000}, /* INTEGER */
    {"ACPH",                       0x0008, 0x0000021D, 0x0A, 0x00000222, 0x00000000000000DE}, /* INTEGER */
    {"ASSB",                       0x0008, 0x00000224, 0x00, 0x00000228, 0x0000000000000000}, /* ZERO */
    {"AOTB",                       0x0008, 0x0000022A, 0x00, 0x0000022E, 0x0000000000000000}, /* ZERO */
    {"AAXB",                       0x0008, 0x00000230, 0x00, 0x00000234, 0x0000000000000000}, /* ZERO */
    {"PEHP",                       0x0008, 0x00000236, 0x01, 0x0000023A, 0x0000000000000001}, /* ONE */
    {"SHPC",                       0x0008, 0x0000023C, 0x01, 0x00000240, 0x0000000000000001}, /* ONE */
    {"PEPM",                       0x0008, 0x00000242, 0x01, 0x00000246, 0x0000000000000001}, /* ONE */
    {"PEER",                       0x0008, 0x00000248, 0x01, 0x0000024C, 0x0000000000000001}, /* ONE */
    {"PECS",                       0x0008, 0x0000024E, 0x01, 0x00000252, 0x0000000000000001}, /* ONE */
    {"ITKE",                       0x0008, 0x00000254, 0x00, 0x00000258, 0x0000000000000000}, /* ZERO */
    {"FMBL",                       0x0008, 0x0000025A, 0x01, 0x0000025E, 0x0000000000000001}, /* ONE */
    {"FDTP",                       0x0008, 0x00000260, 0x0A, 0x00000265, 0x0000000000000002}, /* INTEGER */
    {"FUPS",                       0x0008, 0x00000267, 0x0A, 0x0000026C, 0x0000000000000003}, /* INTEGER */
    {"FUWS",                       0x0008, 0x0000026E, 0x0A, 0x00000273, 0x0000000000000004}, /* INTEGER */
    {"BGR_",                       0x0008, 0x00000275, 0x01, 0x00000279, 0x0000000000000001}, /* ONE */
    {"BFR_",                       0x0008, 0x0000027B, 0x0A, 0x00000280, 0x0000000000000002}, /* INTEGER */
    {"BBR_",                       0x0008, 0x00000282, 0x0A, 0x00000287, 0x0000000000000003}, /* INTEGER */
    {"BWC_",                       0x0008, 0x00000289, 0x0A, 0x0000028E, 0x0000000000000004}, /* INTEGER */
    {"BWT1",                       0x0008, 0x00000290, 0x0A, 0x00000295, 0x0000000000000020}, /* INTEGER */
    {"BFHC",                       0x0008, 0x00000297, 0x0B, 0x0000029C, 0x0000000000000100}, /* INTEGER */
    {"TRTP",                       0x0008, 0x0000029F, 0x01, 0x000002A3, 0x0000000000000001}, /* ONE */
    {"WDTE",                       0x0008, 0x000002A5, 0x01, 0x000002A9, 0x0000000000000001}, /* ONE */
    {"TRTD",                       0x0008, 0x000002AB, 0x0A, 0x000002B0, 0x0000000000000002}, /* INTEGER */
    {"TRTI",                       0x0008, 0x000002B2, 0x0A, 0x000002B7, 0x0000000000000003}, /* INTEGER */
    {"PFTI",                       0x0008, 0x000002B9, 0x0A, 0x000002BE, 0x0000000000000004}, /* INTEGER */
    {"GCDD",                       0x0008, 0x000002C0, 0x01, 0x000002C4, 0x0000000000000001}, /* ONE */
    {"DSTA",                       0x0008, 0x000002C6, 0x0A, 0x000002CB, 0x000000000000000A}, /* INTEGER */
    {"DSLO",                       0x0008, 0x000002CD, 0x0A, 0x000002D2, 0x000000000000000C}, /* INTEGER */
    {"DSLC",                       0x0008, 0x000002D4, 0x0A, 0x000002D9, 0x000000000000000E}, /* INTEGER */
    {"PITS",                       0x0008, 0x000002DB, 0x0A, 0x000002E0, 0x0000000000000010}, /* INTEGER */
    {"SBCS",                       0x0008, 0x000002E2, 0x0A, 0x000002E7, 0x0000000000000012}, /* INTEGER */
    {"SALS",                       0x0008, 0x000002E9, 0x0A, 0x000002EE, 0x0000000000000013}, /* INTEGER */
    {"LSSS",                       0x0008, 0x000002F0, 0x0A, 0x000002F5, 0x000000000000002A}, /* INTEGER */
    {"SOOT",                       0x0008, 0x000002F7, 0x0A, 0x000002FC, 0x0000000000000035}, /* INTEGER */
    {"PDBR",                       0x0008, 0x000002FE, 0x0A, 0x00000303, 0x000000000000004D}, /* INTEGER */
    {"BW1P",                       0x0008, 0x00000305, 0x0A, 0x0000030A, 0x0000000000000021}, /* INTEGER */
    {"BW2C",                       0x0008, 0x0000030C, 0x0A, 0x00000311, 0x0000000000000022}, /* INTEGER */
    {"BW2P",                       0x0008, 0x00000313, 0x0A, 0x00000318, 0x0000000000000023}, /* INTEGER */
    {"BSPC",                       0x0008, 0x0000031A, 0x0A, 0x0000031F, 0x0000000000000024}, /* INTEGER */
    {"BSPP",                       0x0008, 0x00000321, 0x0A, 0x00000326, 0x0000000000000025}, /* INTEGER */
    {"BICO",                       0x0008, 0x00000328, 0x0A, 0x0000032D, 0x0000000000000027}, /* INTEGER */
    {"BICC",                       0x0008, 0x0000032F, 0x0A, 0x00000334, 0x0000000000000028}, /* INTEGER */
    {"BHB_",                       0x0008, 0x00000336, 0x0A, 0x0000033B, 0x0000000000000030}, /* INTEGER */
    {"BFS2",                       0x0008, 0x0000033D, 0x0A, 0x00000342, 0x0000000000000031}, /* INTEGER */
    {"BFS3",                       0x0008, 0x00000344, 0x0A, 0x00000349, 0x0000000000000032}, /* INTEGER */
    {"BFS4",                       0x0008, 0x0000034B, 0x0A, 0x00000350, 0x0000000000000033}, /* INTEGER */
    {"BRH_",                       0x0008, 0x00000352, 0x0A, 0x00000357, 0x0000000000000035}, /* INTEGER */
    {"SMIT",                       0x0008, 0x00000359, 0x0A, 0x0000035E, 0x00000000000000B2}, /* INTEGER */
    {"OFST",                       0x0008, 0x00000360, 0x0A, 0x00000365, 0x00000000000000BC}, /* INTEGER */
    {"TPMF",                       0x0008, 0x00000367, 0x00, 0x0000036B, 0x0000000000000000}, /* ZERO */
    {"TCMF",                       0x0008, 0x0000036D, 0x00, 0x00000371, 0x0000000000000000}, /* ZERO */
    {"TMF1",                       0x0008, 0x00000373, 0x00, 0x00000377, 0x0000000000000000}, /* ZERO */
    {"TMF2",                       0x0008, 0x00000379, 0x00, 0x0000037D, 0x0000000000000000}, /* ZERO */
    {"TMF3",                       0x0008, 0x0000037F, 0x00, 0x00000383, 0x0000000000000000}, /* ZERO */
    {"TRST",                       0x0008, 0x00000385, 0x0A, 0x0000038A, 0x0000000000000002}, /* INTEGER */
    {"CIDK",                       0x0008, 0x000003AA, 0x0C, 0x000003AF, 0x000000000303D041}, /* INTEGER */
    {"CIDM",                       0x0008, 0x000003B4, 0x0C, 0x000003B9, 0x00000000030FD041}, /* INTEGER */
    {"MBEC",                       0x0008, 0x000003BE, 0x00, 0x000003C2, 0x0000000000000000}, /* ZERO */
    {"PMLN",                       0x0008, 0x000003C4, 0x0B, 0x000003C9, 0x0000000000000100}, /* INTEGER */
    {"GPLN",                       0x0008, 0x000003CC, 0x0B, 0x000003D1, 0x0000000000000400}, /* INTEGER */
    {"SP1O",                       0x0008, 0x000003D4, 0x0B, 0x000003D9, 0x000000000000094E}, /* INTEGER */
    {"IOPB",                       0x0008, 0x000003DC, 0x0B, 0x000003E1, 0x000000000000094E}, /* INTEGER */
    {"IFSC",                       0x0008, 0x000003E4, 0x0A, 0x000003E9, 0x00000000000000B5}, /* INTEGER */
    {"DSSP",                       0x0008, 0x000003EB, 0x00, 0x000003EF, 0x0000000000000000}, /* ZERO */
    {"FHPP",                       0x0008, 0x000003F1, 0x00, 0x000003F5, 0x0000000000000000}, /* ZERO */
    {"SS1_",                       0x0008, 0x000003F7, 0x00, 0x000003FB, 0x0000000000000000}, /* ZERO */
    {"SS2_",                       0x0008, 0x000003FD, 0x00, 0x00000401, 0x0000000000000000}, /* ZERO */
    {"SS3_",                       0x0008, 0x00000403, 0x01, 0x00000407, 0x0000000000000001}, /* ONE */
    {"SS4_",                       0x0008, 0x00000409, 0x01, 0x0000040D, 0x0000000000000001}, /* ONE */
    {"IOST",                       0x0008, 0x0000040F, 0x0B, 0x00000414, 0x0000000000004400}, /* INTEGER */
    {"TOPM",                       0x0008, 0x00000417, 0x00, 0x0000041B, 0x0000000000000000}, /* INTEGER */
    {"ROMS",                       0x0008, 0x0000041D, 0x0C, 0x00000422, 0x00000000FFE00000}, /* INTEGER */
    {"VGAF",                       0x0008, 0x00000427, 0x01, 0x0000042B, 0x0000000000000001}, /* ONE */
    {"GNVS",                       0x5B80, 0x0000042E, 0x0C, 0x00000434, 0x00000000CA7FCC18}, /* OPERATIONREGION */
    {"SANV",                       0x5B80, 0x00000A40, 0x0C, 0x00000A46, 0x00000000CA7FDC18}, /* OPERATIONREGION */
    {"EXBU",                       0x5B80, 0x00000C90, 0x0C, 0x00000C96, 0x00000000CA7FFF18}, /* OPERATIONREGION */
    {NULL,0,0,0,0,0} /* Table terminator */
};

