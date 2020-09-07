#include "face.hpp"
#include <sstream>

void Face::AddVertex(VertexReference const &vertex_reference)
{
    vertex_references.push_back(vertex_reference);
}

VertexReference const &Face::GetVertex(unsigned int index) const
{
    return vertex_references[index];
}

unsigned int Face::GetVertexCount() const
{
    return vertex_references.size();
}

std::string const Face::ToString() const
{
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < vertex_references.size(); i++)
    {
        if (i != 0)
            ss << ", ";
        ss << vertex_references[i].ToString();
    }
    ss << "]";
    return ss.str();
}
