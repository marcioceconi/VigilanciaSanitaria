#include "icones.h"
#include "ui_icones.h"

Icones::Icones(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Icones)
{
    ui->setupUi(this);

    setupIcones();
}

Icones::~Icones()
{
    delete ui;
}

// Restaura todos os ícones para as imagens originais
void Icones::restauraIconesDefault() {
    ui->frameQToolButtonRelatorioInspecao->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameQToolButtonPAS->setStyleSheet("image: url(:/imagens/icon-alert.png);");
    ui->frameRelatorioInspecaoHemodinamica->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoMedicinaNuclear->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoRadiologiaMedica->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoRadiologiaOdontologica->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoRadioterapia->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameAutoInfracaoRitoSumarissimo->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameAutoInfracaoRitoAnaliseFiscal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoColetaAmostras->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInterdicaoCautelarEstabelecimento->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInterdicaoCautelarProdutos->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInterdicaoCautelarProdutosSemAutuacao->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInutilizacaoImediataProdutosComLaudoPericial->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoDesinterdicaoEstabelecimento->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoDesinterdicaoProdutos->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoImposicaoPenalidadeParcialProcedencia->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoImposicaoPenalidadeProcedencia->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoImposicaoPenaMulta->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoDesprovimentoRecurso->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoParcialProvimentoRecurso->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoDecisaoFinal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoPagamentoMultaAposDecisaoFinal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoApreensaoInutilizacaoAposDecisaoFinal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameSalvar->setStyleSheet("image: url(:/imagens/icon-save.png);");
    ui->frameSair->setStyleSheet("image: url(:/imagens/icon-quit.png);");
    ui->frameDesfazer->setStyleSheet("image: url(:/imagens/icon-undo.png);");
    ui->frameRefazer->setStyleSheet("image: url(:/imagens/icon-redo.png);");
    ui->frameRecortar->setStyleSheet("image: url(:/imagens/icon-cut.png);");
    ui->frameCopiar->setStyleSheet("image: url(:/imagens/icon-copy.png);");
    ui->frameColar->setStyleSheet("image: url(:/imagens/icon-paste.png);");
    ui->frameEstabelecimentos->setStyleSheet("image: url(:/imagens/icon-address.png);");
    ui->frameVigilanciaSanitaria->setStyleSheet("image: url(:/imagens/icon-contacts.png);");
    ui->frameCNAE->setStyleSheet("image: url(:/imagens/icon-banknotes.png);");
    ui->frameAlterarIcones->setStyleSheet("image: url(:/imagens/icon-settings.png);");
    ui->frameResetarLayout->setStyleSheet("image: url(:/imagens/icon-circular-arrows.png);");
    ui->frameSobre->setStyleSheet("image: url(:/imagens/RadShield-Png.png);");
    ui->frameLicenca->setStyleSheet("image: url(:/imagens/icon-document.png);");
}

void Icones::setupIcones() {
    ui->frameQToolButtonRelatorioInspecao->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameQToolButtonPAS->setStyleSheet("image: url(:/imagens/icon-alert.png);");
    ui->frameRelatorioInspecaoHemodinamica->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoMedicinaNuclear->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoRadiologiaMedica->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoRadiologiaOdontologica->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameRelatorioInspecaoRadioterapia->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameAutoInfracaoRitoSumarissimo->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameAutoInfracaoRitoAnaliseFiscal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoColetaAmostras->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInterdicaoCautelarEstabelecimento->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInterdicaoCautelarProdutos->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInterdicaoCautelarProdutosSemAutuacao->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoInutilizacaoImediataProdutosComLaudoPericial->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoDesinterdicaoEstabelecimento->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoDesinterdicaoProdutos->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoImposicaoPenalidadeParcialProcedencia->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoImposicaoPenalidadeProcedencia->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoImposicaoPenaMulta->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoDesprovimentoRecurso->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoParcialProvimentoRecurso->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoDecisaoFinal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameNotificacaoPagamentoMultaAposDecisaoFinal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameTermoApreensaoInutilizacaoAposDecisaoFinal->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameSalvar->setStyleSheet("image: url(:/imagens/icon-save.png);");
    ui->frameSair->setStyleSheet("image: url(:/imagens/icon-quit.png);");
    ui->frameDesfazer->setStyleSheet("image: url(:/imagens/icon-undo.png);");
    ui->frameRefazer->setStyleSheet("image: url(:/imagens/icon-redo.png);");
    ui->frameRecortar->setStyleSheet("image: url(:/imagens/icon-cut.png);");
    ui->frameCopiar->setStyleSheet("image: url(:/imagens/icon-copy.png);");
    ui->frameColar->setStyleSheet("image: url(:/imagens/icon-paste.png);");
    ui->frameEstabelecimentos->setStyleSheet("image: url(:/imagens/icon-address.png);");
    ui->frameVigilanciaSanitaria->setStyleSheet("image: url(:/imagens/icon-contacts.png);");
    ui->frameCNAE->setStyleSheet("image: url(:/imagens/icon-banknotes.png);");
    ui->frameAlterarIcones->setStyleSheet("image: url(:/imagens/icon-settings.png);");
    ui->frameResetarLayout->setStyleSheet("image: url(:/imagens/icon-circular-arrows.png);");
    ui->frameSobre->setStyleSheet("image: url(:/imagens/RadShield-Png.png);");
    ui->frameLicenca->setStyleSheet("image: url(:/imagens/icon-document.png);");
}

// Apaga todos os itens de um layout
void Icones::resetLayout(QLayout* apLayout)
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

void Icones::on_salvarAlteracoes1PushButton_clicked()
{

}

void Icones::on_salvarAlteracoes2PushButton_clicked()
{

}

void Icones::on_cancelar1PushButton_clicked()
{
    resetLayout(this->layout());
}

void Icones::on_cancelar2PushButton_clicked()
{
    resetLayout(this->layout());
}

