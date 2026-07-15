#include "navigationitem.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QFile>

NavigationItem::NavigationItem(
    NavigationPage page,
    const QString& title,
    const QString& iconPath,
    QWidget* parent)
    : QWidget(parent),
    m_page(page)
{
    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(8, 8, 8, 8);
    layout->setSpacing(4);

    m_icon = new QLabel(this);

    qDebug() << "Resource exists:"
             << QFile::exists(iconPath);

    qDebug() << "Path:"
             << iconPath;

    QIcon icon(iconPath);

    QPixmap pixmap = icon.pixmap(28, 28);

    m_icon->setPixmap(pixmap);

    m_text = new QLabel(title, this);

    m_icon->setAlignment(Qt::AlignCenter);
    m_text->setAlignment(Qt::AlignCenter);

    layout->addWidget(m_icon);
    layout->addWidget(m_text);

    setMinimumSize(80, 70);

    setStyleSheet(R"(

    NavigationItem
    {
        background: transparent;
        border-radius:10px;
    }

    NavigationItem:hover
    {
        background-color:#2D2D2D;
    }

    QLabel
    {
        color:#BDBDBD;
        background:transparent;
    }

    )");
}

void NavigationItem::mousePressEvent(QMouseEvent* event)
{
    emit Clicked(m_page);
    QWidget::mousePressEvent(event);
}
