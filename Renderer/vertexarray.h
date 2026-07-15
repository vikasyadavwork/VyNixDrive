#pragma once

#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>

#include "vertexbuffer.h"
#include "vertexlayout.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    bool Create();
    void Destroy();
    void Bind();
    void Release();
    void AddBuffer(VertexBuffer& vertexBuffer,
                   const VertexLayout& layout);

private:
    QOpenGLFunctions* m_functions = nullptr;
    QOpenGLVertexArrayObject m_vertexArray;
};

