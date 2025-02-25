#include "CannyEdgeDetection.hpp"

void CannyEdgeDetection::CannyThreshold(int, void*)
{
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );
}

void CannyEdgeDetection::runCannyEdgeDetection(cv::Mat& image)
{
    src = image;    
    dst.create( src.size(), src.type() );
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    namedWindow( window_name, WINDOW_AUTOSIZE );
    cv::setMouseCallback(window_name, NULL);
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, [](int pos, void* userdata) {
        static_cast<CannyEdgeDetection*>(userdata)->CannyThreshold(pos, userdata);
    }, this);
    CannyThreshold(0, 0);
    waitKey(0);
};

void CannyEdgeDetection::applyCannyEdgeDetector(cv::Mat &img){

    src = img;    

    int lowThreshold = 50, highThreshold = 150;    
    cv::Mat edges;
    cv::Canny(src, edges, lowThreshold, highThreshold);
    
    src = edges;
    if (src.empty()) {
        std::cerr << "Error: Empty image, cannot display!" << std::endl;
        return;
    }
    cv::namedWindow("Canny Edge Detection", cv::WINDOW_NORMAL);
    cv::imshow("Canny Edge Detection", src);
    cv::waitKey(0);
}


void CannyEdgeDetection::applyCannyEdgeDetectionWithThreads(cv::Mat &img, int numThreads) {
    auto start = std::chrono::high_resolution_clock::now();
    int lowThreshold = 50, highThreshold = 150;

    if (img.channels() > 1) {
        cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);  
    }

    cv::Mat edges = img.clone(); 

    int height = img.rows;
    int chunkHeight = height / numThreads; 
    vector<std::thread> threads;

    auto processChunk = [&img, &edges, lowThreshold, highThreshold](int startRow, int endRow) {
        cv::Mat chunk = img(cv::Range(startRow, endRow), cv::Range::all());
        cv::Mat edgesChunk;
        cv::Canny(chunk, edgesChunk, lowThreshold, highThreshold); 
        edgesChunk.copyTo(edges(cv::Range(startRow, endRow), cv::Range::all()));
    };

    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * chunkHeight;
        int endRow = (i == numThreads - 1) ? height : (i + 1) * chunkHeight; 
        
        threads.push_back(std::thread(processChunk, startRow, endRow));
    }

    for (auto &t : threads) {
        t.join();
    }

    if (edges.empty()) {
        std::cerr << "Error: Empty image, cannot display!" << std::endl;
        return;
    }

    cv::namedWindow("Canny Edge Detection", cv::WINDOW_NORMAL);
    cv::imshow("Canny Edge Detection", edges);
    cv::waitKey(0);    
}


void CannyEdgeDetection::plotGraph(const std::vector<int> &xValues, const std::vector<double> &yValues, 
    const std::string &title, const std::string &xLabel, 
    const std::string &yLabel)
{
    matplotlibcpp::figure();
    matplotlibcpp::plot(xValues, yValues, "-o");
    matplotlibcpp::title(title);
    matplotlibcpp::xlabel(xLabel);
    matplotlibcpp::ylabel(yLabel);
    matplotlibcpp::grid(true);
    matplotlibcpp::show();
}

void CannyEdgeDetection::graphThreads(cv::Mat &img)
{   
    vector<double> averageTimes;
    vector<int> threadCounts = {1, 2, 4, 8, 16, 32};
        
    cout << "\n Average Time vs Threads ";
    for (int threads : threadCounts)
    {
        double averageTime = timeApplyCannyEdge(img, threads);
        averageTimes.push_back(averageTime);

        cout << "\n "<< threads << "thread : " << averageTime << "s";
    }

    plotGraph(threadCounts, averageTimes, "Average Time vs. Threads", "Threads", "Average Time (s)");
}

double CannyEdgeDetection::timeApplyCannyEdge(cv::Mat &img, int numThreads){

    auto start = std::chrono::high_resolution_clock::now();
    int lowThreshold = 50, highThreshold = 150;

    if (img.channels() > 1) {
        cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);  
    }

    cv::Mat edges = img.clone(); 

    int height = img.rows;
    int chunkHeight = height / numThreads; 
    vector<std::thread> threads;

    auto processChunk = [&img, &edges, lowThreshold, highThreshold](int startRow, int endRow) {
        cv::Mat chunk = img(cv::Range(startRow, endRow), cv::Range::all());
        cv::Mat edgesChunk;
        cv::Canny(chunk, edgesChunk, lowThreshold, highThreshold); 
        edgesChunk.copyTo(edges(cv::Range(startRow, endRow), cv::Range::all()));
    };

    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * chunkHeight;
        int endRow = (i == numThreads - 1) ? height : (i + 1) * chunkHeight; 
        
        threads.push_back(std::thread(processChunk, startRow, endRow));
    }

    for (auto &t : threads) {
        t.join();
    }

    return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();;
}