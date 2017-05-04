#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myPlayer = new Player();
    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
                              this, SLOT(updatePlayerUI(QImage)));
    ui->setupUi(this);
//    this->setStyleSheet("background-color: #202020;color: #808080;");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete myPlayer;
}


void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    myPlayer->Stop();

    QString filename = QFileDialog::getOpenFileName(this,
                                          tr("Open Video"), tr("/media/hel/Data2/Vaxel Videos/"),
                                          tr("Video Files (*.wmv *.avi *.mpg *.mp4)"));
    if (!filename.isEmpty()){
        if (!myPlayer->loadVideo(filename.toLatin1().data()))
        {
            QMessageBox msgBox;
            msgBox.setText("The selected video could not be opened!");
            msgBox.exec();

            ui->frameNumberScroll->setMaximum(myPlayer->getNumberOfFrames());
        }
    }
}
void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),
                                           Qt::KeepAspectRatio, Qt::FastTransformation));

        // camera streams give a warning while accessing certain properties
        if(!myPlayer->isCamera){
            ui->frameNumberScroll->setValue(myPlayer->getCurrentFrame());
            ui->frameNumberScroll->setMaximum(myPlayer->getNumberOfFrames());
            ui->lcdNumber->display(myPlayer->getCurrentFrame());
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (myPlayer->isStopped())
    {
        myPlayer->Play();
        ui->pushButton_3->setText(tr("Stop"));
    }else
    {
        myPlayer->Stop();
        ui->pushButton_3->setText(tr("Play"));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                          tr("Open Picture"), ".",
                                          tr("Picture Files (*.jpg *.png *.bmp)"));
    if (!filename.isEmpty()){

        QImage myImage (filename.toLatin1().data());
        ui->label_2->setAlignment(Qt::AlignCenter);
        ui->label_2->setPixmap(QPixmap::fromImage(myImage).scaled(ui->label_2->size(),
                                           Qt::KeepAspectRatio, Qt::FastTransformation));

        cv::Mat myImage2 = cv::imread(filename.toLatin1().data());
//        cv::namedWindow("original");
//        cv::imshow("orignal",myImage2);

        myImage2.copyTo(theImage);

        cv::Mat gray,result,result2;
        cv::cvtColor(myImage2,gray,CV_BGR2GRAY);

        int min = ui->horizontalScrollBar->value();
        int max = ui->horizontalScrollBar_2->value();

        cv::Canny(gray,result,min,max,3);
        cv::cvtColor(result,result2,CV_GRAY2RGB);

//        cv::namedWindow("result");
//        cv::imshow("result",result2);

        QImage imgIn= QImage((uchar*) result2.data, result2.cols, result2.rows, result2.step, QImage::Format_RGB888);

        ui->label_3->setPixmap(QPixmap::fromImage(imgIn).scaled(ui->label_3->size(),
                                           Qt::KeepAspectRatio, Qt::FastTransformation));

        Ptr<SuperResolution> srp = cv::superres::createSuperResolution_BTVL1();
        Ptr<FrameSource> fsp = cv::superres::createFrameSource_Empty();

        srp->setInput(fsp);
    }
}

void MainWindow::on_horizontalScrollBar_sliderReleased()
{
    cv::Mat gray,result,result2;
    cv::cvtColor(theImage,gray,CV_BGR2GRAY);

    int min = ui->horizontalScrollBar->value();
    int max = ui->horizontalScrollBar_2->value();

    cv::Canny(gray,result,min,max,3);
    cv::cvtColor(result,result2,CV_GRAY2RGB);

    QImage imgIn= QImage((uchar*) result2.data, result2.cols, result2.rows, result2.step, QImage::Format_RGB888);
    ui->label_3->setPixmap(QPixmap::fromImage(imgIn).scaled(ui->label_3->size(),
                                       Qt::KeepAspectRatio, Qt::FastTransformation));

}

void MainWindow::on_horizontalScrollBar_2_sliderReleased()
{
    on_horizontalScrollBar_sliderReleased();
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    on_horizontalScrollBar_sliderReleased();
}

void MainWindow::on_horizontalScrollBar_2_valueChanged(int value)
{
    on_horizontalScrollBar_sliderReleased();
}

void MainWindow::on_pushButton_5_clicked()
{
    myPlayer->Stop();
    myPlayer->StartCamera();
    myPlayer->Play();
}

void MainWindow::on_frameNumberScroll_sliderReleased()
{
    if(myPlayer){
        myPlayer->Stop();
        myPlayer->setCurrentFrame(this->ui->frameNumberScroll->value());
        //myPlayer->Play();
    }

    this->ui->lcdNumber->display(this->ui->frameNumberScroll->value());
}

void MainWindow::on_frameNumberScroll_sliderMoved(int position)
{
    this->ui->frameNumberScroll->setValue(position);
    on_frameNumberScroll_sliderReleased();
}

void MainWindow::on_pushButton_6_clicked()
{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setHostName("jalapeno");
//    db.setDatabaseName("daisi");
//    db.setUserName("hel");
//    db.setPassword("hel");
//    //db.setConnectOptions(); // SSL?
//    db.setPort(5432);
//    bool ok = db.open();
//    if(ok != true)
//    {
//        QMessageBox::information(this,"Connection","Connection Failed!") ;
//    }
//    QSqlQuery myQuery;
//    ok = myQuery.prepare("select version();");
//    if(ok != true)
//    {
//        QMessageBox::information(this,"Query","Preparation Failed!") ;
//        return;
//    }

//    myQuery.exec();
//    myQuery.first(); // seems necessary
//    if (myQuery.isActive())
//    {
//        int myIndex = 0; // first field of result
//        if (!myQuery.isNull(myIndex))
//        {
//            QString myString = myQuery.value(myIndex).toString();
//            QMessageBox::information(this,"Query / Result",myString);
//        }
//    }
//    myQuery.finish();
//    //db.commit();        // before or after query clear?
//    myQuery.clear();

//    db.close();




}



void MainWindow::on_pushButton_7_clicked()
{
    winAbout = new TestDialog(this);
    winAbout->show();

}

void MainWindow::on_myTestButton_clicked()
{
//    printf("OpenCV: %s", cv::getBuildInformation().c_str());

    cv::Mat test = Mat::zeros(500,500,CV_8UC3);

    cv::namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow( "Display window", test );                   // Show our image inside it.

    //waitKey(0);                                          // Wait for a keystroke in the window
    return;

}








