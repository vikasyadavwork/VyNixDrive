#include "ambientscreen.h"

#include <QVBoxLayout>

#include "Renderer/openglwidget.h"

AmbientScreen::AmbientScreen(QWidget* parent)
    : Screen("Ambient", parent)
{
    m_layout->setContentsMargins(0,0,0,0);

    m_renderer = new OpenGLWidget();

    m_layout->addWidget(m_renderer);
}
