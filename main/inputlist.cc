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

    for (int i=0; i<labelStrings.length(); ++i) {
        labels.append(new QLabel());
        edits.append(new QLineEdit());

        labels[i]->setText(labelStrings[i]);
        labels[i]->setBuddy(edits[0]);

        widgetLayout->addWidget(labels[i], i, 0);
        widgetLayout->addWidget(edits[i], i, 1);
    }
    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    widgetLayout->addItem(verticalSpacer, widgetLayout->rowCount(), 0);

    rangeLabel = new QLabel(rangeLabelString, nullptr);
    rangeBox = new QComboBox();
    rangeLabel->setBuddy(rangeBox);

    rangeBox->addItems(rangeStrings);
    widgetLayout->addWidget(rangeLabel, widgetLayout->rowCount(), 0);
    widgetLayout->addWidget(rangeBox, widgetLayout->rowCount()-1, 1);
}
