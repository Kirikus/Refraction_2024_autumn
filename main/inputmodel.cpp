#include "inputmodel.h"
#include "ui_inputmodel.h"

InputModel::InputModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputModel)
{
    ui->setupUi(this);
}

InputModel::~InputModel()
{
    delete ui;
}
