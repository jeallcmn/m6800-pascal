#include "fields.h"

#include <stdio.h>
#include "acpi.h"
#include "aml.h"

void set_dsdt_field_value(acpi_hdr * dsdt, field_value * value) {

    aml_opreg * region = (aml_opreg *)find_region(dsdt, value -> region);
    if( region != 0) {
        printf("Region %.4s @ %#08x\n", region -> hdr.name, region -> parm1);

        void * field = (void *) region->parm1 + value->field_location;

        uint32_t updated_value = (uint32_t) region->parm1 - value -> offset_value;
        printf("\t setting value of %.4s at %#08x to %#08x\n", value -> field, (uint32_t)field, (uint32_t)updated_value);

        memcpy(field, &updated_value, 4);
    } else {
        printf("Region not found!\n");
    }
//  0xcd6d7000
//  0
}

void set_field_value(field_value * value) {
    printf("Setting %.4s.%.4s field to %#08x\n", value -> region, value -> field, value->offset_value);

    acpi_rsdp *rsdp = find_rsdp();

    // RSDT
    printf("RSDT %#08x:\n", rsdp -> rsdt_addr);
    acpi_fadt * fadt = (acpi_fadt *)find_rsdt_entry((acpi_rsdt *) rsdp -> rsdt_addr, "FACP");
    acpi_hdr * dsdt = (acpi_hdr * ) fadt -> dsdt_addr;
    set_dsdt_field_value(dsdt, value);

    //also look in entries for qemu testing...
//    dsdt = (acpi_hdr *) find_rsdt_entry( (acpi_rsdt *) rsdp -> rsdt_addr, "DSDT");
//    set_dsdt_field_value(dsdt, value);

    // XSDT
    if(rsdp -> xsdt_addr != 0) {
        fadt = (acpi_fadt *)find_xsdt_entry((acpi_xsdt *)(uint32_t)rsdp -> xsdt_addr, "FACP");

        if(fadt != 0) {
            printf("XSDT %#08x:\n", (uint32_t)rsdp -> xsdt_addr);
            dsdt = (acpi_hdr *) fadt->dsdt_addr;
            set_dsdt_field_value(dsdt, value);

            //also look in entries for qemu testing...
//            dsdt = (acpi_hdr *dsdt) find_xsdt_entry((acpi_xsdt *) rsdp->xsdt_addr, "DSDT");
//            set_dsdt_field_value(dsdt, value);
        }
    }

};
