#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QTimer>
#include <QElapsedTimer>
#include "camera.h"
#include "renderer.h"
#include "Math/Transform.h"

class OpenGLWidget : public QOpenGLWidget,
                     protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

private:
    Camera m_camera;
    Renderer m_renderer;

private:
    Transform m_transform;

    QTimer* m_timer = nullptr;
    QElapsedTimer m_frameTimer;
    float m_deltaTime = 0.0f;
    void Update();
};
