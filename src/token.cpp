#include <iostream>
#include "libs/token.hh"
#include <unordered_map>

Token::Token(TokenTypes type, std::string literal)
{
    _literal = literal;
    _type = type;
}

Tokenizer::Tokenizer()
{
  
};

void Tokenizer::makeReservedKeyWords()
{
    _reservedKeyWord["int"] = "int";
}

std::vector<Token> Tokenizer::tokenize(std::string input)
{
    _input = input;
    std::vector<Token> tokens;
    makeReservedChars();
    makeReservedKeyWords();
    if(input.length() > 2)
    {
        next = input[1];
        nextIdx = 1;
    }
    else
    {
        next = '\0';
        nextIdx = 0;
    }

    current = input[0];

    while(current != EOF && current != '\0' )
    {
        skipSpace();
        if(isdigit(current))
        {
            tokens.push_back(Token(int_val, getNum()));
        }
        else if(current == '=')
        {
            if(next == '=')
            {
                tokens.push_back(Token(equals, "=="));
                moveChar();
                // if moveChar() isnt called we will get
                // an extra token with the value of assign and "="
            }
            else
                tokens.push_back(Token(assign, "="));
        }
        else if(current == ';')
        {
            tokens.push_back(Token(semicolon, ";"));
        }
        else if(isspace(current))
            skipSpace(); 
        else
        {
            tokens.push_back(getValue());
        }
        moveChar();
    }

    return tokens;
}

void Tokenizer::makeReservedChars()
{
    _reservedLetters['='] = '=';
    _reservedLetters[';'] = ';';
}

bool Tokenizer::isNextReservedChar()
{
    if(_reservedLetters.find(next) != _reservedLetters.end())
        return true;
    return false;
}

Token Tokenizer::getValue()
{
    std::stringstream val;
    val << current;
    while(!isNextReservedChar() && !isspace(next) && current != '\0')
    {
        moveChar();
        val << current;
    }
    moveChar(); 
    if(_reservedKeyWord[val.str()] == val.str())
    {
        std::string stringVal = val.str();

        if(stringVal == "int")
            return Token(int_type, stringVal);
    }
    return Token(illegal, "illegal Token");
}

std::string Tokenizer::getNum()
{
    std::stringstream num;

    do
    {
        num << current;
        moveChar();
    }while(isdigit(current) && isdigit(next));

    return num.str();
}

void Tokenizer::skipSpace()
{
    while(isspace(current))
    {
        moveChar();
    }
}

void Tokenizer::moveChar()
{
    current = next;
    idx++;
    if(nextIdx + 1 < _input.length())
    {
        nextIdx++;
        next = _input[nextIdx];
    }
    else
        next = '\0';
    
}



