#include "renderer.h"
#include <QOpenGLFunctions>

bool Renderer::Initialize(QOpenGLFunctions* gl)
{
    // Load shaders
    if (!m_shader.LoadFromFile(
            "Assets/Shaders/Triangle.vert",
            "Assets/Shaders/Triangle.frag"))
    {
        return false;
    }

    Vertex vertices[] =
        {
            {{-0.5f,-0.5f,0.0f}, {1,0,0}},
            {{ 0.5f,-0.5f,0.0f}, {0,1,0}},
            {{ 0.5f, 0.5f,0.0f}, {0,0,1}},
            {{-0.5f, 0.5f,0.0f}, {1,1,0}}
        };

    unsigned int indices[] =
        {
            0,1,2,
            2,3,0
        };

    m_vertexArray.Create();
    m_vertexArray.Bind();

    m_vertexBuffer.Create();
    m_vertexBuffer.Bind();
    m_vertexBuffer.Allocate(vertices, sizeof(vertices));

    m_elementBuffer.Create();
    m_elementBuffer.Bind();
    m_elementBuffer.Allocate(indices, sizeof(indices));

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

    layout.SetStride(sizeof(Vertex));

    m_vertexArray.AddBuffer(
        m_vertexBuffer,
        layout);

    // Unbind everything
    m_vertexArray.Release();
    m_vertexBuffer.Release();
    m_elementBuffer.Release();

    return true;
}

void Renderer::Render(
    QOpenGLFunctions* gl,
    const Transform& transform,
    const Camera& camera,
    int width,
    int height)
{
    QMatrix4x4 model;

    model.translate(transform.Position);

    model.rotate(transform.Rotation.x(),1,0,0);
    model.rotate(transform.Rotation.y(),0,1,0);
    model.rotate(transform.Rotation.z(),0,0,1);

    model.scale(transform.Scale);

    auto view = camera.GetViewMatrix();

    auto projection =
        camera.GetProjectionMatrix(
            float(width)/float(height));

    gl->glClearColor(
        0.08f,
        0.08f,
        0.10f,
        1.0f);

    gl->glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT);

    m_shader.Bind();

    m_shader.Program().setUniformValue(
        "uModel",
        model);

    m_shader.Program().setUniformValue(
        "uView",
        view);

    m_shader.Program().setUniformValue(
        "uProjection",
        projection);

    m_vertexArray.Bind();

    gl->glDrawElements(
        GL_TRIANGLES,
        6,
        GL_UNSIGNED_INT,
        nullptr);

    m_vertexArray.Release();
    m_shader.Release();
}
