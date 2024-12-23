#include <iostream>
#include <sstream>
#include <fstream>
#include "./libs/token.hh"
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    if(argc < 2)
    {
        std::cerr << "Not enough arguments given \n";
        return EXIT_FAILURE;
    }

    std::stringstream inputString;
    std::ifstream inputFile(argv[1], std::ios::in);
    std::string lineStr;
    while (getline(inputFile, lineStr))
    {
        inputString << lineStr;
    }
    Tokenizer *tokenizer = new Tokenizer();
    std::vector<Token> tks = tokenizer->tokenize(inputString.str());

    for(int i = 0; i<tks.size();i++)
    {
        std::cout << tks[i]._literal << std::endl;
        
    }


    return EXIT_SUCCESS;
}
