#include "vertexbuffer.h"

VertexBuffer::VertexBuffer()
    : m_buffer(QOpenGLBuffer::VertexBuffer)
{
}

VertexBuffer::~VertexBuffer()
{
    Destroy();
}

bool VertexBuffer::Create()
{
    return m_buffer.create();
}

void VertexBuffer::Destroy()
{
    if (m_buffer.isCreated())
        m_buffer.destroy();
}

void VertexBuffer::Allocate(const void* data,
                            int size)
{
    m_buffer.allocate(data, size);
}

void VertexBuffer::Bind()
{
    m_buffer.bind();
}

void VertexBuffer::Release()
{
    m_buffer.release();
}
