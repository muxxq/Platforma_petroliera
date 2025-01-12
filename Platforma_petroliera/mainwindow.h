#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include "Simulare.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Simulare simulare;
    QTableWidget* tablePlatforme;
    QTableWidget* tableDerivate;

    void setupUI();
    void updateTables();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void onAddPlatforma();
    void onAddDerivat();
    void onSimuleazaZi();
};

#endif // MAINWINDOW_H
