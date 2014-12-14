#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this , SLOT(abrir_imagen()));
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(close()));
    connect(this, SIGNAL(frameOriginal()), this, SLOT(cargar_frameOriginal()));
    connect(this, SIGNAL(imagenFinal()), this, SLOT(cargar_imagenFinal()));
    connect(this, SIGNAL(segmentation()), this, SLOT(cargar_segmentation()));
    connect(this, SIGNAL(text2()), this, SLOT(cargar_text2()));
    connect(this, SIGNAL(texto()), this, SLOT(cargar_text3()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this , SLOT(processing()));

}



//#############################################################
// Slots:

void MainWindow::abrir_imagen()
{
    ruta = QFileDialog::getOpenFileName(this, tr("Abrir Video"), "./",
                   tr("Video (*.flv *.avi *.mpeg *.mp4);; All files (*.*)"));
    if(ruta == "")return;
    ui->label->setText(ruta);
}

void MainWindow::cargar_frameOriginal()
{
    lugarImg1.setPixmap(QPixmap::fromImage(cvxCopyIplImage(frame_original,buffer)));
    ui->scrollArea->setWidget(&lugarImg1);


}

void MainWindow::cargar_imagenFinal()
{
    lugarImg3.setPixmap(QPixmap::fromImage(cvxCopyIplImage(img,buffer)));
    ui->scrollArea_3->setWidget(&lugarImg3);

}

void MainWindow::cargar_segmentation()
{
    lugarImg2.setPixmap(QPixmap::fromImage(cvxCopyIplImage(img2,buffer)));
    ui->scrollArea_2->setWidget(&lugarImg2);

}

void MainWindow::cargar_text2()
{
    ui->label_4->setText(text);

}

void MainWindow::cargar_text3()
{
    ui->label_6->setText(text3);

}


MainWindow::~MainWindow()
{
    delete ui;
}
