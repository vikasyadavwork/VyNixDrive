#pragma once

#include <QVector3D>

class Transform
{
public:

    QVector3D Position {0.0f,0.0f,0.0f};

    QVector3D Rotation {0.0f,0.0f,0.0f};

    QVector3D Scale {1.0f,1.0f,1.0f};
};
