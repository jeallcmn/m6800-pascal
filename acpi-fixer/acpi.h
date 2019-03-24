//
// Created by jon on 3/15/19.
//

#ifndef ACPI_FIX_ACPI_H
#define ACPI_FIX_ACPI_H

#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct acpi_rsdp {
    char  magic[8];		/* "RSD PTR " */
    uint8_t  csum;
    char     oemid[6];
    uint8_t  rev;
    uint32_t rsdt_addr;
    uint32_t len;
    uint64_t xsdt_addr;
    uint8_t  xcsum;
    uint8_t  rsvd[3];
} acpi_rsdp;

typedef struct acpi_hdr {
    char     sig[4];		/* Signature */
    uint32_t len;
    uint8_t  rev;
    uint8_t  csum;
    char     oemid[6];
    char     oemtblid[8];
    uint32_t oemrev;
    uint32_t creatorid;
    uint32_t creatorrev;
} acpi_hdr;

typedef struct acpi_rsdt {
    acpi_hdr hdr;
    uint32_t entry[0];
} acpi_rsdt;

typedef struct acpi_xsdt {
    acpi_hdr hdr;
    uint64_t entry[0];
} acpi_xsdt;


typedef struct acpi_fadt {
    acpi_hdr hdr;
    uint32_t facs_addr;
    uint32_t dsdt_addr;
    uint8_t rsvd;
    uint8_t profile;
    uint8_t scsint[2];
    uint32_t smi_cmd_adr;
    uint8_t acpi_enable;
    uint8_t acpi_disable;
    uint8_t s4bios_req;
    uint8_t pstate_cnt;
    uint8_t pm1a_evt_blk;
    uint8_t pm1b_evt_blk;
    uint32_t pm1a_cnt_blk;
    uint32_t pm1b_cnt_blk;
    uint32_t pm_tmr_blk;
    uint32_t gpe0_blk;
    uint32_t gpe1_blk;
    uint8_t pm1_evt_len;
    uint8_t pm1_cnt_len;
    uint8_t pm2_cnt_len;
    uint8_t pm_tmr_len;
    uint8_t gpe0_blk_len;
    uint8_t gpe1_blk_len;
    uint8_t gpe1_base;
    uint8_t cst_cnt;
    uint8_t p_lvl2_lat[2];
    uint8_t p_lvl3_lat[2];
    uint8_t flush_size[2];
    uint8_t flush_stride[2];
    uint8_t duty_offset;
    uint8_t duty_width;
    uint8_t day_alrm;
    uint8_t mon_alrm;
    uint8_t centruy;
    uint8_t iapc_boot_arch[2];
    uint8_t reserved2;
    uint32_t flags;
    uint32_t reset_reg[3];
    uint8_t reset_value;
    uint8_t reserved3[3];
    uint32_t x_facs[2];
    uint32_t x_dsdt[2];
    uint32_t x_pm1a_evt_blk[2];
    uint32_t x_pm1b_evt_blk[2];
    uint32_t x_pm1a_cnt_blk[2];
    uint32_t x_pm1b_cnt_blk[2];
    uint32_t x_pm2_cnt_blk[2];
    uint32_t x_pm_tmr_blk[2];
    uint32_t x_gpe0_blk[2];
    uint32_t x_gpe1_blk[2];
    uint32_t sleep_control_reg[2];
    uint32_t sleep_status_reg[2];
} acpi_fadt;

typedef struct acpi_facs {
    char     sig[4];     /* Signature */
    uint32_t len;
    uint32_t hw_sig;
    uint32_t fw_waking_vector;
    uint32_t global_lock;
    uint32_t flags;
    uint64_t x_fw_waking_vector;
    uint8_t  version;
    char  reserved[31];
} acpi_facs;

//
//typedef struc aml_field_op_hdr {
//    uint8_t op;
//    uint8_t op_type;
//    uint16_t field_length;
//    char name[4];
//    uint8_t fielSd_flags;
//    void * field_list;
//};
//
//typedef struct aml_op_hdr {
//    uint8_t op;
//    uint8_t op_type;
//    char name[4];
//    uint8_t region_type;
//} aml_op_hdr;
//
//typedef struct aml_opreg {
//    aml_opreg_hdr hdr;
//    uint8_t parm1_type;
//    uint32_t parm1;
//    uint8_t parm2_type;
//    uint16_t parm2;
//    aml_field_op_hdr field_op;
//} aml_opreg;

void parse_acpi(void);

acpi_rsdp *find_rsdp(void);

#endif //ACPI_FIX_ACPI_H
