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

    // Exibe logotipo
    QFrame *logoFrame = new QFrame;
    logoFrame->setStyleSheet("image: url(:/imagens/RadShield-Png.png);");
    QHBoxLayout *hboxLogo = new QHBoxLayout;
    hboxLogo->addWidget(logoFrame);
    vboxCentral->addLayout(hboxLogo);

    // Acrescenta opções na toolbar
    QMenu *menuRelatorioInspecao = new QMenu();
    menuRelatorioInspecao->addAction(ui->actionRelatorioHemodinamica);
    menuRelatorioInspecao->addAction(ui->actionRelatorioMedicinaNuclear);
    menuRelatorioInspecao->addAction(ui->actionRelatorioRadiologiaMedica);
    menuRelatorioInspecao->addAction(ui->actionRelatorioRadiologiaOdontologica);
    menuRelatorioInspecao->addAction(ui->actionRelatorioRadioterapia);

    QToolButton* toolButtonRelatorioInspecao = new QToolButton();
    toolButtonRelatorioInspecao->setMenu(menuRelatorioInspecao);
    toolButtonRelatorioInspecao->setPopupMode(QToolButton::InstantPopup);
    toolButtonRelatorioInspecao->setIcon(QIcon(":/imagens/icon-edit-file.png"));
    toolButtonRelatorioInspecao->setToolTip("Novo Relatório de Inspeção");

    QMenu *menuPAS = new QMenu();
    menuPAS->addAction(ui->actionBrancoAutoInfracaoRitoSumarissimo);
    menuPAS->addSeparator();
    menuPAS->addAction(ui->actionBrancoAutoInfracaoRitoAnaliseFiscal);
    menuPAS->addAction(ui->actionPASTermoColetaAmostras);
    menuPAS->addSeparator();
    menuPAS->addAction(ui->actionPASTermoInterdicaoCautelarEstabelecimentos);
    menuPAS->addAction(ui->actionPASTermoInterdicaoCautelarProdutos);
    menuPAS->addAction(ui->actionPASTermoInterdicaoCautelarProdutosSemAutuacao);
    menuPAS->addAction(ui->actionPASTermoInutilizacaoImediataProdutos);
    menuPAS->addSeparator();
    menuPAS->addAction(ui->actionPASTermoDesinterdicaoEstabelecimentos);
    menuPAS->addAction(ui->actionPASTermoDesinterdicaoProdutos);
    menuPAS->addSeparator();
    menuPAS->addAction(ui->actionPASNotificacaoImposicaoPenalidadeProcedenciaAutuacao);
    menuPAS->addAction(ui->actionPASNotificacaoImposicaoPenalidadeParcialProcedenciaAutuacao);
    menuPAS->addAction(ui->actionPASNotificacaoImposicaoPenaMulta);
    menuPAS->addSeparator();
    menuPAS->addAction(ui->actionPASNotificacaoDesprovimentoRecurso);
    menuPAS->addAction(ui->actionPASNotificacaoParcialProvimentoRecurso);
    menuPAS->addSeparator();
    menuPAS->addAction(ui->actionPASNotificacaoDecisaoFinal);
    menuPAS->addAction(ui->actionPASNotificacaoPagamentoMultaAposDecisaoFinal);
    menuPAS->addAction(ui->actionPASTermoApreensaoInutilizacaoAposDecisaoFinal);

    QToolButton* toolButtonPAS = new QToolButton();
    toolButtonPAS->setMenu(menuPAS);
    toolButtonPAS->setPopupMode(QToolButton::InstantPopup);
    toolButtonPAS->setIcon(QIcon(":/imagens/icon-alert.png"));
    toolButtonPAS->setToolTip("Novo Documento Avulso de Processo Administrativo Sanitário");

    ui->toolBarPrincipal->addWidget(toolButtonRelatorioInspecao);
    ui->toolBarPrincipal->addWidget(toolButtonPAS);
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
    ui->statusbar->showMessage("Relatório de Inspeção Sanitária - Serviço de Radiologia Médica");
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
    const QString sobre = "<p><strong>Versão</strong>: 1.0.0 (Compilado em 26/02/2024)</p>"
                                 "<p>Este <em>software</em> foi desenvolvido pelo Físico <strong>Márcio Ceconi</strong>,"
                                 "da Vigilância Sanitária da 14ª CRS (Santa Rosa), empregando a linguagem de programação "
                                 "C++, o <em>framework</em> Qt (versão 6.6.1) e o IDE Qt Creator (versão 12.0.1).</p>"
                                 "<p>Para maiores informações, entre em contato com o desenvolvedor:<br>"
                                 "E-mail: <em>marcio-ceconi@saude.rs.gov.br</em><br>"
                                 "Telefone: +55 (055) 3512-5277 ramal 139<br>"
                                 "<em>Whatsapp</em>: +55 (055) 99976-4702</p>"
                                 "<p>O código-fonte deste <em>software</em> está disponível no GitHub:<br><a href=\"https://github.com/marcioceconi/VigilanciaSanitaria\">https://github.com/marcioceconi/VigilanciaSanitaria</a></p>"
                                 "<p>Todos os ícones utilizados neste software foram obtidos de <a href=\"https://icons8.com/\">Icons8</a>, sob a licença \"<a href=\"https://intercom.help/icons8-7fb7577e8170/en/articles/5534926-universal-multimedia-licensing-agreement-for-icons8\"><em>Universal Multimedia License Agreement for Icons8</em></a>\"<br>(<strong><em>Icons by <a href=\"https://icons8.com/\">Icons8</a></em></strong>)</p>";
    QMessageBox::about(this, QString("Sobre este programa"), sobre);
}

