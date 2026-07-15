#include "navigationbar.h"

#include <QHBoxLayout>
#include <QPushButton>
#include "NavigationItem.h"

NavigationBar::NavigationBar(QWidget* parent) : QWidget(parent)
{
    auto* layout = new QHBoxLayout(this);

    auto AddNavigationItem =
        [this](NavigationPage page,
               const QString& title,
               const QString& iconPath)
    {
        auto* item = new NavigationItem(
            page,
            title,
            iconPath,
            this);

        m_items.push_back({ page, item });

        return item;
    };

    AddNavigationItem(
        NavigationPage::Home,
        "Home",
        ":/Icons/home.svg");

    AddNavigationItem(
        NavigationPage::Ambient,
        "Ambient",
        ":/Icons/ambient.svg");

    AddNavigationItem(
        NavigationPage::HVAC,
        "HVAC",
        ":/Icons/hvac.svg");

    AddNavigationItem(
        NavigationPage::TPMS,
        "TPMS",
        ":/Icons/tpms.svg");

    AddNavigationItem(
        NavigationPage::Camera,
        "Camera",
        ":/Icons/camera.svg");

    AddNavigationItem(
        NavigationPage::Music,
        "Music",
        ":/Icons/music.svg");

    AddNavigationItem(
        NavigationPage::Settings,
        "HVAC",
        ":/Icons/settings.svg");

    for (const auto& entry : m_items)
    {
        layout->addWidget(entry.Item);
    }

    for (const auto& entry : m_items)
    {
        connect(entry.Item,
                &NavigationItem::Clicked,
                this,
                &NavigationBar::PageSelected);
    }

    setFixedHeight(90);

    layout->setContentsMargins(16, 8, 16, 8);
    layout->setSpacing(12);

    setStyleSheet(R"(
    NavigationBar
    {
        background-color: #181818;
        border-top: 1px solid #2C2C2C;
    }
    )");

}
