#include "elementbuffer.h"

ElementBuffer::ElementBuffer()
    : m_buffer(QOpenGLBuffer::IndexBuffer)
{
}

ElementBuffer::~ElementBuffer()
{
    Destroy();
}

bool ElementBuffer::Create()
{
    return m_buffer.create();
}

void ElementBuffer::Destroy()
{
    if (m_buffer.isCreated())
        m_buffer.destroy();
}

void ElementBuffer::Bind()
{
    m_buffer.bind();
}

void ElementBuffer::Release()
{
    m_buffer.release();
}

void ElementBuffer::Allocate(const void* data, int size)
{
    m_buffer.allocate(data, size);
}
