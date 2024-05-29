#ifndef ICONES_H
#define ICONES_H

#include <QWidget>

namespace Ui {
class Icones;
}

class Icones : public QWidget
{
    Q_OBJECT

public:
    explicit Icones(QWidget *parent = nullptr);
    ~Icones();

private slots:
    void on_salvarAlteracoes1PushButton_clicked();

    void on_cancelar1PushButton_clicked();

    void on_salvarAlteracoes2PushButton_clicked();

    void on_cancelar2PushButton_clicked();

private:
    Ui::Icones *ui;
    void resetLayout(QLayout* apLayout);

    void setupIcones();
    void restauraIconesDefault();
};

#endif // ICONES_H
