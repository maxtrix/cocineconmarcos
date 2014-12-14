#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv/cxmisc.h>
#include <opencv/ml.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QGuiApplication>
#include <QLabel>
#include "procesos.h"
#include <ctime>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "cv.h"
#include "cvaux.h"
#include "cxcore.h"
#include "highgui.h"
#include "cxmisc.h"
#include "ml.h"
#include <math.h>
#include "cv_yuv_codebook.h"
#include <qwaitcondition.h>
#include <QThread>  
using namespace cv;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QImage&   cvxCopyIplImage(const IplImage *pIplImage, QImage &qImage);

private:
    Ui::MainWindow *ui;
    QImage imagen,ImagenFinal,imgAux1,imgAux2;
    IplImage *frame_original=NULL;
IplImage *img = NULL, *img2 = NULL;
QImage buffer;
    QLabel lugarImg1;
    QLabel lugarImg2;
    QLabel lugarImg3;
    QLabel lugarImg4;
    QLabel lugarImg5;
    QLabel lugarImg6;
    QString ruta, text, text3;
    int total = 0;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
signals:
    void frameOriginal();
    void imagenFinal();
    void segmentation();
    void text2();
    void texto();

public slots:
    void processing();
    void abrir_imagen();
    void cargar_frameOriginal();
    void cargar_imagenFinal();
    void cargar_segmentation();
    void cargar_text2();
    void cargar_text3();
    void delay(float seconds);





};

#endif // MAINWINDOW_H
