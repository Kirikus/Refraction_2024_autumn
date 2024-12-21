#ifndef INPUTATMOLIST_H
#define INPUTATMOLIST_H

#include <QWidget>
#include <QVector>
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
    // Returns the range index;
    // 3k meters : index = 0;
    // 10k meters : index = 1;
    // 15k meters : index = 2;
    // custom : index = 3.
    int get_rangeIndex();
    // values = {N_s, n_b, N_b, H_b}.
    QVector<double> get_edits();
private:
    QVector<QString> labelStrings = {"N<sub>s<sub>:", "n<sub>b<sub>:", "N<sub>b<sub>:", "H<sub>b<sub>:"};
    QStringList rangeStrings = {"3 km", "10 km", "15 km"};//, "custom"};
    QVector<QLabel*> labels;
    QVector<QLineEdit*> edits;
    QGridLayout *widgetLayout;
    QSpacerItem *verticalSpacer;
    QLabel *rangeLabel;
    QString rangeLabelString = "Range:";
    QComboBox *rangeBox;

};

#endif // INPUTATMOLIST_H
