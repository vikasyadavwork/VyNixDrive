#pragma once

#include "Math/Transform.h"
#include "camera.h"
#include "shader.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "cubemesh.h"
#include "elementbuffer.h"

class Renderer
{
public:
    bool Initialize(QOpenGLFunctions* gl);

    void Render(
        QOpenGLFunctions* gl,
        const Transform& transform,
        const Camera& camera,
        int viewportWidth,
        int viewportHeight);

private:
    CubeMesh m_cube;
    Shader m_shader;
    VertexArray m_vertexArray;
    VertexBuffer m_vertexBuffer;
    ElementBuffer m_elementBuffer;
};
