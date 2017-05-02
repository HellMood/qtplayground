#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include </usr/local/include/opencv2/core/core.hpp>
#include </usr/local/include/opencv2/imgproc/imgproc.hpp>
#include </usr/local/include/opencv2/highgui/highgui.hpp>

using namespace cv;
class Player : public QThread
{    Q_OBJECT
 private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    VideoCapture *capture = 0;

    Mat RGBframe;
    QImage img;
 signals:
 //Signal to output frame to be displayed
      void processedImage(const QImage &image);
 protected:
     void run();
     void msleep(int ms);
 public:
    //Constructor
    Player(QObject *parent = 0);
    //Destructor
    ~Player();
    //Kill capture
    void KillCapture(void);
    //Display default camera content
    bool StartCamera(void);
    //Load a video from memory
    bool loadVideo(std::string filename);
    //Play the video
    void Play();
    //Stop the video
    void Stop();
    //check if the player has been stopped
    bool isStopped() const;
     //set video properties
     void setCurrentFrame( int frameNumber);

     //Get video properties
     double getFrameRate();
     double getCurrentFrame();
     double getNumberOfFrames();
     bool isCamera = false;

};
#endif // VIDEOPLAYER_H
