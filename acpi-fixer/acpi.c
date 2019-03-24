//
// Created by jon on 3/15/19.
//

#include "acpi.h"
#include <stdbool.h>
#include "loader.h"

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
//
//void * find_field(char field[4], aml_opreg_hdr *region) {
//
//
//}
//
//
//
//void * find_sanv(acpi_hdr * dsdt, uint32_t len) {
//
//    aml_opreg_hdr sanv_hdr = {
//            .op = 0x5B,
//            .op_type = 0x80,
//            .name = "SANV",
//            .region_type = 0x00
//    };
//
//    bool found = false;
//    for(int i = 0; i < len; i++) {
//        void * current = (void * ) dsdt + i;
////
////        if(strncmp((char *)current, "SANV", 4) == 0 ) {
////            printf("Found reference to SANV!\n");
////        }
//
//        aml_opreg_hdr * h = (aml_opreg_hdr *) current;
//
////        if(h->op == 0x5B && h->op_type == 0x80) {
////            printf("Found a OpRegion(%x%x, %.4s, %#02x )\n", h -> op, h->op_type, h->name, h ->region_type);
////        }
//
//        if(memcmp(current, &sanv_hdr, sizeof(sanv_hdr)) == 0) {
//            //found a match!!!
//            aml_opreg * sanv = (aml_opreg *) current;
//            printf("Found %08x, len %04x\n", sanv->parm1, sanv->parm2);
//            return sanv;
//        }
//    }
//
// //   printf("Unable to find SANV\n");
//  return 0;
//}


static uint8_t checksum_range(const void *start, uint32_t size) {
    const uint8_t *p = start;
    uint8_t csum = 0;

    while (size--)
        csum += *p++;

    return csum;
}

static enum tbl_errs is_valid_table(const char name[4], void *ptr) {
    acpi_hdr *hdr = ptr;

    if (hdr->sig[0] == 0) {
        printf("No signature for table %s\n", name);
        return ERR_NOSIG;
    }

    if (hdr->len<10 || hdr->len>(1 << 20)) {
        printf("Bad table size %d for %s\n", hdr->len, name);
        /* Either insane or too large to dump */
        return ERR_SIZE;
    }

