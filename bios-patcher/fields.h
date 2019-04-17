

#ifndef BIOS_PATCHER_FIELDS_H
#define BIOS_PATCHER_FIELDS_H


#include "aml.h"
#include "acpi.h"

void set_dsdt_field_value(acpi_hdr * dsdt, field_value * value);
void set_field_value(field_value * value);

#endif //BIOS_PATCHER_FIELDS_H