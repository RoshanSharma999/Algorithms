#include <stdio.h>
#include <string.h>

#define MAX 256

// Function to build the bad character shift table
void buildShiftTable(char *pattern, int shiftTable[]) {
    int m = strlen(pattern);
    for (int i = 0; i < MAX; i++) {
        shiftTable[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

// Function to perform Horspool pattern matching
int horspoolSearch(char *text, char *pattern) {
    int shiftTable[MAX];
    int n = strlen(text);
    int m = strlen(pattern);
    buildShiftTable(pattern, shiftTable);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i += shiftTable[(unsigned char)text[i]];
        }
    }
    return -1;
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0;

    int position = horspoolSearch(text, pattern);

    if (position != -1) {
        printf("Pattern found at position: %d\n", position);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
