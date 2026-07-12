#include "openglwidget.h"
#include <QDebug>

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

    if (!m_shader.LoadFromFile(
            "Assets/Shaders/Triangle.vert",
            "Assets/Shaders/Triangle.frag"))
    {
        qFatal("Shader loading failed.");
    }

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
}
