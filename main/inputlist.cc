#include "inputlist.h"

GostInput::GostInput(QWidget *parent) : QWidget(parent) {
    widgetLayout = new QVBoxLayout(this);
    table = new QTableWidget();

    table->setRowCount(rowsAmount);
    table->setColumnCount(columnsAmount);
    table->setHorizontalHeaderLabels(headers);

    widgetLayout->addWidget(table);
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
    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    widgetLayout->addItem(verticalSpacer, stringLabel.length(), 0);
}
