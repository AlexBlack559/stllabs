#include <string>
#include <vector>

using namespace std;

enum TokenKind { WORD, PUNCTUATION, SPACES };

class Token {
public:
    Token(TokenKind kind, string value) {
        this->kind = kind;
        this->value = value;
    }
    TokenKind kind;
    string value;
};

class Tokenizer {
public:
    vector<Token> tokenize(string text);
};
