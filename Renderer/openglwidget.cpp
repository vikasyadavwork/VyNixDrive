#include "openglwidget.h"
#include <QDebug>

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    m_timer = new QTimer(this);
    m_frameTimer.start();
    connect(
        m_timer,
        &QTimer::timeout,
        this,
        [this](){
            qint64 elapsed = m_frameTimer.restart();
            m_deltaTime = elapsed / 1000.0f;
            Update();
            update();
        });

    m_timer->start(16);
}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    m_renderer.Initialize(this);
    qDebug() << "OpenGL Initialized!";
}

void OpenGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenGLWidget::paintGL()
{
    m_renderer.Render(
        this,
        m_transform,
        m_camera,
        width(),
        height());
}

void OpenGLWidget::Update()
{
    constexpr float RotationSpeed = 90.0f; // degrees/sec

    m_transform.Rotation.setY(
        m_transform.Rotation.y()
        + RotationSpeed * m_deltaTime);
}
