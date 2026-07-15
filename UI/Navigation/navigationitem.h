#pragma once

#include <QWidget>

#include "NavigationPage.h"

class QLabel;
class QVBoxLayout;

class NavigationItem : public QWidget
{
    Q_OBJECT

public:

    explicit NavigationItem(
        NavigationPage page,
        const QString& title,
        const QString& iconPath,
        QWidget* parent = nullptr);

    NavigationPage Page() const;

signals:

    void Clicked(NavigationPage page);

protected:

    void mousePressEvent(QMouseEvent* event) override;

private:

    NavigationPage m_page;

private:
    QLabel* m_icon = nullptr;
    QLabel* m_text = nullptr;
};
