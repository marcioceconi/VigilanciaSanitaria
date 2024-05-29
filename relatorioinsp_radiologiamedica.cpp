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

    // Configura ícones iniciais
    ui->servicoDensitometriaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->densitometriaOsseaGroupBox->setVisible(false);
    ui->servicoLitotripsiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->litotripsiaGroupBox->setVisible(false);
    ui->servicoMamografiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->mamografiaGroupBox->setVisible(false);
    ui->servicoRadiologiaComFluoroscopiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->radiologiaComFluoroscopiaGroupBox->setVisible(false);
    ui->servicoRadiologiaConvencionalPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->radiologiaConvencionalGroupBox->setVisible(false);
    ui->servicoRadiologiaIntervencionistaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->radiologiaIntervencionistaGroupBox->setVisible(false);
    ui->servicoRessonanciaMagneticaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->ressonanciaMagneticaGroupBox->setVisible(false);
    ui->servicoTomografiaComputadorizadaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->tomografiaComputadorizadaGroupBox->setVisible(false);
    ui->servicoUltrassonografiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
    ui->ultrassonografiaGroupBox->setVisible(false);

    // Inicializa os campos de data
    ui->dataInicioInspecaoDateEdit->setDate(QDate::currentDate());
    ui->dataTerminoInspecaoDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraDensitometriaOsseaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraLitotripsiaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraMamografiaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraRadiologiaComFluoroscopiaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraRadiologiaConvencionalDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraRadiologiaIntervencionistaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraRessonanciaMagneticaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraTomografiaComputadorizadaDateEdit->setDate(QDate::currentDate());
    ui->validadeAlvaraUltrassonografiaDateEdit->setDate(QDate::currentDate());
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
    listaCustomCheckBoxOnLayout.clear();
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
                    QLabel *novoLabel = new QLabel();
                    novoLabel->setText(colunasRoteiro[1]);
                    novoLabel->setFixedHeight(31);
                    novoLabel->setStyleSheet("QLabel {font: 700 10pt \"Segoe UI\"; background-color: rgb(112, 255, 148); border: 1px solid black; border-radius: 5px}");
                    novoLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    ui->itensRoteiroGroupBox->layout()->addWidget(novoLabel);
                } else if (colunasRoteiro[0] == "item") {
                    CustomCheckBox *novoCustomCheckBox = new CustomCheckBox(this);
                    ui->itensRoteiroGroupBox->layout()->addWidget(novoCustomCheckBox);
                    novoCustomCheckBox->alteraTexto(colunasRoteiro[1]);
                    listaCustomCheckBoxOnLayout.append(novoCustomCheckBox);
                }
                else {
                    return;
                }
            }
        }
        arqRoteiro.close();
    }
}

// Se o campo de pesquisa estiver em branco, reexibe todos os itens do Roteiro de Inspeção
void RelatorioInsp_RadiologiaMedica::on_pesquisaRoteiroLineEdit_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        for (int i=0; i<listaCustomCheckBoxOnLayout.count(); i++) {
            if (!listaCustomCheckBoxOnLayout[i]->isVisible()) {
                listaCustomCheckBoxOnLayout[i]->setVisible(true);
            }
        }
    } else {
        return;
    }
}

// Pesquisa no Roteiro de Inspeção se for pressionado Enter
void RelatorioInsp_RadiologiaMedica::on_pesquisaRoteiroLineEdit_editingFinished()
{
    QString arg1 = ui->pesquisaRoteiroLineEdit->text().toLower();
    if (listaCustomCheckBoxOnLayout.count() == 0) {
        return;
    } else {
        if (arg1.isEmpty()) {
            for (int i=0; i<listaCustomCheckBoxOnLayout.count(); i++) {
                if (!listaCustomCheckBoxOnLayout[i]->isVisible()) {
                    listaCustomCheckBoxOnLayout[i]->setVisible(true);
                }
            }
        } else {
            for (int i=0; i<listaCustomCheckBoxOnLayout.count(); i++) {
                if (listaCustomCheckBoxOnLayout[i]->readLabelTexto().toLower().contains(arg1)) {
                    if (!listaCustomCheckBoxOnLayout[i]->isVisible()) {
                        listaCustomCheckBoxOnLayout[i]->setVisible(true);
                    }
                } else {
                    if (listaCustomCheckBoxOnLayout[i]->isVisible()) {
                        listaCustomCheckBoxOnLayout[i]->setVisible(false);
                    }
                }
            }
        }
    }
}

// Pesquisa no Roteiro de Inspeção se for clicado no botão "Pesquisar"
void RelatorioInsp_RadiologiaMedica::on_pesquisarIrregularidadePushButton_clicked()
{
    on_pesquisaRoteiroLineEdit_editingFinished();
}

