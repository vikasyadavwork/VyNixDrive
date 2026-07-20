#pragma once

#include <QOpenGLBuffer>

class ElementBuffer
{
public:
    ElementBuffer();
    ~ElementBuffer();

    bool Create();
    void Destroy();

    void Bind();
    void Release();

    void Allocate(const void* data, int size);

private:
    QOpenGLBuffer m_buffer;
};
