#pragma once

#include <QWidget>
#include <vector>

#include "NavigationPage.h"

class NavigationItem;

struct NavigationEntry
{
    NavigationPage Page;

    NavigationItem* Item;
};

class NavigationBar : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationBar(QWidget* parent = nullptr);

signals:
    void PageSelected(NavigationPage page);

private:

    std::vector<NavigationEntry> m_items;
};