    return checksum_range(hdr, hdr->len) == 0 ? ERR_NONE : ERR_CSUM;
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

void dump_acpi(const char *prefix) {

    char filename[256];
    sprintf(filename, "%s_RSDP", prefix);

    acpi_rsdp *rsdp;

    rsdp = find_rsdp();
    printf("Dumping ACPI RSPD @ %x, rev=%d\n", rsdp, rsdp->rev);

    if(rsdp->rev == 0) {
        write_file(filename, rsdp, 20);
    } else {
        //v2
        write_file(filename, rsdp, 36);
    }
}
void parse_acpi(){

    dump_acpi("original");

    acpi_rsdp *rsdp;

    rsdp = find_rsdp();
    printf("Found ACPI RSPD @ %x, rev=%d\n", rsdp, rsdp->rev);

    int len = 20;
    if( rsdp->rev > 0 ) {
        len = rsdp -> len;
    }

    fix_table("RSDP", rsdp, len);

    if(rsdp->rev == 0) {
        printf("Version 1 acpi\n");
        acpi_rsdt * rsdt = (acpi_rsdt *)rsdp -> rsdt_addr;
        is_valid_table("RSDT", rsdt);
        fix_table(rsdt -> hdr.sig, rsdt, rsdt -> hdr.len);
        fix_rsdt_entries(rsdt, rsdt->entry);
    } else {
        printf("Version 2 acpi\n");
        acpi_xsdt * xsdt = (acpi_xsdt *)rsdp -> xsdt_addr;
        is_valid_table("XSDT", xsdt);
        fix_table(xsdt -> hdr.sig, xsdt, xsdt -> hdr.len);
        fix_xsdt_entries(xsdt, xsdt->entry);
       }
}


void fix_rsdt_entries(acpi_rsdt * rsdt) {
    int num_entries = (rsdt -> hdr.len - sizeof(rsdt -> hdr)) / 4;

    printf("%.4s: %d Entries\n", rsdt -> hdr.sig, num_entries);
    int ssdt = 1;

    for(int i = 0; i< num_entries; i++) {
        acpi_hdr *h = (acpi_hdr *) rsdt -> entry[i];
        printf("\t%.4s\t%#08x to %#08x\t(%d)\n", h->sig, (uint32_t)h, ((uint32_t)h + h->len), h->len);
        fix_table(h->sig, h, h->len);


        if(memcmp(h->sig, "FACP", 4) ==0) {
            acpi_fadt * fadt = (acpi_fadt *) h;
            acpi_facs * facs = fadt -> facs_addr;
            fix_table("FACS", facs, -1);

            acpi_hdr * dsdt = (acpi_hdr *) fadt -> dsdt_addr;
            printf("\t\tDSDT\t%#08x to %#08x\t(%d)\n", (uint32_t)facs, (uint32_t)(dsdt + dsdt->len), dsdt->len);

            fix_table("DSDT", dsdt,  dsdt -> len);
           // find_sanv(dsdt, dsdt -> len);
        }
        if(memcmp(h->sig, "SSDT", 4)==0) {
            char name[6];
            sprintf(name, "SSDT%d", ssdt);
            fix_table(name, h, h -> len);
        }
        if(memcmp(h->sig, "DSDT", 4)==0) {
            //find_sanv(h, h -> len);
        }
    }
}

void fix_xsdt_entries(acpi_xsdt * xsdt) {
    int num_entries = (xsdt -> hdr.len - sizeof(xsdt -> hdr)) / 8;

    printf("%.4s: %d Entries\n", xsdt -> hdr.sig, num_entries);

    int ssdt = 1;

    for(int i = 0; i< num_entries; i++) {
        acpi_hdr *h = (acpi_hdr *) xsdt -> entry[i];
        char name[6];
        sprintf(name, "%.4s", h->sig);

        printf("\t%s\t%#08x to %#08x\t(%d)\n", name, (uint32_t)h, ((uint32_t)h + h->len), h->len);
        fix_table(h->sig, h, h->len);

        if(memcmp(h->sig, "FACP", 4) ==0  ){
            acpi_fadt * fadt = (acpi_fadt *) h;
            acpi_facs * facs = fadt -> facs_addr;
            printf("\t\tFACS\t%#08x to %#08x\t(%d)\n", (uint32_t)facs, (uint32_t)(facs + 0x60), 64);
            fix_table("FACS", facs, -1);

            acpi_hdr * dsdt = (acpi_hdr *) fadt -> dsdt_addr;
            printf("\t\tDSDT\t%#08x to %#08x\t(%d)\n", (uint32_t)facs, (uint32_t)(dsdt + dsdt->len), dsdt->len);

            fix_table("DSDT", dsdt,  dsdt -> len);
            //find_sanv(dsdt, dsdt -> len);
        }



        if(memcmp(h->sig, "SSDT", 4)==0) {
            sprintf(name, "SSDT%d", ssdt);
            fix_table(name, h, h -> len);
            ssdt += 1;
        }
    }
}

bool confirm(char *message) {

    char buffer[256];
    printf("%s\n", message);
    fgets(buffer, 256, stdin);
    return strncmp(buffer, "y", 1)==0;
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

//Possible fix up the table...
void fix_table(char * name, void *ptr, uint32_t len) {
    char filename[256];
    sprintf(filename, "%s/%s.aml", base_directory, name);

    int length = file_length(filename);

    if (length > 0) {
        //  printf("Fixup file %s exists for %.4s\n", filename, name);
        if (length > len && len > 0) {
            printf("Warning!: fixup length %d is greater than original table size: %d, skipping fixup.\n", length, len);
            return;
        }

        char *fixup_data = load_file(filename);

        if (confirm("Overwrite file?")) {
            memcpy(ptr, fixup_data, length);
            printf("Overwrote ACPI table %.4s\n", name);

        } else {
            printf("Skipping overwite of ACPI table %.4s\n", name);

        }
        //otherwise overwrite!
        return;
    }
}
//    else {
//        printf("No fixup file for %.4s\n", name);
//        return;
//    }


