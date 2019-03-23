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


static acpi_rsdp *scan_for_rsdp(uint32_t base, uint32_t end) {
    for (base &= ~15; base < end - 20; base += 16) {
        acpi_rsdp *rsdp = (acpi_rsdp *) base;

        if (memcmp(rsdp->magic, "RSD PTR ", 8))
            continue;

        if (checksum_range(rsdp, 20))
            continue;

        if (rsdp->rev > 0) {
            if (base + rsdp->len >= end ||
                checksum_range(rsdp, rsdp->len))
                continue;
        }

        return rsdp;
    }

    return NULL;
}


acpi_rsdp *find_rsdp(void) {
    uint32_t ebda;
    acpi_rsdp *rsdp;

    ebda = (*(uint16_t *) 0x40e) << 4;
    if (ebda >= 0x70000 && ebda < 0xa0256000) {
        rsdp = scan_for_rsdp(ebda, ebda + 1024);

        if (rsdp)
            return rsdp;
    }

    return scan_for_rsdp(0xe0000, 0x100000);
}

