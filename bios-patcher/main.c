#include <stdio.h>
#include "acpi.h"
#include "aml.h"
#include "io.h"

acpi_facs facs = {
        .sig = "FACS",
        .len = 0x40,
        .version = 0x02,
};

int main(void) {

    set_facs( &facs);

    char *gnvs = load_file("optimus/gnvs.bin");
    char *sanv = load_file("optimus/sanv.bin");
    char *ppmt = load_file("optimus/ppmt.bin");

    memcpy((void *)0xCA7FCC18, gnvs, 0x02B4);
    memcpy((void *)0xCA7FDC18, sanv, 0x016D);
    memcpy((void *)0xCA7FFE18, ppmt, 0x003A);
//    set_field_value(&xbas);
//    set_field_value(&aslb);
//    set_field_value(&nvha);
    return 0;
}