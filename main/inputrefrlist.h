#ifndef INPUTREFRLIST_H
#define INPUTREFRLIST_H

#include <QVector>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>

class UsualRefrInput : public QWidget {
    Q_OBJECT

public:
    UsualRefrInput(QWidget *parent = nullptr);
    // values = {h_a, h_b, R}.
    QVector<double> get_edits();
private:
    QVector<QString> labelStrings = {"h<sub>a<sub>:", "h<sub>s<sub>:", "R:"};
    QVector<QLabel*> labels;
    QVector<QLineEdit*> edits;
    QGridLayout *widgetLayout;
    QSpacerItem *verticalSpacer;
};

#endif // INPUTREFRLIST_H
