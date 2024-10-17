#ifndef INPUTPROBLEM_H
#define INPUTPROBLEM_H

#include <QWidget>
#include <qvector.h>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class GostInput : public QTableWidget {
    Q_OBJECT

    int rowsAmount = 15, columnsAmount = 3;
    QStringList headers = {"h", "P", "T"};

public:
    GostInput(QWidget *parent = nullptr);
};


class ExpInput : public QWidget {
    Q_OBJECT

public:
    ExpInput(QWidget *parent = nullptr);
private:
    QVector<QString> stringLabel = {"Ns:", "nb:", "Nb:", "Hb:"};
    QGridLayout *widgetLayout;
    QVector<QLabel*> labels;
    QVector<QLineEdit*> edits;

};

#endif // INPUTPROBLEM_H
