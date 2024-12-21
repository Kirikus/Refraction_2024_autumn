#include "inputmodel.h"
#include <iostream>
#include "ui_inputmodel.h"

InputModel::InputModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputModel)
{
    ui->setupUi(this);
}

InputModel::~InputModel()
{
    delete ui;
}

AtmosphereModel* InputModel::getAtmoModel() {
    int mode = ui->atmoMode->currentIndex();
    const int GOST=0, SEGMENTED=1, LAYERED=2,
        EXP=3, ANOMALY=4;

    const int RANGE_3K=0, RANGE_10K=1, RANGE_15K=2;//, RANGE_CUSTOM=3;

    switch (mode) {

    // case GOST:

    // TODO: Insert parameters
    // case LAYERED:
    //     return LayeredAtmosphere();

    case SEGMENTED:
        // TODO: implement parameters
        return new SegmentedAtmosphere();

    case EXP: {
            int range = ui->exp->get_rangeIndex();
            QVector<double> atmo_parameters = ui->exp->get_edits();
            QVector<double> refr_parameters = static_cast<UsualRefrInput>(ui->refraList->currentWidget()).get_edits();
            switch (range) {

            case RANGE_3K:
                return new ExponentialAtmosphere3k(atmo_parameters[0], refr_parameters[1]);

            case RANGE_10K:
                return new ExponentialAtmosphere10k(atmo_parameters[0],refr_parameters[1]);

            case RANGE_15K:
                return new ExponentialAtmosphere15k(atmo_parameters[0], refr_parameters[1]);
            // TODO
            //case RANGE_CUSTOM:
            default:
                std::runtime_error("Impossible Exponential range index.");
            }
        }
    // case ANOMALY:
    default:
        std::runtime_error("Impossible atmosphere index.");
    }
}

RefractionModel* InputModel::getRefrModel() {
    int mode = ui->refraMode->currentIndex();
    const int GEOMLINE=0, GEOMROUND=1, FOURTHIRDS=2,
        AVRGKANALYT=3, AVRGPANALYT=4;

    switch (mode) {

    case GEOMLINE:
        return new GeometricLine();

    case GEOMROUND:
        return new GeometricRound();

    case FOURTHIRDS:
        return new FourThirds();

    // TODO: assert the result of 'getAtmoModel()'
    case AVRGKANALYT:
        return new AverageKAnalytical(static_cast<ExponentialAtmosphere*>(getAtmoModel()));

    // TODO: assert the result of 'getAtmoModel()'
    case AVRGPANALYT:
        return new AveragePAnalytical(static_cast<ExponentialAtmosphere*>(getAtmoModel()));

    default:
        std::runtime_error("Impossible refraction index.");
    }
}

QVector<double> InputModel::getRefrValues() {
    int mode = ui->refraMode->currentIndex();
    const int GEOMLINE=0, GEOMROUND=1, FOURTHIRDS=2,
        AVRGKANALYT=3, AVRGPANALYT=4;

    switch (mode) {

    case GEOMLINE:
        return ui->geomLine->get_edits();

    case GEOMROUND:
        return ui->geomRound->get_edits();

    case FOURTHIRDS:
        return ui->fourThirds->get_edits();

    case AVRGKANALYT:
        return ui->avrgKanalyt->get_edits();

    case AVRGPANALYT:
        return ui->avrgPanalyt->get_edits();

    default:
        std::runtime_error("Impossible refraction index.");
    }
}
