#pragma once

#include <QMainWindow>

class QStackedWidget;

class HomeScreen;
class AmbientScreen;
class HVACScreen;

class NavigationBar;
enum class NavigationPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:

    QStackedWidget* m_stack = nullptr;

    NavigationBar* m_navigationBar = nullptr;

    HomeScreen* m_homeScreen = nullptr;
    AmbientScreen* m_ambientScreen = nullptr;
    HVACScreen* m_hvacScreen = nullptr;

private slots:
    void OnPageSelected(
        NavigationPage page);
};
