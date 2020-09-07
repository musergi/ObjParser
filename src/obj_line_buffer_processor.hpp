#pragma once

#include "line_bufferer.hpp"
#include "obj_content.hpp"

class ObjLineBufferProcessor : public LineBufferer::LineBufferProcessor
{
private:
    ObjContent *obj_content;

public:
    ObjLineBufferProcessor(ObjContent *obj_content);
    void Process(const char *line);

private:
    void ParseLineTypeLen1(const char *line);
    void ParseLineTypeLen2(const char *line);
    void ParseGeometricVertexLine(const char *line);
    void ParseTextureVertexLine(const char *line);
    void ParseVertexNormalLine(const char *line);
    void ParseFaceLine(const char *line);
    void ParseVertexReference(const char *str, Face &face);
};
