#include "mainwindow.h"
// #include <iostream>
#include "../lib/refrmodel.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::redrawGraph() {
    auto direct_refr_model = ui->direct->getRefrModel();
    auto inverse_refr_model = ui->inverse->getRefrModel();

    QVector<double> direct_refr_vals = ui->direct->getRefrValues();
    QVector<double> inverse_refr_vals = ui->inverse->getRefrValues();
    double dir_h_a = direct_refr_vals[0], dir_h_s = direct_refr_vals[1], dir_R = direct_refr_vals[2];
    // some vars stay unused, then why even leave a TextEdit for them?
    double inv_h_a = inverse_refr_vals[0], inv_h_s = inverse_refr_vals[1], inv_R = inverse_refr_vals[2];

    QCustomPlot* gView = ui->graphView;
    gView->legend->setVisible(true);
    gView->clearGraphs();
    RefrResult dir_ans = direct_refr_model->calculate(dir_h_a, dir_h_s, dir_R);
    InvRefrResult inv_ans = inverse_refr_model->reverse(inv_h_a, dir_ans.psi_d, inv_R);

    QPen pen;
    QVector<double> x, y;

    pen.setColor(QColor(0, 0, 0));
    //station
    x = {0};
    y = {dir_h_a};

    gView->addGraph();
    gView->graph()->setScatterStyle(QCPScatterStyle::ssSquare);
    gView->graph()->setData(x, y);
    gView->graph()->setPen(pen);
    gView->graph()->setName("Station");

    // direct target
    x = {dir_ans.d};
    y = {dir_h_s};

    gView->addGraph();
    gView->graph()->setScatterStyle(QCPScatterStyle::ssSquare);
    gView->graph()->setData(x, y);
    pen.setColor(QColor(255, 0, 0, 126));
    gView->graph()->setPen(pen);
    gView->graph()->setName("Target-direct");

    // inverse target
    x = {inv_ans.d};
    y = {inv_ans.h_s};

    gView->addGraph();
    gView->graph()->setScatterStyle(QCPScatterStyle::ssSquare);
    gView->graph()->setData(x, y);
    pen.setColor(QColor(0, 0, 255, 126));
    gView->graph()->setPen(pen);
    gView->graph()->setName("Target-inverse");


    // direct graph
    pen.setColor(QColor(255, 0, 0, 126));
    // direct declination
    x = {0, dir_ans.d/5};
    y = {dir_h_a, dir_h_a - dir_ans.d/5*std::tan(dir_ans.psi_d)};

    gView->addGraph();
    gView->graph()->setData(x, y);
    gView->graph()->setPen(pen);
    gView->graph()->setName("Direct declination");

    // direct glide
    x = {dir_ans.d*4/5, dir_ans.d};
    y = {dir_h_s + dir_ans.d/5*std::tan(dir_ans.psi_g), dir_h_s};

    gView->addGraph();
    gView->graph()->setData(x, y);
    gView->graph()->setPen(pen);
    gView->graph()->setName("Direct glide");

    // inverse graph
    pen.setColor(QColor(0, 0, 255, 126));
    //inverse declination
    x = {0, inv_ans.d/5};
    y = {inv_h_a, inv_h_a - inv_ans.d/5*std::tan(dir_ans.psi_d)};

    gView->addGraph();
    gView->graph()->setData(x, y);
    gView->graph()->setPen(pen);
    gView->graph()->setName("Inverse declination");

    //inverse glide
    x = {inv_ans.d*4/5, inv_ans.d};
    y = {inv_ans.h_s + inv_ans.d/5*std::tan(inv_ans.psi_g), inv_ans.h_s};

    gView->addGraph();
    gView->graph()->setData(x, y);
    gView->graph()->setPen(pen);
    gView->graph()->setName("Inverse glide");


    gView->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    gView->replot();
}
