#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFrame>
#include <QToolButton>
#include <QWidgetAction>

#include "relatorioinsp_radiologiamedica.h"
#include "icones.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVBoxLayout *vboxCentral;

    RelatorioInsp_RadiologiaMedica *widgetRelatorioInspRadiologiaMedica;
    Icones *widgetIcones;

private slots:
    void resetLayout(QLayout* apLayout);
    void on_actionRelatorioRadiologiaMedica_triggered();
    void on_actionSalvar_triggered();
    void on_actionDesfazer_triggered();
    void on_actionRefazer_triggered();
    void on_actionRecortar_triggered();
    void on_actionCopiar_triggered();
    void on_actionColar_triggered();
    void on_actionSobre_triggered();
    void on_actionSobreQt_triggered();
    void on_actionLicenca_triggered();
    void on_actionSair_triggered();
    void on_actionResetar_Layout_triggered();

    void on_actionAlterarIcones_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
