#include "procesos.h"

QImage& MainWindow::cvxCopyIplImage(const IplImage *pIplImage, QImage &qImage)
{
    if(!CV_IS_IMAGE(pIplImage)) return qImage;



    int w = pIplImage->width;
    int h = pIplImage->height;



    if(qImage.width() != w || qImage.height() != h)
    {
        qImage = QImage(w, h, QImage::Format_RGB32);
    }



    int x, y;
    for(x = 0; x < pIplImage->width; ++x)
    {
        for(y = 0; y < pIplImage->height; ++y)
        {
            CvScalar color = cvGet2D(pIplImage, y, x);


            if(pIplImage->nChannels == 1)
            {
                int v = color.val[0];

                qImage.setPixel(x, y, qRgb(v,v,v));
            }
            else
            {
                int r = color.val[2];
                int g = color.val[1];
                int b = color.val[0];

                qImage.setPixel(x, y, qRgb(r,g,b));
            }
        }
    }


    if(pIplImage->origin != IPL_ORIGIN_TL)
    {
        qImage = qImage.mirrored(false, true);
    }

    return qImage;
}
