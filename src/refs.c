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
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}