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

void Icones::setupIcones() {
    ui->frameNovoRelatorioInspecao->setStyleSheet("image: url(:/imagens/icon-new-file.png);");
    ui->frameNovoDocumentoPAS->setStyleSheet("image: url(:/imagens/icon-edit-file.png);");
    ui->frameSalvar->setStyleSheet("image: url(:/imagens/icon-save.png);");
    ui->frameSair->setStyleSheet("image: url(:/imagens/icon-quit.png);");
    ui->frameDesfazer->setStyleSheet("image: url(:/imagens/icons8-undo-96.png);");
    ui->frameRefazer->setStyleSheet("image: url(:/imagens/icon-redo.png);");
    ui->frameRecortar->setStyleSheet("image: url(:/imagens/icon-cut.png);");
    ui->frameCopiar->setStyleSheet("image: url(:/imagens/icon-copy.png);");
    ui->frameColar->setStyleSheet("image: url(:/imagens/icon-paste.png);");
    ui->frameEstabelecimentos->setStyleSheet("image: url(:/imagens/icon-address.png);");
    ui->frameVigilanciaSanitaria->setStyleSheet("image: url(:/imagens/icon-contacts.png);");
    ui->frameCNAE->setStyleSheet("image: url();");
    ui->frameAlterarIcones->setStyleSheet("image: url(:/imagens/icon-settings.png);");
    ui->frameResetarLayout->setStyleSheet("image: url(:/imagens/icon-circular-arrows.png);");
    ui->frameSobre->setStyleSheet("image: url(:/imagens/RadShield-Png.png);");
    ui->frameLicenca->setStyleSheet("image: url(:/imagens/icon-document.png);");
}
