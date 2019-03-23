//
// Created by jon on 3/23/19.
//

#include "acpi.h"
#include <stdbool.h>

const char base_directory[] = "/acpi";

static inline bool addr_ok(uint64_t addr) {
    /* We can only handle 32-bit addresses for now... */
    return addr <= 0xffffffff;
}

enum tbl_errs {
    ERR_NONE,            /* No errors */
    ERR_CSUM,            /* Invalid checksum */
    ERR_SIZE,            /* Impossibly large table */
    ERR_NOSIG            /* No signature */
};


void set_field_value(char region[4], char field[4], uint32_t value) {
    printf("Setting %.4s.%.4s field to %#08x", region, field, value);
}
