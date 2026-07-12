#pragma once

#include <vector>
#include <QOpenGLFunctions>

struct VertexAttribute
{
    GLuint Index;          // layout(location = ?)

    GLint Count;           // 3 floats, 2 floats ...

    GLenum Type;           // GL_FLOAT

    bool Normalized;

    std::size_t Offset;
};

class VertexLayout
{
public:

    void AddAttribute(
        GLuint index,
        GLint count,
        GLenum type,
        bool normalized,
        std::size_t offset);

    const std::vector<VertexAttribute>& Attributes() const;

    void SetStride(GLsizei stride);

    GLsizei Stride() const;

private:

    std::vector<VertexAttribute> m_attributes;

    GLsizei m_stride = 0;
};
