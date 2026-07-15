#pragma once

#include <QWidget>

class QVBoxLayout;

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(
        const QString& title,
        QWidget* parent = nullptr);
protected:

    QVBoxLayout* m_layout = nullptr;
};
