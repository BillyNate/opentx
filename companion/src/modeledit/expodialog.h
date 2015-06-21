#ifndef EXPODIALOG_H
#define EXPODIALOG_H

#include <QDialog>
#include "eeprominterface.h"
#include "modelprinter.h"

class GVarGroup;
class CurveGroup;

namespace Ui {
  class ExpoDialog;
}

class ExpoDialog : public QDialog {
    Q_OBJECT
  public:
    ExpoDialog(QWidget *parent, ModelData & model, ExpoData *expodata, GeneralSettings & generalSettings, FirmwareInterface * firmware, char * inputName);
    ~ExpoDialog();

  protected:
    void updateScale();

  private slots:
    void valuesChanged();
    void shrink();    

  private:
    Ui::ExpoDialog * ui;
    ModelData & model;
    GeneralSettings & generalSettings;
    FirmwareInterface * firmware;
    ExpoData * ed;
    char * inputName;
    GVarGroup * gvWeightGroup;
    GVarGroup * gvOffsetGroup;
    CurveGroup * curveGroup;
    ModelPrinter modelPrinter;
};

#endif // EXPODIALOG_H
