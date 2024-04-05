#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *extract_substring(char *sentence, int start, int end) {
    if (start >= end || start < 0 || end >= strlen(sentence)) {
        return NULL; // Handle invalid indices or empty substring
    }

    int sub_len = end - start + 1;
    char *substring = (char *)malloc(sub_len * sizeof(char) + 1); // Allocate memory for substring + null terminator

    if (substring == NULL) {
        return NULL; // Handle memory allocation failure
    }

    int i = 0;
    while (start < end) {
        substring[i++] = sentence[start++];
    }

    substring[i] = '\0'; // Add null terminator

    return substring;
}

int main() {
    char sentence[] = "This is a sample sentence";
    int start = 5;
    int end = 11;

    char *substring = extract_substring(sentence, start, end);

    if (substring != NULL) {
        printf("Extracted substring: %s\n", substring);
        free(substring); // Free allocated memory
    } else {
        printf("Error: Invalid indices or memory allocation failure\n");
    }

    return 0;
}
