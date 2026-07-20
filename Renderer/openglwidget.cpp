#include "openglwidget.h"
#include <QDebug>
#include "Core/Vertex.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    // Load shader
    if (!m_shader.LoadFromFile(
            "Assets/Shaders/Triangle.vert",
            "Assets/Shaders/Triangle.frag"))
    {
        qFatal("Shader loading failed.");
    }

    // Create triangle vertices
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


    qDebug() << "OpenGL Initialized!";
}

void OpenGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenGLWidget::paintGL()
{
    QMatrix4x4 model;

    model.translate(m_transform.Position);

    model.rotate(
        m_transform.Rotation.x(),
        1,0,0);

    model.rotate(
        m_transform.Rotation.y(),
        0,1,0);

    model.rotate(
        m_transform.Rotation.z(),
        0,0,1);

    model.scale(m_transform.Scale);

     m_shader.Bind();

    m_shader.Program().setUniformValue(
        "uModel",
        model);

    glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_vertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        6,
        GL_UNSIGNED_INT,
        nullptr);
    m_vertexArray.Release();
    m_shader.Release();
}
