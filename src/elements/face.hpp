#pragma once

#include <vector>
#include <string>
#include "vertex_reference.hpp"

class Face
{
private:
    std::vector<VertexReference> vertex_references;
public:
    void AddVertex(VertexReference const &vertex_reference);
    VertexReference const &GetVertex(unsigned int index) const;
    unsigned int GetVertexCount() const;
    std::string const ToString() const;
};
