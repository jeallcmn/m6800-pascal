#include <stdio.h>
#include <stdlib.h>
#include "loader.h"
#include "acpi.h"

int main(const int argc, const char *args[]) {
    parse_acpi();
    return 0;
}
