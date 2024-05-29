#ifndef CUSTOMCHECKBOX_H
#define CUSTOMCHECKBOX_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class CustomCheckBox;
}

class CustomCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit CustomCheckBox(QWidget *parent = nullptr);
    ~CustomCheckBox();

    void alteraTexto(QString texto);
    bool getCheckState();
    QString readLabelTexto();

private:
    Ui::CustomCheckBox *ui;

    void atualizaEstado(bool entrada);
    bool checkStateLabel = false;

private:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CUSTOMCHECKBOX_H
