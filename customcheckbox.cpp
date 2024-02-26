#include "customcheckbox.h"
#include "ui_customcheckbox.h"

CustomCheckBox::CustomCheckBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomCheckBox)
{
    ui->setupUi(this);
}

CustomCheckBox::~CustomCheckBox()
{
    delete ui;
}

void CustomCheckBox::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        checkStateLabel = !checkStateLabel;
    }
    if(checkStateLabel) {
        ui->labelCheck->setStyleSheet("QLabel { image: url(:/imagens/icon-checked-square-green.png); background-color: rgb(186, 224, 189); border: 1px solid black; border-radius: 5px; } "
                                      "QLabel:hover { image: url(:/imagens/icon-checked-square.png); background-color: rgb(152, 204, 253); border: 1px solid black; border-radius: 5px; }");
        ui->labelText->setStyleSheet("QLabel { font: 10pt \"Segoe UI\"; border: 1px solid black; border-radius: 5px; background-color: rgb(186, 224, 189); }"
                                     "QLabel:hover { font: 10pt \"Segoe UI\"; border: 1px solid black; border-radius: 5px; background-color: rgb(152, 204, 253); }");
    } else {
        ui->labelCheck->setStyleSheet("QLabel { image: url(:/imagens/icon-empty.png); background-color: rgb(255, 255, 255); border: 1px solid black; border-radius: 5px; } "
                                      "QLabel:hover { image: url(:/imagens/icon-empty.png); background-color: rgb(152, 204, 253); border: 1px solid black; border-radius: 5px; }");
        ui->labelText->setStyleSheet("QLabel { font: 10pt \"Segoe UI\"; border: 1px solid black; border-radius: 5px; background-color: rgb(255, 255, 255); }"
                                     "QLabel:hover { font: 10pt \"Segoe UI\"; border: 1px solid black; border-radius: 5px; background-color: rgb(152, 204, 253); }");
    }
}

void CustomCheckBox::alteraTexto(QString texto)
{
    ui->labelText->setText(texto);
}

void CustomCheckBox::atualizaEstado(bool entrada)
{
    ui->labelText->setText(QString("Mouse-Event: %1").arg(!entrada));
}

