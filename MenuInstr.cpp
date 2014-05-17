#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdio>

/// Extern functions to save file space, MessageNameSpace became to large of a file

void Instructions()
{
    std::ifstream Instr("Instructions.txt");
    
    std::vector<std::string> tokens;
    std::istream_iterator<std::string> it(Instr), end;

    std::for_each(it, end, [&] (const std::string& str)
    {
        std::cout << str << " ";
        if (str == "\\n")
            tokens.push_back("\n");
        else
            tokens.push_back(str);
    });

    std::ofstream out("temp.txt"); // create a temporary file
    // copy vector to file and rename
    std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<std::string>(out));
    std::rename("temp.txt", "Instructions.txt");
};

void Credits()
{
    std::ifstream credit("Credits.txt");
    
    std::vector<std::string> tokens;
    std::istream_iterator<std::string> it(credit), end;

    std::for_each(it, end, [&] (const std::string& str)
    {
        std::cout << str << " ";
        if (str == "\\n")
            tokens.push_back("\n");
        else
            tokens.push_back(str);
    });

    std::ofstream out("temp.txt"); // create a temporary file
    // copy vector to file and rename
    std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<std::string>(out));
    std::rename("temp.txt", "Credits.txt");
};