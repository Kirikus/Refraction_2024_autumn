#ifndef INPUTMODEL_H
#define INPUTMODEL_H

#include <QWidget>
#include <memory>
#include <variant>
#include "../lib/refrgeom.h"
#include "../lib/refravrganalyt.h"
#include "../lib/exponential_model.h"
#include "../lib/layered_model.h"
#include "../lib/segmented_model.h"

namespace Ui {
class inputModel;
}

class InputModel : public QWidget
{
    Q_OBJECT

public:
    explicit InputModel(QWidget *parent = nullptr);
    ~InputModel();

    AtmosphereModel* getAtmoModel();
    RefractionModel* getRefrModel();

private:
    Ui::inputModel *ui;
};

#endif // INPUTMODEL_H
