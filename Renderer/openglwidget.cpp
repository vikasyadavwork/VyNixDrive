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
    Vertex vertices[]
        {
            { -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f }, // Red
            {  0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f }, // Green
            {  0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f }  // Blue
        };

    // Create GPU Vertex Buffer
    m_vertexBuffer.Create();
    m_vertexBuffer.Bind();
    m_vertexBuffer.Allocate(vertices, sizeof(vertices));

    // Describe vertex layout
    VertexLayout layout;

    layout.AddAttribute(
        0,
        3,
        GL_FLOAT,
        false,
        offsetof(Vertex, x));

    layout.AddAttribute(
        1,
        3,
        GL_FLOAT,
        false,
        offsetof(Vertex, r));

    layout.SetStride(sizeof(Vertex));

    // Create Vertex Array
    m_vertexArray.Create();
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
    glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_shader.Bind();
    m_vertexArray.Bind();

    glDrawArrays(
        GL_TRIANGLES,
        0,
        3);

    m_vertexArray.Release();
    m_shader.Release();
}
