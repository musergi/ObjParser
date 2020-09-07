#include "vertex_normal.hpp"
#include <sstream>

VertexNormal::VertexNormal(float i, float j, float k) : i(i), j(j), k(k)
{
}

std::string const VertexNormal::ToString() const
{
    std::stringstream ss;
    ss << "(" << i << ", " << j << ", " << k << ")";
    return ss.str();
}
