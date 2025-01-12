#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setupUI();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    setWindowTitle("Simulare Platformă Petrolieră");
    resize(800, 600);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    // Tabele pentru platforme și derivate
    tablePlatforme = new QTableWidget(0, 3, this);
    tablePlatforme->setHorizontalHeaderLabels({ "Nume", "Stoc Curent", "Capacitate Maxima" });
    layout->addWidget(new QLabel("Platforme:"));
    layout->addWidget(tablePlatforme);

    tableDerivate = new QTableWidget(0, 3, this);
    tableDerivate->setHorizontalHeaderLabels({ "Nume", "Cantitate", "Pret" });
    layout->addWidget(new QLabel("Derivate:"));
    layout->addWidget(tableDerivate);

    // Butoane
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* addPlatformaButton = new QPushButton("Adaugă Platformă", this);
    QPushButton* addDerivatButton = new QPushButton("Adaugă Derivat", this);
    QPushButton* simuleazaButton = new QPushButton("Simulează Zi", this);

    connect(addPlatformaButton, &QPushButton::clicked, this, &MainWindow::onAddPlatforma);
    connect(addDerivatButton, &QPushButton::clicked, this, &MainWindow::onAddDerivat);
    connect(simuleazaButton, &QPushButton::clicked, this, &MainWindow::onSimuleazaZi);

    buttonLayout->addWidget(addPlatformaButton);
    buttonLayout->addWidget(addDerivatButton);
    buttonLayout->addWidget(simuleazaButton);
    layout->addLayout(buttonLayout);
}

void MainWindow::onAddPlatforma() {
    QString nume = QInputDialog::getText(this, "Adaugă Platformă", "Numele platformei:");
    double cantitateZilnica = QInputDialog::getDouble(this, "Adaugă Platformă", "Cantitate zilnică:");
    double capacitateMaxima = QInputDialog::getDouble(this, "Adaugă Platformă", "Capacitate maximă:");

    simulare.adaugaPlatforma(Platforma(nume.toStdString(), cantitateZilnica, capacitateMaxima));
    updateTables();
}

void MainWindow::onAddDerivat() {
    QString nume = QInputDialog::getText(this, "Adaugă Derivat", "Numele derivatului:");
    double pret = QInputDialog::getDouble(this, "Adaugă Derivat", "Preț per unitate:");

    simulare.adaugaDerivat(Derivat(nume.toStdString(), pret));
    updateTables();
}

void MainWindow::onSimuleazaZi() {
    simulare.simuleazaZi();
    updateTables();
}

void MainWindow::updateTables() {
    tablePlatforme->setRowCount(0);
    for (const auto& platforma : simulare.getPlatforme()) {
        int row = tablePlatforme->rowCount();
        tablePlatforme->insertRow(row);
        tablePlatforme->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(platforma.getNume())));
        tablePlatforme->setItem(row, 1, new QTableWidgetItem(QString::number(platforma.getStocCurent())));
        tablePlatforme->setItem(row, 2, new QTableWidgetItem(QString::number(platforma.getCapacitateMaxima())));
    }

    tableDerivate->setRowCount(0);
    for (const auto& derivat : simulare.getDerivate()) {
        int row = tableDerivate->rowCount();
        tableDerivate->insertRow(row);
        tableDerivate->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(derivat.getNume())));
        tableDerivate->setItem(row, 1, new QTableWidgetItem(QString::number(derivat.getCantitate())));
        tableDerivate->setItem(row, 2, new QTableWidgetItem(QString::number(derivat.getPret())));
    }
}
