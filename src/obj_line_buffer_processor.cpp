#include "obj_line_buffer_processor.hpp"
#include <stdio.h>
#include <string.h>

ObjLineBufferProcessor::ObjLineBufferProcessor(ObjContent *obj_content)
    : obj_content(obj_content)
{
}

void ObjLineBufferProcessor::Process(const char *line)
{
    size_t type_len = strpbrk(line, " ") - line;
    if (type_len == 1)
        ParseLineTypeLen1(line);
    else if (type_len == 2)
        ParseLineTypeLen2(line);
}

void ObjLineBufferProcessor::ParseLineTypeLen1(const char *line)
{
    if (strncmp("v", line, 1) == 0)
        ParseGeometricVertexLine(line);
    else if (strncmp("f", line, 1) == 0)
        ParseFaceLine(line);
}

void ObjLineBufferProcessor::ParseLineTypeLen2(const char *line)
{
    if (strncmp("vt", line, 2) == 0)
        ParseTextureVertexLine(line);
    else if (strncmp("vn", line, 2) == 0)
        ParseVertexNormalLine(line);
}

void ObjLineBufferProcessor::ParseGeometricVertexLine(const char *line)
{
    float x, y, z, w;
    int component_count = sscanf(line, "%*s %f %f %f %f", &x, &y, &z, &w);
    if (component_count == 3)
        obj_content->AddGeometricVertex(GeometricVertex(x, y, z));
    else if (component_count == 4)
        obj_content->AddGeometricVertex(GeometricVertex(x, y, z, w));
}

void ObjLineBufferProcessor::ParseTextureVertexLine(const char *line)
{
    float u, v, w;
    int component_count = sscanf(line, "%*s %f %f %f", &u, &v, &w);
    if (component_count == 2)
        obj_content->AddTextureVertex(TextureVertex(u, v));
    else if (component_count == 3)
        obj_content->AddTextureVertex(TextureVertex(u, v, w));
}

void ObjLineBufferProcessor::ParseVertexNormalLine(const char *line)
{
    float i, j, k;
    sscanf(line, "%*s %f %f %f", &i, &j, &k);
    obj_content->AddVertexNormal(VertexNormal(i, j, k));
}

void ObjLineBufferProcessor::ParseFaceLine(const char *line)
{
    Face face;
    while ((line = strchr(line, ' ')) != NULL)
        ParseVertexReference(++line, face);
    obj_content->AddFace(face);
}

void ObjLineBufferProcessor::ParseVertexReference(const char *str, Face &face)
{
    unsigned int v, vt, vn;
    sscanf(str, "%u/%u/%u", &v, &vt, &vn);
    face.AddVertex(VertexReference(v, vt, vn));
}
