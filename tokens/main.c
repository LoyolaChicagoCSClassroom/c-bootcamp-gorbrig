#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "token.h"

int main() {
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t linelen;

    // Read input line by line
    while ((linelen = getline(&line, &bufsize, stdin)) != -1) {
        // Tokenize the input line
        char *token_str = strtok(line, " ");
        while (token_str != NULL) {
            // Determine token type
            enum token_type_t token_type;
            if (isdigit((unsigned char)token_str[0])) {
                token_type = NUMBER;
            } else if (strchr("+-*/", token_str[0]) != NULL) {
                token_type = OPERATOR;
            } else if (strchr(":", token_str[0]) != NULL || strchr(";", token_str[0]) != NULL) {
                token_type = SYMBOL;
            } else {
                token_type = WORD;
            }

            // Create and print token
            struct token_t *token = create_token(token_type, token_str);
            printf("Token: Type: %s, Text %s\n",token_type_to_string (token_type),token->text);
            
            // Free token memory
            destroy_token(token);

            // Get next token
            token_str = strtok(NULL, " ");
        }
    }

    free(line);
    return 0;
}
