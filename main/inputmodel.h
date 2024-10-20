#ifndef INPUTMODEL_H
#define INPUTMODEL_H

#include <QWidget>

namespace Ui {
class inputModel;
}

class InputModel : public QWidget
{
    Q_OBJECT

public:
    explicit InputModel(QWidget *parent = nullptr);
    ~InputModel();

private:
    Ui::inputModel *ui;
};

#endif // INPUTMODEL_H
