
#ifndef FRAMEDRAWER_H
#define FRAMEDRAWER_H

#include "Tracking.h"
#include "MapPoint.h"
#include "Map.h"
#include "YOLOv5Detector.h"

#include<opencv2/core/core.hpp>
#include<opencv2/features2d/features2d.hpp>

#include<mutex>


namespace ORB_SLAM2
{

class Tracking;
class Viewer;

class FrameDrawer
{
public:
    FrameDrawer(Map* pMap);

    // Update info from the last processed frame.
    void Update(Tracking *pTracker);

    // Draw last processed frame.
    cv::Mat DrawFrame();

    //**** 画出框选物体
    void DrawDetections(cv::Mat & frame, std::vector<detect_result> &results, std::vector<std::string> &classes);

protected:

    void DrawTextInfo(cv::Mat &im, int nState, cv::Mat &imText);

    // Info of the frame to be drawn
    cv::Mat mIm;
    int N;
    vector<cv::KeyPoint> mvCurrentKeys;
    vector<bool> mvbMap, mvbVO;
    bool mbOnlyTracking;
    int mnTracked, mnTrackedVO;
    vector<cv::KeyPoint> mvIniKeys;
    vector<int> mvIniMatches;
    int mState;
    
    //*****检测结果
    vector<ORB_SLAM2::detect_result> mResults;
    vector<std::string> mClasses;

    Map* mpMap;

    std::mutex mMutex;
};

} //namespace ORB_SLAM

#endif // FRAMEDRAWER_H
