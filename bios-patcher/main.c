#include <stdio.h>
#include "acpi.h"
#include "aml.h"
#include "io.h"

acpi_facs facs = {
        .sig = "FACS",
        .len = 0x40,
        .version = 0x02,
};

// field_value xbas = {
//     .region = "SANV",
//     .field = "XBAS",
//     .field_location = 0xC8 + 13,
//     .offset_value = 0x30000
// };

// field_value aslb = {
//     .region = "SANV",
//     .field = "ASLB",
//     .field_location = 4,
//     .offset_value = 0x30000
// };

// field_value nvha = {
//     .region = "SANV",
//     .field = "NVHA",
//     .field_location = 0xC8 + 24,
//     .offset_value = 0x60000
// };



int main(void) {

    set_facs( &facs);

    char *gnvs = load_file("optimus/gnvs.bin");
    char *sanv = load_file("optimus/sanv.bin");

    memcpy((void *)0xCA7FCC18,gnvs, 0x02B4);
    memcpy((void *)0xCA7FDC18, sanv, 0x016D);
//    set_field_value(&xbas);
//    set_field_value(&aslb);
//    set_field_value(&nvha);
    return 0;
}