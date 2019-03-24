#include <stdio.h>
#include "acpi.h"

int main(void) {
    set_field_value("SANV", "XBAS", 0x00000020);
    return 0;
}