/*
compute LK
*/

#ifndef LK_h
#define LK_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <chrono>
#include <Frame.h>

using namespace std;

vector< cv::Point2f > keypoints;
vector<cv::Point3f> mappointInCurrentFrame;
vector<cv::Point2f> prev_keypoints;
cv::Mat last_color;

namespace ORB_SLAM
{
Mat computeMtcwUseLK(cv::Mat &ImgLeft, cv::Mat &Imgright,)
{
    
}
    
}

#endif