void RelatorioInsp_RadiologiaMedica::on_densitometriaOsseaGroupBox_clicked()
{
    if (ui->densitometriaOsseaGroupBox->isChecked()) {
        ui->validadeAlvaraDensitometriaOsseaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraDensitometriaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraDensitometriaLineEdit->clear();
        ui->codigoCEVSAlvaraDensitometriaOsseaLineEdit->clear();
        ui->validadeAlvaraDensitometriaOsseaDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_litotripsiaGroupBox_clicked()
{
    if (ui->litotripsiaGroupBox->isChecked()) {
        ui->validadeAlvaraLitotripsiaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraLitotripsiaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraLitotripsiaLineEdit->clear();
        ui->codigoCEVSAlvaraLitotripsiaLineEdit->clear();
        ui->validadeAlvaraLitotripsiaDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_mamografiaGroupBox_clicked()
{
    if (ui->mamografiaGroupBox->isChecked()) {
        ui->validadeAlvaraMamografiaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraMamografiaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraMamografiaLineEdit->clear();
        ui->codigoCEVSAlvaraMamografiaLineEdit->clear();
        ui->validadeAlvaraMamografiaDateEdit->setDate(QDate(2000,1,1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_radiologiaComFluoroscopiaGroupBox_clicked()
{
    if (ui->radiologiaComFluoroscopiaGroupBox->isChecked()) {
        ui->validadeAlvaraRadiologiaComFluoroscopiaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraRadiologiaComFluoroscopiaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraRadiologiaComFluoroscopiaLineEdit->clear();
        ui->codigoCEVSAlvaraRadiologiaComFluoroscopiaLineEdit->clear();
        ui->validadeAlvaraRadiologiaComFluoroscopiaDateEdit->setDate(QDate(2000,1,1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_radiologiaConvencionalGroupBox_clicked()
{
    if (ui->radiologiaConvencionalGroupBox->isChecked()) {
        ui->validadeAlvaraRadiologiaConvencionalDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraRadiologiaConvencionalLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraRadiologiaConvencionalLineEdit->clear();
        ui->codigoCEVSAlvaraRadiologiaConvencionalLineEdit->clear();
        ui->validadeAlvaraRadiologiaConvencionalDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_radiologiaIntervencionistaGroupBox_clicked()
{
    if (ui->radiologiaIntervencionistaGroupBox->isChecked()) {
        ui->validadeAlvaraRadiologiaIntervencionistaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraRadiologiaIntervencionistaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraRadiologiaIntervencionistaLineEdit->clear();
        ui->codigoCEVSAlvaraRadiologiaIntervencionistaLineEdit->clear();
        ui->validadeAlvaraRadiologiaIntervencionistaDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_ressonanciaMagneticaGroupBox_clicked()
{
    if (ui->ressonanciaMagneticaGroupBox->isChecked()) {
        ui->validadeAlvaraRessonanciaMagneticaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraRessonanciaMagneticaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraRessonanciaMagneticaLineEdit->clear();
        ui->codigoCEVSAlvaraRessonanciaMagneticaLineEdit->clear();
        ui->validadeAlvaraRessonanciaMagneticaDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_tomografiaComputadorizadaGroupBox_clicked()
{
    if (ui->tomografiaComputadorizadaGroupBox->isChecked()) {
        ui->validadeAlvaraTomografiaComputadorizadaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraTomografiaComputadorizadaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraTomografiaComputadorizadaLineEdit->clear();
        ui->codigoCEVSAlvaraTomografiaComputadorizadaLineEdit->clear();
        ui->validadeAlvaraTomografiaComputadorizadaDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_ultrassonografiaGroupBox_clicked()
{
    if (ui->ultrassonografiaGroupBox->isChecked()) {
        ui->validadeAlvaraUltrassonografiaDateEdit->setDate(QDate::currentDate());
        ui->protocoloAlvaraUltrassonografiaLineEdit->setFocus();
    } else {
        ui->protocoloAlvaraUltrassonografiaLineEdit->clear();
        ui->codigoCEVSAlvaraUltrassonografiaLineEdit->clear();
        ui->validadeAlvaraUltrassonografiaDateEdit->setDate(QDate(2000, 1, 1));
    }
}


void RelatorioInsp_RadiologiaMedica::on_adicionarEquipamentoDensitometriaPushButton_clicked()
{
    if (!ui->equipamentoDensitometriaTableWidget->hasFocus()) ui->equipamentoDensitometriaTableWidget->setFocus();
    if (ui->equipamentoDensitometriaTableWidget->rowCount() != 0) {
        ui->equipamentoDensitometriaTableWidget->insertRow(ui->equipamentoDensitometriaTableWidget->currentRow()+1);
    } else {
        ui->equipamentoDensitometriaTableWidget->insertRow(0);
    }
}


void RelatorioInsp_RadiologiaMedica::on_removerEquipamentoDensitometriaPushButton_clicked()
{
    if (!ui->equipamentoDensitometriaTableWidget->hasFocus()) ui->equipamentoDensitometriaTableWidget->setFocus();
    if (ui->equipamentoDensitometriaTableWidget->rowCount() != 0) {
        ui->equipamentoDensitometriaTableWidget->removeRow(ui->equipamentoDensitometriaTableWidget->currentRow());
    } else {
        return;
    }
}


void RelatorioInsp_RadiologiaMedica::on_adicionarReferenciaPushButton_clicked()
{
    if (!ui->normativasTableWidget->hasFocus()) ui->normativasTableWidget->setFocus();
    if (ui->normativasTableWidget->rowCount() != 0) {
        ui->normativasTableWidget->insertRow(ui->normativasTableWidget->currentRow()+1);
    } else {
        ui->normativasTableWidget->insertRow(0);
    }
}


void RelatorioInsp_RadiologiaMedica::on_removerReferenciaPushButton_clicked()
{
    if (!ui->normativasTableWidget->hasFocus()) ui->normativasTableWidget->setFocus();
    if (ui->normativasTableWidget->rowCount() != 0) {
        ui->normativasTableWidget->removeRow(ui->normativasTableWidget->currentRow());
    } else {
        return;
    }
}


void RelatorioInsp_RadiologiaMedica::on_limparNormativasPushButton_clicked()
{
    for (int i=ui->normativasTableWidget->rowCount(); i>=0; i--) {
        ui->normativasTableWidget->removeRow(i);
    }
}


void RelatorioInsp_RadiologiaMedica::on_upNormativasPushButton_clicked()
{

}


void RelatorioInsp_RadiologiaMedica::on_downNormativasPushButton_clicked()
{

}


void RelatorioInsp_RadiologiaMedica::on_servicoDensitometriaPushButton_clicked()
{
    if (ui->servicoDensitometriaPushButton->isChecked()) {
        ui->servicoDensitometriaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->densitometriaOsseaGroupBox->setVisible(true);
    } else {
        ui->servicoDensitometriaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->densitometriaOsseaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoLitotripsiaPushButton_clicked()
{
    if (ui->servicoLitotripsiaPushButton->isChecked()) {
        ui->servicoLitotripsiaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->litotripsiaGroupBox->setVisible(true);
    } else {
        ui->servicoLitotripsiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->litotripsiaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoMamografiaPushButton_clicked()
{
    if (ui->servicoMamografiaPushButton->isChecked()) {
        ui->servicoMamografiaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->mamografiaGroupBox->setVisible(true);
    } else {
        ui->servicoMamografiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->mamografiaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoRadiologiaComFluoroscopiaPushButton_clicked()
{
    if (ui->servicoRadiologiaComFluoroscopiaPushButton->isChecked()) {
        ui->servicoRadiologiaComFluoroscopiaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->radiologiaComFluoroscopiaGroupBox->setVisible(true);
    } else {
        ui->servicoRadiologiaComFluoroscopiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->radiologiaComFluoroscopiaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoRadiologiaConvencionalPushButton_clicked()
{
    if (ui->servicoRadiologiaConvencionalPushButton->isChecked()) {
        ui->servicoRadiologiaConvencionalPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->radiologiaConvencionalGroupBox->setVisible(true);
    } else {
        ui->servicoRadiologiaConvencionalPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->radiologiaConvencionalGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoRadiologiaIntervencionistaPushButton_clicked()
{
    if (ui->servicoRadiologiaIntervencionistaPushButton->isChecked()) {
        ui->servicoRadiologiaIntervencionistaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->radiologiaIntervencionistaGroupBox->setVisible(true);
    } else {
        ui->servicoRadiologiaIntervencionistaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->radiologiaIntervencionistaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoRessonanciaMagneticaPushButton_clicked()
{
    if (ui->servicoRessonanciaMagneticaPushButton->isChecked()) {
        ui->servicoRessonanciaMagneticaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->ressonanciaMagneticaGroupBox->setVisible(true);
    } else {
        ui->servicoRessonanciaMagneticaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->ressonanciaMagneticaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoTomografiaComputadorizadaPushButton_clicked()
{
    if (ui->servicoTomografiaComputadorizadaPushButton->isChecked()) {
        ui->servicoTomografiaComputadorizadaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->tomografiaComputadorizadaGroupBox->setVisible(true);
    } else {
        ui->servicoTomografiaComputadorizadaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->tomografiaComputadorizadaGroupBox->setVisible(false);
    }
}


void RelatorioInsp_RadiologiaMedica::on_servicoUltrassonografiaPushButton_clicked()
{
    if (ui->servicoUltrassonografiaPushButton->isChecked()) {
        ui->servicoUltrassonografiaPushButton->setIcon(QIcon(":/imagens/icon-checked-square-white.png"));
        ui->ultrassonografiaGroupBox->setVisible(true);
    } else {
        ui->servicoUltrassonografiaPushButton->setIcon(QIcon(":/imagens/icon-unchecked-square-white.png"));
        ui->ultrassonografiaGroupBox->setVisible(false);
    }
}

