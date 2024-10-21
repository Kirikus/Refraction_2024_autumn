#ifndef INPUTLIST_H
#define INPUTLIST_H

#include <QWidget>
#include <qvector.h>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QSpacerItem>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class GostInput : public QWidget {
    Q_OBJECT

    QStringList headers = {"h", "P", "T"};
    QTableWidget *table;
    QVBoxLayout *widgetLayout;
    int rowsAmount = 15, columnsAmount = 3;
public:
    GostInput(QWidget *parent = nullptr);
};


class ExpInput : public QWidget {
    Q_OBJECT

public:
    ExpInput(QWidget *parent = nullptr);
private:
    QVector<QString> labelStrings = {"N<sub>s<sub>:", "n<sub>b<sub>:", "N<sub>b<sub>:", "H<sub>b<sub>:"};
    QStringList rangeStrings = {"3 km", "10 km", "15 km"};
    QVector<QLabel*> labels;
    QVector<QLineEdit*> edits;
    QGridLayout *widgetLayout;
    QSpacerItem *verticalSpacer;
    QLabel *rangeLabel;
    QString rangeLabelString = "Range:";
    QComboBox *rangeBox;

};

#endif // INPUTLIST_H
