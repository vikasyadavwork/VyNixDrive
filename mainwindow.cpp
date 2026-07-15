#include "mainwindow.h"

#include <QStackedWidget>
#include <QVBoxLayout>

#include "UI/Navigation/NavigationPage.h"
#include "UI/Navigation/NavigationBar.h"

#include "UI/screens/homescreen.h"
#include "UI/screens/ambientscreen.h"
#include "UI/screens/hvacScreen.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    resize(1280, 720);
    setWindowTitle("VyNixDrive");

    auto* centralWidget = new QWidget(this);

    auto* layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Create widgets
    m_stack = new QStackedWidget(centralWidget);

    m_navigationBar = new NavigationBar(centralWidget);

    m_homeScreen = new HomeScreen();
    m_ambientScreen = new AmbientScreen();
    m_hvacScreen = new HVACScreen();

    // Add pages
    m_stack->addWidget(m_homeScreen);
    m_stack->addWidget(m_ambientScreen);
    m_stack->addWidget(m_hvacScreen);

    // Show Home page by default
    m_stack->setCurrentWidget(m_homeScreen);

    // Build layout
    layout->addWidget(m_stack, 1);          // Stretch = 1
    layout->addWidget(m_navigationBar);

    setCentralWidget(centralWidget);

    // Connect navigation to page switching
    connect(
        m_navigationBar,
        &NavigationBar::PageSelected,
        this,
        &MainWindow::OnPageSelected);

    m_navigationBar->setStyleSheet("background-color: red;");
    m_navigationBar->setMinimumHeight(80);
}

void MainWindow::OnPageSelected(
    NavigationPage page)
{
    switch (page)
    {
    case NavigationPage::Home:
        m_stack->setCurrentWidget(m_homeScreen);
        break;

    case NavigationPage::Ambient:
        m_stack->setCurrentWidget(m_ambientScreen);
        break;

    case NavigationPage::HVAC:
        m_stack->setCurrentWidget(m_hvacScreen);
        break;

    default:
        break;
    }
}

MainWindow::~MainWindow()
{
}
