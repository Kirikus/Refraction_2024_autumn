#include "inputproblem.h"

GostInput::GostInput(QWidget *parent) : QTableWidget(parent) {
    this->setRowCount(rowsAmount);
    this->setColumnCount(columnsAmount);
    this->setHorizontalHeaderLabels(headers);
}

ExpInput::ExpInput(QWidget *parent) : QWidget(parent) {
    widgetLayout = new QGridLayout(this);

    for (int i=0; i<stringLabel.length(); ++i) {
        labels.append(new QLabel());
        edits.append(new QLineEdit());

        labels[i]->setText(stringLabel[i]);
        labels[i]->setBuddy(edits[0]);

        widgetLayout->addWidget(labels[i], i, 0);
        widgetLayout->addWidget(edits[i], i, 1);
    }

}
