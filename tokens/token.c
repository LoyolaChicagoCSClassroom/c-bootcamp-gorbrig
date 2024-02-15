#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

struct token_t *create_token(enum token_type_t type, const char *text) {
    struct token_t *token = malloc(sizeof(struct token_t));
    if (token) {
        token->type = type;
        token->text = strdup(text);
    }
    return token;
}

void destroy_token(struct token_t *token) {
    if (token) {
        free(token->text);
        free(token);
    }
}
