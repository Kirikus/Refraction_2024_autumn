#include "mainwindow.h"
#include <iostream>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::redrawGraph() {
    // QCustomPlot* gView = ui->graphView;
    // gView->addGraph();
    std::cout << "Your advertisement" << std::endl;
}
