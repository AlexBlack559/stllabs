#include <string>

enum TokenKind { WORD, PUNCTUATION, SPACES };

class Token {
public:
    TokenKind kind;
    string value;
};

