#include "cubemesh.h"

CubeMesh::CubeMesh() {}

bool CubeMesh::Create()
{
    // Rectangle (temporary)
    static constexpr Vertex vertices[] =
        {
         // Front (Red)
         {{-0.5f,-0.5f, 0.5f}, {1,0,0}},
         {{ 0.5f,-0.5f, 0.5f}, {1,0,0}},
         {{ 0.5f, 0.5f, 0.5f}, {1,0,0}},
         {{-0.5f, 0.5f, 0.5f}, {1,0,0}},

         // Back (Green)
         {{ 0.5f,-0.5f,-0.5f}, {0,1,0}},
         {{-0.5f,-0.5f,-0.5f}, {0,1,0}},
         {{-0.5f, 0.5f,-0.5f}, {0,1,0}},
         {{ 0.5f, 0.5f,-0.5f}, {0,1,0}},

         // Left (Blue)
         {{-0.5f,-0.5f,-0.5f}, {0,0,1}},
         {{-0.5f,-0.5f, 0.5f}, {0,0,1}},
         {{-0.5f, 0.5f, 0.5f}, {0,0,1}},
         {{-0.5f, 0.5f,-0.5f}, {0,0,1}},

         // Right (Yellow)
         {{ 0.5f,-0.5f, 0.5f}, {1,1,0}},
         {{ 0.5f,-0.5f,-0.5f}, {1,1,0}},
         {{ 0.5f, 0.5f,-0.5f}, {1,1,0}},
         {{ 0.5f, 0.5f, 0.5f}, {1,1,0}},

         // Top (Magenta)
         {{-0.5f, 0.5f, 0.5f}, {1,0,1}},
         {{ 0.5f, 0.5f, 0.5f}, {1,0,1}},
         {{ 0.5f, 0.5f,-0.5f}, {1,0,1}},
         {{-0.5f, 0.5f,-0.5f}, {1,0,1}},

         // Bottom (Cyan)
         {{-0.5f,-0.5f,-0.5f}, {0,1,1}},
         {{ 0.5f,-0.5f,-0.5f}, {0,1,1}},
         {{ 0.5f,-0.5f, 0.5f}, {0,1,1}},
         {{-0.5f,-0.5f, 0.5f}, {0,1,1}},
         };

    static constexpr uint32_t indices[] =
        {
            // Front
            0,1,2,
            2,3,0,

            // Back
            4,5,6,
            6,7,4,

            // Left
            8,9,10,
            10,11,8,

            // Right
            12,13,14,
            14,15,12,

            // Top
            16,17,18,
            18,19,16,

            // Bottom
            20,21,22,
            22,23,20
        };

    constexpr uint32_t VertexCount =
        sizeof(vertices) / sizeof(Vertex);

    constexpr uint32_t IndexCount =
        sizeof(indices) / sizeof(uint32_t);

    return Mesh::Create(
        vertices,
        VertexCount,
        indices,
        IndexCount);
}
