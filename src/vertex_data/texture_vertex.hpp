#pragma once

#include "vertex_data.hpp"

class TextureVertex : public VertexData
{
public:
    float u, v, w;
    TextureVertex(float u, float v);
    TextureVertex(float u, float v, float w);
    std::string const ToString() const;
};
