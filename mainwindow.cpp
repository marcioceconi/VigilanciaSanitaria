#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Define vboxCentral como o layout principal de centralScrollArea
    vboxCentral = new QVBoxLayout;
    ui->centralScrollArea->setLayout(vboxCentral);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Apaga todos os itens de um layout específico
void MainWindow::resetLayout(QLayout* apLayout)
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

// Relatório de Inspeção em Radiologia Médica
void MainWindow::on_actionRelatorioRadiologiaMedica_triggered()
{
    resetLayout(vboxCentral);
    widgetRelatorioInspRadiologiaMedica = new RelatorioInsp_RadiologiaMedica();
    vboxCentral->addWidget(widgetRelatorioInspRadiologiaMedica);
}

// Botão Salvar
void MainWindow::on_actionSalvar_triggered()
{

}

// Botão Desfazer
void MainWindow::on_actionDesfazer_triggered()
{

}

// Botão Refazer
void MainWindow::on_actionRefazer_triggered()
{

}

// Botão Recortar
void MainWindow::on_actionRecortar_triggered()
{

}

// Botão Copiar
void MainWindow::on_actionCopiar_triggered()
{

}

// Botão Colar
void MainWindow::on_actionColar_triggered()
{

}

// Botão Sobre o Programa
void MainWindow::on_actionSobre_triggered()
{
    const QString sobreQString = "<p><strong>Versão</strong>: 1.0.0 (Compilado em 26/02/2024)</p>"
                                 "<p>Este <em>software</em> foi desenvolvido pelo Físico <strong>Márcio Ceconi</strong>,"
                                 "da Vigilância Sanitária da 14ª CRS (Santa Rosa).</p>"
                                 "<p>Para maiores informações, entre em contato com o desenvolvedor através do e-mail"
                                 "<em>marcio-ceconi@saude.rs.gov.br</em> ou <em>Whatsapp</em> (55) 99976-4702</p>";
    QMessageBox::about(this, QString("Sobre este programa"), sobreQString);
}

// Botão sobre o Qt
void MainWindow::on_actionSobreQt_triggered()
{
    QMessageBox::aboutQt(this);
}

// Botão Licença
void MainWindow::on_actionLicenca_triggered()
{

}

// Botão Sair
void MainWindow::on_actionSair_triggered()
{
    close();
}

