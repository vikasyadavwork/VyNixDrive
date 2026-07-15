#pragma once

#include <QOpenGLBuffer>
#include <vector>

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();

    bool Create();
    void Destroy();
    void Bind();
    void Release();
    void Allocate(
        const void* data,
        int size
        );

    template<typename T>
    void Upload(const std::vector<T>& vertices)
    {
        m_buffer.allocate(
            vertices.data(),
            static_cast<int>(vertices.size() * sizeof(T)));
    }

private:
    QOpenGLBuffer m_buffer;
};
