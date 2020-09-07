#pragma once

#include "vertex_data.hpp"

class GeometricVertex : public VertexData
{
public:
    float x, y, z, w;
    GeometricVertex(float x, float y, float z);
    GeometricVertex(float x, float y, float z, float w);
    std::string const ToString() const;
};
