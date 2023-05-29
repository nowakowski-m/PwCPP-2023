#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

int changeIcon = 0;
bool startChange = false;
bool checkOnce = false;

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!startChange) {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
        startChange = true;
    }
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()));
    connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(zmienIkonke()));
}

//connect(ui->przycisk, SIGNAL(clicked()), ui->widget, SLOT(toggle_animation()));

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koniec_programu()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Uwaga!");
    msgBox.setText("Czy zamknąć program?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    if (msgBox.exec() == QMessageBox::Yes)
        qApp->quit();
}


void MainWindow::on_action_O_programie_triggered()
{
 QMessageBox::aboutQt(this,"O wspaniałym programie");
}

void MainWindow::zmienIkonke() {

    checkOnce = false;

    if (changeIcon == 1 && !checkOnce) {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
        changeIcon = 0;
        checkOnce = true;
    }

    else if (changeIcon == 0 && !checkOnce) {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-start.png"));
        changeIcon = 1;
        checkOnce = true;
    }
}
