#include "vertexarray.h"
#include <QOpenGLFunctions>

VertexArray::VertexArray()
{

}

VertexArray::~VertexArray()
{
    Destroy();
}

bool VertexArray::Create()
{
    m_functions = QOpenGLContext::currentContext()->functions();
    return m_vertexArray.create();
}

void VertexArray::Destroy()
{
    if(m_vertexArray.isCreated()){
        m_vertexArray.destroy();
    }
}

void VertexArray::Bind()
{
    m_vertexArray.bind();
}

void VertexArray::Release()
{
    m_vertexArray.release();
}

void VertexArray::AddBuffer(VertexBuffer& vertexBuffer,
                            const VertexLayout& layout)
{

    Bind();
    vertexBuffer.Bind();

    for(const auto& attribute : layout.Attributes())
    {
        m_functions->glEnableVertexAttribArray(attribute.Index);

        m_functions->glVertexAttribPointer(
            attribute.Index,
            attribute.Count,
            attribute.Type,
            attribute.Normalized ? GL_TRUE : GL_FALSE,
            layout.Stride(),
            reinterpret_cast<const void*>(attribute.Offset));
    }
}
