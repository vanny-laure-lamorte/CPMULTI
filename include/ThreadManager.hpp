#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>

class ThreadManager {
public:
    enum Mode { SINGLE_THREAD, MULTI_THREAD, MULTI_THREAD_MUTEX };

    static void processImage(Mode mode, int numThreads, 
                             cv::Mat& image, 
                             std::function<void(cv::Mat&, int, int)> processingFunction);
};

#endif // THREADMANAGER_H
