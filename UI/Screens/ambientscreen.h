#pragma once

#include "screen.h"

class OpenGLWidget;

class AmbientScreen : public Screen
{
    Q_OBJECT

public:
    explicit AmbientScreen(QWidget* parent = nullptr);

private:
    OpenGLWidget* m_renderer = nullptr;
};
