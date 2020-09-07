#include "vertex_reference.hpp"
#include <sstream>

VertexReference::VertexReference(unsigned int v, unsigned int vt,
        unsigned int vn) : v(v), vt(vt), vn(vn)
{
}

std::string const VertexReference::ToString() const
{
    std::stringstream ss;
    ss << "(" << v << ", " << vt << ", " << vn << ")";
    return ss.str();
}
