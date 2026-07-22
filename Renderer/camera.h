#pragma once

#include <QMatrix4x4>
#include <QVector3D>

class Camera
{
public:
    Camera();

    QVector3D Position{0.0f, 0.0f, 3.0f};

    float Pitch = 0.0f;
    float Yaw = -90.0f;
    float FOV = 45.0f;

    QMatrix4x4 GetViewMatrix() const;
    QMatrix4x4 GetProjectionMatrix(
        float aspectRatio) const;
};
