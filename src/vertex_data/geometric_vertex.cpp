#include "geometric_vertex.hpp"
#include <sstream>

GeometricVertex::GeometricVertex(float x, float y, float z)
    : x(x), y(y), z(z), w(1.0f)
{
}

GeometricVertex::GeometricVertex(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
{
}

std::string const GeometricVertex::ToString() const
{
    std::stringstream ss;
    ss << "(" << x << ", " << y << ", " << z;
    if (w != 1.0)
        ss << ", " << w;
    ss << ")";
    return ss.str();
}
