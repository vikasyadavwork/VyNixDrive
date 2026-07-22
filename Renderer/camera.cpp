#include "camera.h"

Camera::Camera() {}

QMatrix4x4 Camera::GetViewMatrix() const
{
    QMatrix4x4 view;
    view.lookAt(
        Position,
        QVector3D(0,0,0),
        QVector3D(0,1,0));

    return view;
}

QMatrix4x4 Camera::GetProjectionMatrix(float aspectRatio) const
{
    QMatrix4x4 projection;
    projection.perspective(
        FOV,
        aspectRatio,
        0.1f,
        100.0f);

    return projection;
}
