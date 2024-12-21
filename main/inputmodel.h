#ifndef INPUTMODEL_H
#define INPUTMODEL_H

#include <QWidget>
#include <QVector>
#include <memory>
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

    // values = {h_a, h_s, R}.
    QVector<double> getRefrValues();

    // TODO... maybe
    // QVector<double> getAtmoValues();
private:
    Ui::inputModel *ui;
};

#endif // INPUTMODEL_H
