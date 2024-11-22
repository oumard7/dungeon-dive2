// stringManip.c
#include <ctype.h>
#include <string.h>
#include "stringManip.h"

void trim(char *str) {
    char *end;

    // Trim leading spaces
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return; // All spaces

    // Trim trailing spaces
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}

