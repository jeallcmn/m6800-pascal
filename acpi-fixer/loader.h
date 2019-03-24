//
// Created by jon on 3/15/19.
//

#ifndef ACPI_FIX_LOADER_H
#define ACPI_FIX_LOADER_H

#include <inttypes.h>

int file_length(const char *name);
char * load_file(const char *name);


void write_file(const char *name, void *data, uint32_t len);

#endif //ACPI_FIX_LOADER_H
