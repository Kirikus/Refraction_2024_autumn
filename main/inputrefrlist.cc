#include "inputrefrlist.h"

UsualRefrInput::UsualRefrInput(QWidget *parent) : QWidget(parent) {
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
}

QVector<double> UsualRefrInput::get_edits() {
    QVector<double> vals;
    for (int i=0; i<labelStrings.length(); ++i)
        vals.append((edits[i]->text()).toDouble());
    return vals;
}
