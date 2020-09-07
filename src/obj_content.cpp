#include "obj_content.hpp"
#include <sstream>
#include "line_bufferer.hpp"
#include "obj_line_buffer_processor.hpp"

ObjContent::ObjContent(const char *path)
{
    LineBufferer line_bufferer(path);
    ObjLineBufferProcessor lbp(this);
    line_bufferer.Buffer(lbp);
}

void ObjContent::AddGeometricVertex(GeometricVertex const &geometric_vertex)
{
    geometric_vertices.push_back(geometric_vertex);
}

void ObjContent::AddTextureVertex(TextureVertex const &texture_vertex)
{
    texture_vertices.push_back(texture_vertex);
}

void ObjContent::AddVertexNormal(VertexNormal const &vertex_normal)
{
    vertex_normals.push_back(vertex_normal);
}

void ObjContent::AddFace(Face const &face)
{
    faces.push_back(face);
}

GeometricVertex const &ObjContent::GetGeometricVertex(unsigned int ref) const
{
    return geometric_vertices[ref - 1];
}

TextureVertex const &ObjContent::GetTextureVertex(unsigned int ref) const
{
    return texture_vertices[ref - 1];
}

VertexNormal const &ObjContent::GetVertexNormal(unsigned int ref) const
{
    return vertex_normals[ref - 1];
}

Face const &ObjContent::GetFace(unsigned int index) const
{
    return faces[index];
}

unsigned int ObjContent::GetFaceCount() const
{
    return faces.size();
}

std::string const ObjContent::ToString() const
{
    std::stringstream ss;
    ss << "Geometric Vertices: " << GetVectorString(geometric_vertices) << std::endl; 
    ss << "Texture Vertices: " << GetVectorString(texture_vertices) << std::endl;
    ss << "Vertex Normals: " << GetVectorString(vertex_normals) << std::endl;
    ss << "Faces: " << GetVectorString(faces) << std::endl;
    return ss.str();
}

template <typename T>
std::string const ObjContent::GetVectorString(std::vector<T> const &vector) const
{
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i != 0)
            ss << ", ";
        ss << vector[i].ToString();
    }
    ss << "]";
    return ss.str();
}
