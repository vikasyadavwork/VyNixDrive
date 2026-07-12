#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "Renderer/openglwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto* renderer = new OpenGLWidget(this);

    setCentralWidget(renderer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
