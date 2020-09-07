#pragma once

#include "vertex_data.hpp"

class VertexNormal : public VertexData
{
public:
    float i, j, k;
    VertexNormal(float i, float j, float k);
    std::string const ToString() const;
};
