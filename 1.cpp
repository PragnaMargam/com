#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Function to check if a given string is a keyword or an identifier
void keyword(char str[10]) {
    if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 ||
        strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 ||
        strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 ||
        strcmp("case", str) == 0) {
        printf("\n%s is a keyword", str);
    } else {
        printf("\n%s is an identifier", str);
    }
}

int main() {
    FILE *f1, *f2, *f3; // File pointers for input, identifiers, and special characters
    char c, str[10], st1[10]; // Variables for character and strings
    int num[100], lineno = 0, tokenvalue = 0; // Variables for numbers and line count
    int i = 0, j = 0, k = 0; // Loop counters

    printf("\nEnter the C program:\n");

    // Open a file to store input from user
    f1 = fopen("input", "w");
    while ((c = getchar()) != EOF) { // Read input from user until EOF
        putc(c, f1); // Write to the input file
    }
    fclose(f1); // Close the input file

    // Reopen the input file in read mode
    f1 = fopen("input", "r");
    // Open files for identifiers and special characters
    f2 = fopen("identifier", "w");
    f3 = fopen("specialchar", "w");

    // Analyze the input for different tokens
    while ((c = getc(f1)) != EOF) {
        if (isdigit(c)) { // Check if the character is a digit
            tokenvalue = c - '0';
            c = getc(f1);
            while (isdigit(c)) { // Read full number
                tokenvalue = tokenvalue * 10 + c - '0';
                c = getc(f1);
            }
            num[i++] = tokenvalue; // Store the number
            ungetc(c, f1); // Push back the last read character
        } else if (isalpha(c)) { // Check if the character is a letter
            putc(c, f2); // Write to the identifier file
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$') {
                putc(c, f2);
                c = getc(f1);
            }
            putc(' ', f2); // Separate identifiers with a space
            ungetc(c, f1); // Push back the last read character
        } else if (c == ' ' || c == '\t') { // Ignore spaces and tabs
            continue;
        } else if (c == '\n') { // Count new lines
            lineno++;
        } else {
            putc(c, f3); // Write special characters
        }
    }

    fclose(f2); // Close identifier file
    fclose(f3); // Close special character file
    fclose(f1); // Close input file

    printf("\nThe numbers in the program are: "); // Display numbers found
    for (j = 0; j < i; j++) {
        printf("%d,", num[j]);
    }
    printf("\n");

    // Reopen the identifier file to identify keywords and identifiers
    f2 = fopen("identifier", "r");
    k = 0;
    printf("The keywords and identifiers are: ");
    while ((c = getc(f2)) != EOF) {
        if (c != ' ') { // Continue reading the identifier
            str[k++] = c;
        } else {
            str[k] = '\0'; // Null-terminate the string
            keyword(str); // Check if it's a keyword or identifier
            k = 0; // Reset the index for the next identifier
        }
    }

    fclose(f2); // Close the identifier file

    // Display special characters
    f3 = fopen("specialchar", "r");
    printf("\nSpecial characters are: ");
    while ((c = getc(f3)) != EOF) {
        printf("%c", c); // Print special characters
    }
    printf("\n");
    fclose(f3); // Close special character file

    // Display the total number of lines in the input program
    printf("Total number of lines are: %d\n", lineno);

    return 0; // End of program
}
