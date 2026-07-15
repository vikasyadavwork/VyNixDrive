#include "vertexlayout.h"

void VertexLayout::AddAttribute(GLuint index, GLint count, GLenum type,
                                bool normalized, std::size_t offset)
{
    m_attributes.push_back({index, count, type, normalized, offset});
}

const std::vector<VertexAttribute>& VertexLayout::Attributes() const
{
    return m_attributes;
}

void VertexLayout::SetStride(GLsizei stride)
{
    m_stride = stride;
}

GLsizei VertexLayout::Stride() const
{
    return m_stride;
}
