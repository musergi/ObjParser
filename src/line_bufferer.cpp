#include "line_bufferer.hpp"
#include <iostream>
#include <fstream>
#include <string>

LineBufferer::LineBufferer(const char *path) : path(path)
{
}

void LineBufferer::Buffer(LineBufferProcessor &lbp)
{
    std::ifstream file(path);
    std::string string;
    while (std::getline(file, string))
        lbp.Process(string.c_str());
}

void LineBufferer::LineBufferProcessor::Process(const char *line)
{
    std::cout << line << std::endl;
}
