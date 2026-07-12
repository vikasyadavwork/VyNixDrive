#pragma once

#include <QString>
#include <QOpenGLShaderProgram>

class Shader
{
public:
    Shader() = default;
    ~Shader() = default;

    bool LoadFromFile(const QString& vertexPath,
                      const QString& fragmentPath);

    void Bind();
    void Release();

    QOpenGLShaderProgram& Program();

private:
    QOpenGLShaderProgram m_program;
};
