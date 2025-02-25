#include "ThreadManager.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void ThreadManager::processImage(Mode mode, int numThreads,
                                 Mat &image,
                                 function<void(Mat &, int, int)> processingFunction)
{
    if (image.empty())
    {
        cerr << "Error: No image loaded for processing!" << endl;
        return;
    }

    if (mode == SINGLE_THREAD)
    {
        processingFunction(image, 0, image.rows);
    }
    else if (mode == MULTI_THREAD)
    {
        vector<thread> threads;
        int blockHeight = image.rows / numThreads;
        vector<Mat> tempResults(numThreads);

        for (int i = 0; i < numThreads; ++i)
        {
            int yStart = i * blockHeight;
            int yEnd = (i == numThreads - 1) ? image.rows : (i + 1) * blockHeight;

            threads.emplace_back([&, i, yStart, yEnd]()
                                 {
Mat tempRegion = image.rowRange(yStart, yEnd).clone();
processingFunction(tempRegion, 0, tempRegion.rows);

tempResults[i] = tempRegion.clone(); });
        }

        for (auto &t : threads)
        {
            t.join();
        }

        for (int i = 0; i < numThreads; ++i)
        {
            tempResults[i].copyTo(image.rowRange(i * blockHeight, (i == numThreads - 1) ? image.rows : (i + 1) * blockHeight));
        }
    }
}
