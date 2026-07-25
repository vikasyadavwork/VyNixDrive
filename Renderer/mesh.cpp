#include "mesh.h"
#include <cstddef>

bool Mesh::Create(
    const Vertex* vertices,
    uint32_t vertexCount,
    const uint32_t* indices,
    uint32_t indexCount)
{
    m_indexCount = indexCount;

    m_vertexArray.Create();
    m_vertexArray.Bind();

    m_vertexBuffer.Create();
    m_vertexBuffer.Bind();
    m_vertexBuffer.Allocate(
        vertices,
        vertexCount * sizeof(Vertex));

    m_elementBuffer.Create();
    m_elementBuffer.Bind();
    m_elementBuffer.Allocate(
        indices,
        indexCount * sizeof(uint32_t));

    VertexLayout layout;

    layout.AddAttribute(
        0,
        3,
        GL_FLOAT,
        false,
        offsetof(Vertex, Position));

    layout.AddAttribute(
        1,
        3,
        GL_FLOAT,
        false,
        offsetof(Vertex, Color));

    layout.AddAttribute(
        2,
        2,
        GL_FLOAT,
        false,
        offsetof(Vertex, UV));

    layout.SetStride(sizeof(Vertex));

    m_vertexArray.AddBuffer(
        m_vertexBuffer,
        layout);

    Release();

    return true;
}

void Mesh::Bind()
{
    m_vertexArray.Bind();
}

void Mesh::Release()
{
    m_vertexArray.Release();
    m_vertexBuffer.Release();
    m_elementBuffer.Release();
}

void Mesh::Draw(QOpenGLFunctions *gl)
{
    Bind();

    gl->glDrawElements(
        GL_TRIANGLES,
        m_indexCount,
        GL_UNSIGNED_INT,
        nullptr);

    Release();
}
