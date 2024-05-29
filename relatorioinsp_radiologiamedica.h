#ifndef RELATORIOINSP_RADIOLOGIAMEDICA_H
#define RELATORIOINSP_RADIOLOGIAMEDICA_H

#include <QWidget>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "customcheckbox.h"

namespace Ui {
class RelatorioInsp_RadiologiaMedica;
}

class RelatorioInsp_RadiologiaMedica : public QWidget
{
    Q_OBJECT

public:
    explicit RelatorioInsp_RadiologiaMedica(QWidget *parent = nullptr);
    ~RelatorioInsp_RadiologiaMedica();

    QList<CustomCheckBox*> listaCustomCheckBoxOnLayout;

private slots:
    void resetLayout(QLayout* apLayout);
    void readConfig();
    void on_pessoaFisicaPesquisaCheckBox_stateChanged();
    void on_pessoaJuridicaPesquisaCheckBox_stateChanged();
    void on_pessoaFisicaEstabCheckBox_stateChanged();
    void on_pessoaJuridicaEstabCheckBox_stateChanged();
    void on_listaRoteiroComboBox_currentIndexChanged(int index);
    void on_pesquisaRoteiroLineEdit_textChanged(const QString &arg1);
    void on_pesquisaRoteiroLineEdit_editingFinished();
    void on_pesquisarIrregularidadePushButton_clicked();
    void on_densitometriaOsseaGroupBox_clicked();
    void on_litotripsiaGroupBox_clicked();
    void on_mamografiaGroupBox_clicked();
    void on_radiologiaComFluoroscopiaGroupBox_clicked();
    void on_radiologiaConvencionalGroupBox_clicked();
    void on_radiologiaIntervencionistaGroupBox_clicked();
    void on_ressonanciaMagneticaGroupBox_clicked();
    void on_tomografiaComputadorizadaGroupBox_clicked();
    void on_ultrassonografiaGroupBox_clicked();
    void on_adicionarEquipamentoDensitometriaPushButton_clicked();
    void on_removerEquipamentoDensitometriaPushButton_clicked();
    void on_adicionarReferenciaPushButton_clicked();
    void on_removerReferenciaPushButton_clicked();
    void on_limparNormativasPushButton_clicked();
    void on_upNormativasPushButton_clicked();
    void on_downNormativasPushButton_clicked();
    void on_servicoDensitometriaPushButton_clicked();
    void on_servicoLitotripsiaPushButton_clicked();
    void on_servicoMamografiaPushButton_clicked();
    void on_servicoRadiologiaComFluoroscopiaPushButton_clicked();
    void on_servicoRadiologiaConvencionalPushButton_clicked();
    void on_servicoRadiologiaIntervencionistaPushButton_clicked();
    void on_servicoRessonanciaMagneticaPushButton_clicked();
    void on_servicoTomografiaComputadorizadaPushButton_clicked();
    void on_servicoUltrassonografiaPushButton_clicked();

private:
    Ui::RelatorioInsp_RadiologiaMedica *ui;
    QStringList listaRoteiros;
};

#endif // RELATORIOINSP_RADIOLOGIAMEDICA_H