// Botão sobre o Qt
void MainWindow::on_actionSobreQt_triggered()
{
    QMessageBox::aboutQt(this);
}

// Botão Licença
void MainWindow::on_actionLicenca_triggered()
{
    const QString licenca = "<p>Este programa é um software livre: você pode redistribuí-lo e/ou modificá-lo sob os termos da Licença Pública Geral GNU, conforme publicado pela Free Software Foundation, seja a versão 3 da Licença ou (a seu critério) qualquer versão posterior.</p>"
                            "<p>Este programa é distribuído na esperança de que seja útil, mas SEM QUALQUER GARANTIA; sem a garantia implícita de COMERCIALIZAÇÃO OU ADEQUAÇÃO A UM DETERMINADO PROPÓSITO. Veja a Licença Pública Geral GNU para obter mais detalhes.</p>"
                            "<p>Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este programa. Se não, veja <a href=\"https://www.gnu.org/licenses\">https://www.gnu.org/licenses/</a>.</p>"
                            "<br><br>"
                            "<p><em>This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.</em></p>"
                            "<p><em>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.</em></p>"
                            "<p><em>You should have received a copy of the GNU General Public License along with this program.  If not, see </em><a href=\"https://www.gnu.org/licenses/\">https://www.gnu.org/licenses/</a>.</p>";
    QMessageBox::about(this, QString("Licença"), licenca);
}

// Botão Sair
void MainWindow::on_actionSair_triggered()
{
    close();
}


void MainWindow::on_actionResetar_Layout_triggered()
{
    resetLayout(vboxCentral);

    // Exibe logotipo
    QFrame *logoFrame = new QFrame;
    logoFrame->setStyleSheet("image: url(:/imagens/RadShield-Png.png);");
    QHBoxLayout *hboxLogo = new QHBoxLayout;
    hboxLogo->addWidget(logoFrame);
    vboxCentral->addLayout(hboxLogo);
}

// Altera os ícones do software
void MainWindow::on_actionAlterarIcones_triggered()
{
    resetLayout(vboxCentral);
    widgetIcones = new Icones();
    vboxCentral->addWidget(widgetIcones);
    ui->statusbar->showMessage("Alterar Ícones");
}

