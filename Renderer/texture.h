#pragma once

#include <QString>
#include <QOpenGLFunctions>

class Texture
{
public:
    Texture();

    bool LoadFromFile(
        QOpenGLFunctions* gl,
        const QString& filename);

    void Bind(
        QOpenGLFunctions* gl,
        unsigned int unit = 0);

    void Release(
        QOpenGLFunctions* gl);
};

