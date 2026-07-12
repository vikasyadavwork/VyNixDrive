#include "shader.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

QOpenGLShaderProgram& Shader::Program()
{
    return m_program;
}

void Shader::Bind()
{
    m_program.bind();
}

void Shader::Release()
{
    m_program.release();
}

namespace
{

QString ReadTextFile(const QString& path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Failed to open shader:" << path;
        return {};
    }

    QTextStream stream(&file);

    return stream.readAll();
}

}

bool Shader::LoadFromFile(const QString& vertexPath,
                          const QString& fragmentPath)
{

    qDebug() << "Current Path :" << QDir::currentPath();
    qDebug() << "Vertex Path  :" << vertexPath;
    qDebug() << "Fragment Path:" << fragmentPath;

    QString vertexSource = ReadTextFile(vertexPath);
    QString fragmentSource = ReadTextFile(fragmentPath);

    qDebug() << "Vertex Size :" << vertexSource.size();
    qDebug() << "Fragment Size :" << fragmentSource.size();

    if (vertexSource.isEmpty() || fragmentSource.isEmpty())
        return false;

    // Compile Vertex Shader
    if (!m_program.addShaderFromSourceCode(
            QOpenGLShader::Vertex,
            vertexSource))
    {
        qCritical() << "Vertex Shader Error";
        qCritical() << m_program.log();
        return false;
    }

    // Compile Fragment Shader
    if (!m_program.addShaderFromSourceCode(
            QOpenGLShader::Fragment,
            fragmentSource))
    {
        qCritical() << "Fragment Shader Error";
        qCritical() << m_program.log();
        return false;
    }

    // Link Program
    if (!m_program.link())
    {
        qCritical() << "Shader Link Error";
        qCritical() << m_program.log();
        return false;
    }

    qDebug() << "Shader compiled successfully.";

    return true;
}
