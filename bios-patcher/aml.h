//
// Created by jon on 3/23/19.
//

#ifndef BIOS_PATCHER_AML_H
#define BIOS_PATCHER_AML_H

#include "acpi.h"

typedef struct aml_op_hdr {
    uint8_t op;
    uint8_t op_type;
    char name[4];
    uint8_t region_type;
} aml_op_hdr;

typedef struct aml_opreg {
    aml_op_hdr hdr;
    uint8_t parm1_type;
    uint32_t parm1;
    uint8_t parm2_type;
    uint16_t parm2;
} aml_opreg;

typedef struct field_value {
    char region[4];
    char field[4];
    uint32_t field_location;
    uint32_t offset_value;
} field_value;

aml_op_hdr * find_region(acpi_hdr *dsdt, char name[4]);

#endif //BIOS_PATCHER_AML_H
