#include "ThreadManager.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void ThreadManager::processImage(Mode mode, int numThreads, 
                                 Mat& image, 
                                 function<void(Mat&, int, int)> processingFunction) {
    if (image.empty()) {
        cerr << "Error: No image loaded for processing!" << endl;
        return;
    }

    if (mode == SINGLE_THREAD) {
        processingFunction(image, 0, image.rows);
    
    } else if (mode == MULTI_THREAD) {
        vector<thread> threads;
        int blockHeight = image.rows / numThreads;
        
        for (int i = 0; i < numThreads; ++i) {
            int yStart = i * blockHeight;
            int yEnd = (i == numThreads - 1) ? image.rows : (i + 1) * blockHeight;

            threads.emplace_back([&, yStart, yEnd]() {
                processingFunction(image, yStart, yEnd);
            });
        }

        for (auto& t : threads) {
            t.join();
        }

    }else if (mode == MULTI_THREAD_MUTEX) {
        vector<thread> threads;
        mutex imgMutex;
        vector<Range> rowRanges;
    
        int baseBlockSize = image.rows / numThreads;
        int extraRows = image.rows % numThreads;
    
        int startRow = 0;
        for (int i = 0; i < numThreads; ++i) {
            int endRow = startRow + baseBlockSize + (i < extraRows ? 1 : 0);
            rowRanges.emplace_back(startRow, endRow);
            startRow = endRow;
        }
    
        for (int i = 0; i < numThreads; ++i) {
            threads.emplace_back([&, i]() {
                // Process only the assigned region
                Mat tempRegion(image, rowRanges[i]);
                processingFunction(tempRegion, 0, tempRegion.rows);
    
                unique_lock<mutex> lock(imgMutex);
                tempRegion.copyTo(image.rowRange(rowRanges[i].start, rowRanges[i].end));
            });
        }
        for (auto& t : threads) {
            t.join();
        }
    }
}
