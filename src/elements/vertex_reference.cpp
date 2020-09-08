#include "vertex_reference.hpp"
#include <sstream>

VertexReference::VertexReference(unsigned int v, unsigned int vt,
        unsigned int vn) : v(v), vt(vt), vn(vn)
{
}

bool VertexReference::operator==(VertexReference const &other)
{
    return v == other.v && vt == other.vt && vn == other.vn;
}

std::string const VertexReference::ToString() const
{
    std::stringstream ss;
    ss << "(" << v << ", " << vt << ", " << vn << ")";
    return ss.str();
}
