//
// Created by jon on 3/23/19.
//

#include "acpi.h"
#include "aml.h"
#include "io.h"

bool addr_ok(uint64_t addr) {
    /* We can only handle 32-bit addresses for now... */
    return addr <= 0xffffffff;
};



acpi_hdr * find_rsdt_entry(acpi_rsdt *rsdt, char sig[4]) {
    int num_entries = (rsdt -> hdr.len - sizeof(rsdt -> hdr)) / 4;
    for(int i=0; i< num_entries; i++) {

        acpi_hdr * entry = (acpi_hdr *) rsdt -> entry[i];
        if(strncmp(entry -> sig, sig, 4) == 0) {
            return entry;
        }
    }
    return 0;
};

acpi_hdr * find_xsdt_entry(acpi_xsdt *xsdt, char sig[4]) {
    int num_entries = (xsdt -> hdr.len - sizeof(xsdt -> hdr)) / 8;
    for(int i=0; i< num_entries; i++) {
        acpi_hdr * entry = (acpi_hdr *) (uint32_t) xsdt -> entry[i];
        if(strncmp(entry -> sig, sig, 4) == 0) {
            return entry;
        }
    }
    return 0;
};


static uint8_t checksum_range(const void *start, uint32_t size) {
    const uint8_t *p = start;
    uint8_t csum = 0;

    while (size--)
        csum += *p++;

    return csum;
}
//
//static enum tbl_errs is_valid_table(const char name[4], void *ptr) {
//    acpi_hdr *hdr = ptr;
//
//    if (hdr->sig[0] == 0) {
//        printf("No signature for table %s\n", name);
//        return ERR_NOSIG;
//    }
//
//    if (hdr->len<10 || hdr->len>(1 << 20)) {
//        printf("Bad table size %d for %s\n", hdr->len, name);
//        /* Either insane or too large to dump */
//        return ERR_SIZE;
//    }
//
//    return checksum_range(hdr, hdr->len) == 0 ? ERR_NONE : ERR_CSUM;
//}

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

static void maybe_set_facs(acpi_fadt * fadt, acpi_facs * facs) {
    if( fadt != 0 ) {
        //overwrite only if the sig is missing
        if(strncmp((void  *)fadt -> facs_addr, "FACS", 4) != 0) {
            //overwrite the facs table.
            printf("Overwriting FACS table  @ %#08x\n", fadt -> facs_addr);
            memcpy((void *)fadt->facs_addr, facs, facs->len);
        } else {
            printf("FACS @ %#08x is good, skipping overwrite...\n", fadt -> facs_addr);
        }
    } else {
        printf("No FADT\n");
    }
}

void load_replacements(void) {
    printf("Loading replacement tables\n");
    acpi_rsdp * rsdp = find_rsdp();
    if(rsdp -> xsdt_addr != 0) {
        char * xsdt_data = load_file("acpi/xsdt.dat");
        if( xsdt_data != NULL) {
            memcpy((void *)(uint32_t)rsdp -> xsdt_addr, xsdt_data, file_length("acpi/xsdt.dat"));
        }
    }
}

void set_facs(acpi_facs * facs) {
    printf("Setting FACs table (maybe)....\n");
    acpi_rsdp * rsdp = find_rsdp();
    printf("RSDP %#08x\n", (uint32_t)rsdp);
    printf("RSDT %#08x\n", rsdp -> rsdt_addr);
    acpi_fadt * fadt = (acpi_fadt *) find_rsdt_entry((acpi_rsdt *)rsdp -> rsdt_addr, "FACP");
    printf("RSDT FADT/FACP %#08x\n", (uint32_t)fadt);
    maybe_set_facs(fadt, facs);

    if(rsdp -> xsdt_addr != 0) {
        printf("XSDT %#08x\n", (uint32_t)rsdp->xsdt_addr);
        fadt = (acpi_fadt *) find_xsdt_entry((acpi_xsdt *)(uint32_t)rsdp->xsdt_addr, "FACP");
        printf("XSDT FADT/FACP %#08x\n", (uint32_t) fadt);
        maybe_set_facs(fadt, facs);
    }
}