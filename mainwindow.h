#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculer();
    void reinitialiser();

private:
    QLineEdit *lineEditKm;
    QLineEdit *lineEditLitres;

    QLabel *labelResultat;

    QPushButton *btnCalculer;
    QPushButton *btnReset;
};

#endif
