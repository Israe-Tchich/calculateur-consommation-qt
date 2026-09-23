#include "mainwindow.h"
#include "Vehicule.h"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Création des éléments
    QLabel *titre = new QLabel("CALCUL DE CONSOMMATION DE CARBURANT");

    QLabel *labelKm = new QLabel("Kilométrage parcouru (km) :");
    lineEditKm = new QLineEdit();
    lineEditKm->setPlaceholderText("Exemple : 250");

    QLabel *labelLitres = new QLabel("Essence utilisée (litres) :");
    lineEditLitres = new QLineEdit();
    lineEditLitres->setPlaceholderText("Exemple : 20");

    btnCalculer = new QPushButton("Calculer");

    labelResultat = new QLabel("Consommation : -- L/100 km");

    btnReset = new QPushButton("Réinitialiser");

    // Autoriser uniquement les nombres décimaux
    QDoubleValidator *validator = new QDoubleValidator(0, 1000000, 2, this);

    lineEditKm->setValidator(validator);
    lineEditLitres->setValidator(validator);

    // Création du layout
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(titre);
    layout->addSpacing(15);

    layout->addWidget(labelKm);
    layout->addWidget(lineEditKm);

    layout->addWidget(labelLitres);
    layout->addWidget(lineEditLitres);

    layout->addSpacing(10);

    layout->addWidget(btnCalculer);

    layout->addSpacing(10);

    layout->addWidget(labelResultat);

    layout->addWidget(btnReset);

    // Widget central
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);

    // Taille de la fenêtre
    resize(450, 300);

    // Titre de la fenêtre
    setWindowTitle("Calcul de consommation");

    // Connexion des boutons
    connect(btnCalculer, &QPushButton::clicked,
            this, &MainWindow::calculer);

    connect(btnReset, &QPushButton::clicked,
            this, &MainWindow::reinitialiser);
}

MainWindow::~MainWindow()
{
}

void MainWindow::calculer()
{
    // Récupérer les valeurs saisies
    double km = lineEditKm->text().toDouble();
    double litres = lineEditLitres->text().toDouble();

    // Vérifier les entrées
    if (km <= 0)
    {
        QMessageBox::warning(
            this,
            "Erreur",
            "Veuillez entrer un kilométrage supérieur à 0."
            );

        return;
    }

    if (litres <= 0)
    {
        QMessageBox::warning(
            this,
            "Erreur",
            "Veuillez entrer une quantité d'essence supérieure à 0."
            );

        return;
    }

    // Création du véhicule
    Vehicule voiture;

    voiture.setKilometrage(km);
    voiture.setLitres(litres);

    // Calcul
    double consommation = voiture.calculerConsommation();

    // Affichage
    labelResultat->setText(
        QString("Consommation : %1 L/100 km")
            .arg(consommation, 0, 'f', 2)
        );
}

void MainWindow::reinitialiser()
{
    lineEditKm->clear();
    lineEditLitres->clear();

    labelResultat->setText("Consommation : -- L/100 km");
}