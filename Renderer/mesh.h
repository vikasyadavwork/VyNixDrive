#pragma once

#include <cstdint>

#include "Core/Vertex.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "elementbuffer.h"

class Mesh
{
public:
    Mesh() = default;
    ~Mesh() = default;

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    bool Create(
        const Vertex* vertices,
        uint32_t vertexCount,
        const uint32_t* indices,
        uint32_t indexCount);

    void Draw(QOpenGLFunctions* gl);

    uint32_t GetIndexCount() const
    {
        return m_indexCount;
    }

protected:
    void Bind();
    void Release();

private:
    VertexArray m_vertexArray;
    VertexBuffer m_vertexBuffer;
    ElementBuffer m_elementBuffer;

    uint32_t m_indexCount = 0;
};
