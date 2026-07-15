#include "ambientscreen.h"

#include <QVBoxLayout>

#include "Renderer/openglwidget.h"

AmbientScreen::AmbientScreen(QWidget* parent)
    : Screen("Ambient", parent)
{
    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(0,0,0,0);

    m_renderer = new OpenGLWidget(this);

    layout->addWidget(m_renderer);
}
