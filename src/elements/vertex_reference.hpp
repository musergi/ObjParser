#pragma once

#include <string>

class VertexReference
{
public:
    unsigned int v, vt, vn;
    VertexReference(unsigned int v, unsigned int vt, unsigned int vn);
    std::string const ToString() const;
};
