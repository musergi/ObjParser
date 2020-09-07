#include <iostream>
#include <obj_content.hpp>

int main()
{
    ObjContent content("tests/test.obj");
    std::cout << content.ToString() << std::endl;
    std::cout << "Face count: " << content.GetFaceCount() << std::endl;
    std::cout << "Face 0: " << content.GetFace(0).ToString() << std::endl;
    VertexReference vertex = content.GetFace(0).GetVertex(0);
    std::cout << "Vertex 0: " 
        << content.GetGeometricVertex(vertex.v).ToString() << " "
        << content.GetTextureVertex(vertex.vt).ToString() << " "
        << content.GetVertexNormal(vertex.vn).ToString() << std::endl;
}
