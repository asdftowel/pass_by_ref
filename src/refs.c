/*
    refstr - prints random string using quirky methods
    Copyright (C) 2025  asdftowel

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define THE_STRING "This string contains some words"

static char **odd_a(char **in_str, size_t const * const str_siz) {
    size_t i;
    for (i = 0; i < *str_siz; i += 2) {
        (*in_str)[i] = 'a';
    }
    return in_str;
}

static char **rand_lower(char **in_str, size_t const * const str_siz) {
    size_t i;
    for (i = 0; i < *str_siz; ++i) {
        (*in_str)[i] = (char)(rand() % 26 + 97); /* -Wconversion */
    }
    return in_str;
}

int main(void) {
    char *example = malloc(sizeof THE_STRING);
    size_t len;
    if (!example) {
        return EXIT_FAILURE;
    }
    len = strlen(memcpy(example, THE_STRING, sizeof THE_STRING));
    srand((unsigned int)time(NULL)); /* -Wconversion */
    if (puts(*odd_a(rand_lower(&example, &len), &len)) == EOF) {
        free(example);
        return EXIT_FAILURE;
    }
    free(example);
    return EXIT_SUCCESS;
}
