#pragma once

#include <vector>
#include <string>
#include "vertex_data/vertex_data.hpp"
#include "vertex_data/geometric_vertex.hpp"
#include "vertex_data/texture_vertex.hpp"
#include "vertex_data/vertex_normal.hpp"
#include "elements/face.hpp"

class ObjContent
{
private:
    std::vector<GeometricVertex> geometric_vertices;
    std::vector<TextureVertex> texture_vertices;
    std::vector<VertexNormal> vertex_normals;
    std::vector<Face> faces;

public:
    ObjContent(const char *path);
    void AddGeometricVertex(GeometricVertex const &geometric_vertex);
    void AddTextureVertex(TextureVertex const &texture_vertex);
    void AddVertexNormal(VertexNormal const &vertex_normal);
    void AddFace(Face const &face);
    GeometricVertex const &GetGeometricVertex(unsigned int ref) const;
    TextureVertex const &GetTextureVertex(unsigned int ref) const;
    VertexNormal const &GetVertexNormal(unsigned int ref) const;
    Face const &GetFace(unsigned int index) const;
    unsigned int GetFaceCount() const;
    void TriangulateFaces();
    std::string const ToString() const;

private:
    template<typename T>
    std::string const GetVectorString(std::vector<T> const &vector) const;
    std::vector<Face> const Triangulate(unsigned int index) const;
    void ReplaceFaceByFaces(unsigned int index, std::vector<Face> const &new_faces);
};
