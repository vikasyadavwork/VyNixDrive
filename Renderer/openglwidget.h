#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include "shader.h"

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
    QOpenGLShaderProgram m_shaderProgram;

    QOpenGLBuffer m_vbo{QOpenGLBuffer::VertexBuffer};

    QOpenGLVertexArrayObject m_vao;
private:

    Shader m_shader;
};
