#pragma once

#include <vector>
#include <sstream>
#include <unordered_map>

enum TokenTypes
{
    int_val,
    int_type,
    assign,
    equals,
    semicolon,
    illegal
};

class Token{

private:
    
public:
    TokenTypes _type;
    std::string _literal;
    Token(TokenTypes type, std::string literal);

    void spit();
};

class Tokenizer{

private:
    std::unordered_map<char, char> _reservedLetters;
    std::unordered_map<std::string, std::string> _reservedKeyWord;
    std::string _input;
    char current, next;
    void moveChar();
    std::string getNum();
    unsigned long long idx, nextIdx;
    void skipSpace();
    bool isNextReservedChar();
    void makeReservedChars();
    void makeReservedKeyWords();
    Token getValue(); // TODO: give this method a better name
public:
    Tokenizer();
    std::vector<Token> tokenize(std::string input);
};
