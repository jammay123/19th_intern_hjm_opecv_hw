#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    angle1(0.0), angle2(0.0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect (timer, &QTimer::timeout, this, &MainWindow::updateFrame);
    timer->start(30);

    image = cv::Mat::zeros(600, 800, CV_8UC3);      //생성자
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateFrame() {
    // 각도 업데이트
    angle1 = angle1 + 0.05;
    angle2 = angle2 + 0.03;

    // 이미지 초기화
    image = cv::Mat::zeros(600, 800, CV_8UC3);

    // 로봇 팔 길이
    double length1 = 80.0;
    double length2 = 100.0;
    cv::Point origin(400, 300);

    cv::Point joint1(
        origin.x + length1 * cos(angle1),
        origin.y + length1 * sin(angle1)
        );

    cv::Point joint2(
        joint1.x + length2 * cos(angle1 + angle2),
        joint1.y + length2 * sin(angle1 + angle2)
        );

    // 로봇 팔 그리기
    cv::line(image, origin, joint1, cv::Scalar(0, 255, 0), 3);
    cv::line(image, joint1, joint2, cv::Scalar(0, 255, 0), 3);
    cv::circle(image, origin, 5, cv::Scalar(255, 0, 0), -1);
    cv::circle(image, joint1, 5, cv::Scalar(255, 0, 0), -1);
    cv::circle(image, joint2, 5, cv::Scalar(255, 0, 0), -1);

    cv::cvtColor (image, image, cv::COLOR_BGR2RGB);
    QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(qImage));
}
