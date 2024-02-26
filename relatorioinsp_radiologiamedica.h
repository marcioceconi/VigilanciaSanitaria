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

private slots:
    void resetLayout(QLayout* apLayout);
    void readConfig();
    void on_pessoaFisicaPesquisaCheckBox_stateChanged();
    void on_pessoaJuridicaPesquisaCheckBox_stateChanged();
    void on_pessoaFisicaEstabCheckBox_stateChanged();
    void on_pessoaJuridicaEstabCheckBox_stateChanged();
    void on_listaRoteiroComboBox_currentIndexChanged(int index);

private:
    Ui::RelatorioInsp_RadiologiaMedica *ui;

    QStringList listaRoteiros;
};

#endif // RELATORIOINSP_RADIOLOGIAMEDICA_H
