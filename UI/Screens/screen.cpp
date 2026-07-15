#include "screen.h"

#include <QVBoxLayout>
#include <QLabel>

Screen::Screen(
    const QString& title,
    QWidget* parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);

    auto* label = new QLabel(title, this);

    label->setAlignment(Qt::AlignCenter);

    m_layout->addWidget(label);
}
