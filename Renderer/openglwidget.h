#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include "shader.h"
#include "vertexbuffer.h"
#include "vertexarray.h"

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
    Shader m_shader;
    VertexBuffer m_vertexBuffer;
    VertexArray m_vertexArray;
};
