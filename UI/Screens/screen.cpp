#include "screen.h"

#include <QVBoxLayout>
#include <QLabel>

Screen::Screen(
    const QString& title,
    QWidget* parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0,0,0,0);
    m_layout->setSpacing(0);
}
