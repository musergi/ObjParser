#include "texture_vertex.hpp"
#include <sstream>

TextureVertex::TextureVertex(float u, float v) : u(u), v(v), w(0.0f)
{
}


TextureVertex::TextureVertex(float u, float v, float w) : u(u), v(v), w(w)
{
}

std::string const TextureVertex::ToString() const
{
    std::stringstream ss;
    ss << "(" << u << ", " << v;
    if (w != 0.0)
        ss << ", " << w;
    ss << ")";
    return ss.str();
}
