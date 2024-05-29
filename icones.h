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

private:
    Ui::Icones *ui;

    void setupIcones();
};

#endif // ICONES_H
