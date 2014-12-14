#include "procesos.h"
// Slots para los procesos:
void MainWindow::processing()
{
    QByteArray byteArray = ruta.toUtf8();
    const char* cString = byteArray.constData();
    int threshold = 42.0;
    int dilate1 = 2;
    int erode1 = 4;
    int dilate2 = 2;
    int maxValue = 255.0;
    int thresholdType = CV_THRESH_BINARY;
    int key;


    IplImage *frame = NULL;
    IplImage *bg = NULL;
    IplImage *diff = NULL;
    IplImage *fg = NULL;
    IplImage *fg_aux = NULL;
    IplImage *fg_out = NULL;
    IplImage *final = NULL;

//First we get the video
CvCapture* capture;     //CvCapture is the structure used by openCv to handle with video

capture = cvCreateFileCapture(cString);
    //capture = cvCaptureFromCAM(0);

while(cvGrabFrame(capture)) {

    frame = cvRetrieveFrame(capture);

    if(frame) {
            if(bg == NULL) { //Initial background
                bg = cvCloneImage(frame);
                diff = cvCloneImage(frame);
                fg_out = cvCloneImage(frame);
                fg = cvCreateImage(cvSize(frame->width,frame->height),frame->depth,1);
                final = cvCreateImage( cvSize(frame->width,frame->height), IPL_DEPTH_8U, 1 );
            }

            //Segmentation
            img=cvCloneImage(frame);
            emit imagenFinal();
            fg_aux = cvCreateImage(cvSize(frame->width,frame->height),frame->depth, frame->nChannels);
            cvAbsDiff(frame, bg, diff);
            cvThreshold(diff, fg_aux, threshold, maxValue, thresholdType);
            cvCvtColor(fg_aux, final, CV_RGB2GRAY);
            img2=cvCloneImage(final);
            emit segmentation(); 
            cvErode(final, final, NULL,0.5);
            cvDilate(final, final, NULL, dilate1);
            cvErode(final, final, NULL,erode1);
            cvDilate(final, final, NULL, dilate2);
            bg=cvCloneImage(frame);
            int num=100;
            CvRect rectangles[100];
            temp2=temp1;
            cvconnectedComponents(final,1,15,&num,rectangles,NULL,0);
            
            temp1 = num;
            temp3 = temp1-(temp2);
            if(temp3>=2){total += temp3;}

            text = QString::number(num);
            text3 = QString::number(total);
            emit text2();
            emit texto();

            for (int i=0; i<num; i++)
            {
                cvRectangle(frame,
                    cvPoint(rectangles[i].x,rectangles[i].y),
                    cvPoint((rectangles[i].x+rectangles[i].width),(rectangles[i].y+rectangles[i].height)),
                    cvScalar(0,255,255),
                    1.5
                    );
            }



frame_original=cvCloneImage(frame);
emit frameOriginal();

}
delay(0.05);
key = cvWaitKey (0);
cvReleaseImage(&fg_aux);
}
cvReleaseImage(&fg);
    cvReleaseImage(&bg); //initial bg
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
    cvReleaseImage(&fg_out);
}


void MainWindow::delay( float seconds)
{
    clock_t temp;
    temp = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < temp) {}
}