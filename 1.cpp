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

// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>
// #include <string.h>

// #define MAX_IDENTIFIER_LENGTH 50
// #define MAX_PROGRAM_LENGTH 10000

// enum TokenType {
//     TOKEN_IDENTIFIER,
//     TOKEN_NUMBER,
//     TOKEN_OPERATOR,
//     TOKEN_KEYWORD,
//     TOKEN_SYMBOL,
//     TOKEN_UNKNOWN,
//     TOKEN_EOF
// };

// struct Token {
//     enum TokenType type;
//     char lexeme[MAX_IDENTIFIER_LENGTH];
// };

// bool is_valid_identifier_char(char c) {
//     return isalnum(c) || c == '_';
// }

// bool is_whitespace(char c) {
//     return c == ' ' || c == '\t' || c == '\n' || c == '\r';
// }

// bool is_keyword(const char *lexeme) {
//     const char *keywords[] = {"if", "else", "while", "for", "int", "float", "return"};
//     for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
//         if (strcmp(lexeme, keywords[i]) == 0) {
//             return true;
//         }
//     }
//     return false;
// }

// void analyze_program(const char program[], int program_length, int *num_tokens, int *num_keywords, int *num_identifiers, int *num_numbers, int *num_operators, int *num_symbols, int *num_unknowns) {
//     struct Token token;
//     int i = 0;
//     char identifiers[MAX_PROGRAM_LENGTH][MAX_IDENTIFIER_LENGTH] = {0};
//     char keywords[MAX_PROGRAM_LENGTH][MAX_IDENTIFIER_LENGTH] = {0};
//     char numbers[MAX_PROGRAM_LENGTH][MAX_IDENTIFIER_LENGTH] = {0};
//     char operators[MAX_PROGRAM_LENGTH][MAX_IDENTIFIER_LENGTH] = {0};
//     char symbols[MAX_PROGRAM_LENGTH][MAX_IDENTIFIER_LENGTH] = {0};
//     char unknowns[MAX_PROGRAM_LENGTH][MAX_IDENTIFIER_LENGTH] = {0};
//     int id_count = 0;
//     int kw_count = 0;
//     int num_count = 0;
//     int op_count = 0;
//     int sym_count = 0;
//     int unk_count = 0;

//     while (i < program_length) {
//         char c = program[i];

//         if (is_valid_identifier_char(c) && !isdigit(c)) {
//             int j = 0;
//             token.type = TOKEN_IDENTIFIER;
//             while (is_valid_identifier_char(c) && j < MAX_IDENTIFIER_LENGTH - 1) {
//                 token.lexeme[j++] = c;
//                 c = program[++i];
//             }
//             token.lexeme[j] = '\0';
//             if (is_keyword(token.lexeme)) {
//                 token.type = TOKEN_KEYWORD;
//                 strcpy(keywords[kw_count++], token.lexeme);
//             } else {
//                 strcpy(identifiers[id_count++], token.lexeme);
//             }
//         } else if (isdigit(c)) {
//             int j = 0;
//             token.type = TOKEN_NUMBER;
//             while ((isdigit(c) || c == '.') && j < MAX_IDENTIFIER_LENGTH - 1) {
//                 token.lexeme[j++] = c;
//                 c = program[++i];
//             }
//             token.lexeme[j] = '\0';
//             strcpy(numbers[num_count++], token.lexeme);
//         } else if (is_whitespace(c)) {
//             ++i;
//             continue;
//         } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>') {
//             token.type = TOKEN_OPERATOR;
//             token.lexeme[0] = c;
//             token.lexeme[1] = '\0';
//             strcpy(operators[op_count++], token.lexeme);
//             ++i;
//         } else if (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',') {
//             token.type = TOKEN_SYMBOL;
//             token.lexeme[0] = c;
//             token.lexeme[1] = '\0';
//             strcpy(symbols[sym_count++], token.lexeme);
//             ++i;
//         } else {
//             token.type = TOKEN_UNKNOWN;
//             token.lexeme[0] = c;
//             token.lexeme[1] = '\0';
//             strcpy(unknowns[unk_count++], token.lexeme);
//             ++i;
//         }
//     }

//     // Print identifiers
//     printf("Identifiers: ");
//     for (int j = 0; j < id_count; j++) {
//         printf("%s", identifiers[j]);
//         if (j != id_count - 1)
//             printf(", ");
//     }
//     printf("\n");

//     // Print keywords
//     printf("Keywords: ");
//     for (int j = 0; j < kw_count; j++) {
//         printf("%s", keywords[j]);
//         if (j != kw_count - 1)
//             printf(", ");
//     }
//     printf("\n");

//     // Print numbers
//     printf("Numbers: ");
//     for (int j = 0; j < num_count; j++) {
//         printf("%s", numbers[j]);
//         if (j != num_count - 1)
//             printf(", ");
//     }
//     printf("\n");

//     // Print operators
//     printf("Operators: ");
//     for (int j = 0; j < op_count; j++) {
//         printf("%s", operators[j]);
//         if (j != op_count - 1)
//             printf(", ");
//     }
//     printf("\n");

//     // Print symbols
//     printf("Symbols: ");
//     for (int j = 0; j < sym_count; j++) {
//         printf("%s", symbols[j]);
//         if (j != sym_count - 1)
//             printf(", ");
//     }
//     printf("\n");

//     // Print unknowns
//     printf("Unknowns: ");
//     for (int j = 0; j < unk_count; j++) {
//         printf("%s", unknowns[j]);
//         if (j != unk_count - 1)
//             printf(", ");
//     }
//     printf("\n");

//     // Print total number of tokens
//     *num_tokens = id_count + kw_count + num_count + op_count + sym_count + unk_count;

//     // Return counts
//     *num_keywords = kw_count;
//     *num_identifiers = id_count;
//     *num_numbers = num_count;
//     *num_operators = op_count;
//     *num_symbols = sym_count;
//     *num_unknowns = unk_count;
// }

// int main() {
//     const char program[] = 
//         "int main() {\n"
//         "    int x = 10;\n"
//         "    float y = 20.5;\n"
//         "    if (x > 5) {\n"
//         "        printf(\"x is greater than 5\\n\");\n"
//         "    } else {\n"
//         "        printf(\"x is less than or equal to 5\\n\");\n"
//         "    }\n"
//         "    return 0;\n"
//         "}";
//     int program_length = strlen(program);

//     // Analyze the program
//     int num_tokens, num_keywords, num_identifiers, num_numbers, num_operators, num_symbols, num_unknowns;
//     analyze_program(program, program_length, &num_tokens, &num_keywords, &num_identifiers, &num_numbers, &num_operators, &num_symbols, &num_unknowns);
//     printf("\nTotal number of tokens: %d\n", num_tokens);

//     return 0;
// }
