#include "relatorioinsp_radiologiamedica.h"
#include "ui_relatorioinsp_radiologiamedica.h"

RelatorioInsp_RadiologiaMedica::RelatorioInsp_RadiologiaMedica(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RelatorioInsp_RadiologiaMedica)
{
    ui->setupUi(this);

    // Lê arquivo de configurações e preenche QComboBox listaRoteirosComboBox
    readConfig();

    // Define o Roteiro de Inspeção para Radiologia Convencional [--APAGAR--]
    ui->listaRoteiroComboBox->setCurrentIndex(1);
}

RelatorioInsp_RadiologiaMedica::~RelatorioInsp_RadiologiaMedica()
{
    delete ui;
}

void RelatorioInsp_RadiologiaMedica::resetLayout(QLayout* apLayout)
{
    QLayoutItem *vpItem;
    while ((vpItem = apLayout->takeAt(0)) != 0)  {
        if (vpItem->layout()) {
            resetLayout(vpItem->layout());
            vpItem->layout()->deleteLater();
        }
        if (vpItem->widget()) {
            vpItem->widget()->deleteLater();
        }
        delete vpItem;
    }
}

void RelatorioInsp_RadiologiaMedica::on_pessoaFisicaPesquisaCheckBox_stateChanged()
{
    ui->cpfPesquisaLineEdit->clear();
    ui->cnpjPesquisaLineEdit->clear();
    if (ui->pessoaFisicaPesquisaCheckBox->isChecked()) {
        if (ui->pessoaJuridicaPesquisaCheckBox->isChecked()) ui->pessoaJuridicaPesquisaCheckBox->setChecked(false);
        ui->cpfPesquisaLineEdit->setEnabled(true);
        ui->cnpjPesquisaLineEdit->setEnabled(false);
        ui->cpfPesquisaLineEdit->setFocus();
    } else {
        ui->cpfPesquisaLineEdit->setEnabled(false);
    }
}

void RelatorioInsp_RadiologiaMedica::on_pessoaJuridicaPesquisaCheckBox_stateChanged()
{
    ui->cpfPesquisaLineEdit->clear();
    ui->cnpjPesquisaLineEdit->clear();
    if (ui->pessoaJuridicaPesquisaCheckBox->isChecked()) {
        if (ui->pessoaFisicaPesquisaCheckBox->isChecked()) ui->pessoaFisicaPesquisaCheckBox->setChecked(false);
        ui->cnpjPesquisaLineEdit->setEnabled(true);
        ui->cpfPesquisaLineEdit->setEnabled(false);
        ui->cnpjPesquisaLineEdit->setFocus();
    } else {
        ui->cnpjPesquisaLineEdit->setEnabled(false);
    }
}

void RelatorioInsp_RadiologiaMedica::on_pessoaFisicaEstabCheckBox_stateChanged()
{
    ui->cpfEstabLineEdit->clear();
    ui->cnpjEstabLineEdit->clear();
    if (ui->pessoaFisicaEstabCheckBox->isChecked()) {
        if (ui->pessoaJuridicaEstabCheckBox->isChecked()) ui->pessoaJuridicaEstabCheckBox->setChecked(false);
        ui->cpfEstabLineEdit->setEnabled(true);
        ui->cnpjEstabLineEdit->setEnabled(false);
        ui->cpfEstabLineEdit->setFocus();
    } else {
        ui->cpfEstabLineEdit->setEnabled(false);
    }
}

void RelatorioInsp_RadiologiaMedica::on_pessoaJuridicaEstabCheckBox_stateChanged()
{
    ui->cpfEstabLineEdit->clear();
    ui->cnpjEstabLineEdit->clear();
    if (ui->pessoaJuridicaEstabCheckBox->isChecked()) {
        if (ui->pessoaFisicaEstabCheckBox->isChecked()) ui->pessoaFisicaEstabCheckBox->setChecked(false);
        ui->cnpjEstabLineEdit->setEnabled(true);
        ui->cpfEstabLineEdit->setEnabled(false);
        ui->cnpjEstabLineEdit->setFocus();
    } else {
        ui->cnpjEstabLineEdit->setEnabled(false);
    }
}

void RelatorioInsp_RadiologiaMedica::readConfig()
{
    listaRoteiros.clear();

    QFile arqConfig("config/config.txt");
    if (!arqConfig.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Erro", arqConfig.errorString());
        return;
    }

    QTextStream in(&arqConfig);

    QStringList colunas;
    while (!in.atEnd()) {
        QString linha = in.readLine();
        colunas.clear();
        colunas = linha.split("|");

        // Se a linha for um Roteiros de Inspeção, então a QStringList colunas deverá conter 3 elementos: 'ROTEIRO|%nomeRoteiro|%pathRoteiro'
        if (colunas[0] == "ROTEIRO" || colunas.count() > 2) {
            listaRoteiros.append(QString("%1|%2").arg(colunas[1]).arg(colunas[2]));
        }
    }

    // Preenche QComboBox listaRoteiroComboBox
    ui->listaRoteiroComboBox->clear();
    ui->listaRoteiroComboBox->addItem(QString("-- Selecione um Roteiro --"));
    for (int i=0; i<listaRoteiros.count(); i++) {
        colunas.clear();
        colunas = listaRoteiros[i].split("|");
        if (colunas.count() > 1) ui->listaRoteiroComboBox->addItem(colunas[0]);
    }

    arqConfig.close();
}

void RelatorioInsp_RadiologiaMedica::on_listaRoteiroComboBox_currentIndexChanged(int index)
{
    resetLayout(ui->itensRoteiroGroupBox->layout());

    if (index == 0) { // Índice zero '--Selecione um Roteiro --', então não executa nenhuma ação
        return;
    } else {
        QStringList colunas;
        colunas = listaRoteiros[index-1].split("|");
        // colunas[0] => Nome do Roteiro
        // colunas[1] => Path do Roteiro

        QFile arqRoteiro(colunas[1]);
        if (!arqRoteiro.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::information(0, "Erro", arqRoteiro.errorString());
            return;
        }
        QTextStream in(&arqRoteiro);
        QStringList colunasRoteiro;
        while (!in.atEnd()) {
            QString linha;
            linha = in.readLine();
            colunasRoteiro.clear();
            colunasRoteiro = linha.split("|");

            if (colunasRoteiro.count() > 1) {
                if (colunasRoteiro[0] == "grupo") {

                } else if (colunasRoteiro[0] == "item") {
                    CustomCheckBox *novoCustomCheckBox = new CustomCheckBox(this);
                    ui->itensRoteiroGroupBox->layout()->addWidget(novoCustomCheckBox);
                    novoCustomCheckBox->alteraTexto(colunasRoteiro[1]);
                }
                else {
                    return;
                }
            }
        }
        arqRoteiro.close();
    }
}

