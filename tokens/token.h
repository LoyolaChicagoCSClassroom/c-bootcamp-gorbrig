
#ifndef TOKEN_H
#define TOKEN_H

enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD
};

struct token_t {
    enum token_type_t type;
    char *text;
};

struct token_t *create_token(enum token_type_t type, const char *text);
void destroy_token(struct token_t *token);

#endif // TOKEN_H
