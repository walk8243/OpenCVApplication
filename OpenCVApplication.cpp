#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/dnn.hpp>
#include <fstream>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
    Mat refImage;
    refImage = imread("F:\\git\\puzdra-auto-laps\\dungeon-title-cropping.png", IMREAD_UNCHANGED);
    if (refImage.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    Mat refMatGray;
    cvtColor(refImage, refMatGray, COLOR_RGB2GRAY);
    Mat refMatThreshold;
    threshold(refMatGray, refMatThreshold, 0, 255, THRESH_BINARY | THRESH_OTSU);

    Mat targetImage;
    targetImage = imread("F:\\git\\puzdra-auto-laps\\dungeon-title-cropping-2.png", IMREAD_UNCHANGED);
    if (targetImage.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    Mat targetMatGray;
    cvtColor(targetImage, targetMatGray, COLOR_RGB2GRAY);
    Mat targetMatThreshold;
    threshold(targetMatGray, targetMatThreshold, 0, 255, THRESH_BINARY | THRESH_OTSU);

    Mat matDiff;
    absdiff(targetMatThreshold, refMatThreshold, matDiff);
    Mat matErode;
    erode(matDiff, matErode, Mat(), Point(-1, -1), 1);
    Mat matDilate;
    dilate(matErode, matDilate, Mat(), Point(-1, -1), 1);

    vector<vector<Point>> vctContours;
    findContours(matDilate, vctContours, RETR_LIST, CHAIN_APPROX_NONE);

    int i = 0;
    for (auto contour = vctContours.begin(); contour != vctContours.end(); contour++) {
        cv::drawContours(targetImage, vctContours, i, CV_RGB(0, 0, 255), 2);
        i++;
    }

    imwrite("compare-result.jpg", targetImage);
    imshow("diff", targetImage);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
