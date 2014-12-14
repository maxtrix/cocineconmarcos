#-------------------------------------------------
#
# Project created by QtCreator 2013-06-14T16:13:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    #MatToQImage.cpp \
    procesos.cpp \
cv_yuv_codebook.cpp \
    iplimageToQimage.cpp


HEADERS  += mainwindow.h \
    procesos.h \
cv_yuv_codebook.h

FORMS    += mainwindow.ui
################################################################
## Incluimos OpenCV
################################################################

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib \
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui \
        -lopencv_ml \
        -lopencv_video \
        -lopencv_features2d \
        -lopencv_calib3d \
        -lopencv_objdetect \
        -lopencv_contrib \
        -lopencv_legacy \
        -lopencv_flann
