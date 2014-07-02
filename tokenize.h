#define STACK_SIZE 4096
#define GROWTH_SIZE 512

typedef char* source_t;

typedef enum {
  SYMBOL = 0,
  IDENTIFIER = 1,
  INTEGER = 2,
  FLOATING = 3,
  QUOTE = 4,
  WSPACE = 5,
  PAREN = 6 ,
  EMPTY = 7
} tok_t;

typedef union {
    char *symbol;
    char *identifier;
    char *integer;
    char *floating;
    char *parenthesis;
    bool quote;
    bool whitespace;
    bool null_token;
} token_val_t;

typedef struct {
  tok_t token_type;
  token_val_t token;
} token_t;

typedef struct {
  size_t length; /* Number of current elements */
  size_t max_length; /* Maximum length of the stack */
  token_t *tokens;
} token_stream;

bool push_token(token_stream*, token_t);

bool pop_token(token_stream*);

token_t peek_token(token_stream*);

token_stream tokenize(source_t, uint32_t, const uint32_t);

bool release_tokens(token_stream*);

static uint32_t match_int(source_t, uint32_t, const uint32_t);
static uint32_t match_float(source_t, uint32_t, const uint32_t);
static uint32_t match_identifier(source_t, uint32_t, const uint32_t);
static uint32_t match_symbol(source_t, uint32_t, const uint32_t);