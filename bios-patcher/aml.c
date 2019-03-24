//
// Created by jon on 3/23/19.
//

#include "aml.h"

aml_op_hdr * find_region(acpi_hdr *dsdt, char region_name[4]) {
    aml_op_hdr region_hdr = {
            .op = 0x5B,
            .op_type = 0x80,
            .region_type = 0x00
    };

    strncpy(region_hdr.name, region_name, 4);

    uint8_t * current = (uint8_t *) dsdt;
    for(uint8_t i = 0; i< (dsdt -> len); i++ ) {
        aml_op_hdr * op = (aml_op_hdr *) current;

        if( memcmp(op, &region_hdr, sizeof(region_hdr)) == 0) {
            return op;
        }
        current ++;
    }
    return 0;
}

void * find_field(aml_opreg, char name[4]) {

}

