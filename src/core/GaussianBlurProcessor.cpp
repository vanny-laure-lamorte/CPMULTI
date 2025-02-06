#include "GaussianBlurProcessor.hpp"

GaussianBlurProcessor::GaussianBlurProcessor()
{
    image = imread("../assets/image.jpg", IMREAD_COLOR);
}
GaussianBlurProcessor::~GaussianBlurProcessor()
{
    destroyAllWindows();
}

void GaussianBlurProcessor::plotGraph(const std::vector<int> &xValues, const std::vector<double> &yValues, const std::string &title, const std::string &xLabel, const std::string &yLabel)
{
    matplotlibcpp::figure();
    matplotlibcpp::plot(xValues, yValues, "-o");
    matplotlibcpp::title(title);
    matplotlibcpp::xlabel(xLabel);
    matplotlibcpp::ylabel(yLabel);
    matplotlibcpp::grid(true);
    matplotlibcpp::show();
}

pair<Mat, double> GaussianBlurProcessor::applyGaussianBlur(int numThreads)
{
    Mat blurredImage = image.clone();

    // Warmup run
    GaussianBlur(image, blurredImage, Size(15, 15), 0);

    int64 start = getTickCount();
    for (int attempt = 1; attempt <= 100; ++attempt)
    {
        if (numThreads == 1)
        {
            GaussianBlur(image, blurredImage, Size(15, 15), 0);
        }
        else
        {
            vector<thread> threads;
            vector<Mat> partialResults(numThreads);
            blurredImage = image.clone();

            int blockHeight = image.rows / numThreads;
            for (int i = 0; i < numThreads; ++i)
            {
                int yStart = i * blockHeight;
                int yEnd = (i == numThreads - 1) ? image.rows : (i + 1) * blockHeight;
                Rect region(0, yStart, image.cols, yEnd - yStart);
                partialResults[i] = Mat(blurredImage, region);

                threads.emplace_back([&, region, i]()
                                     { GaussianBlur(image(region), partialResults[i], Size(15, 15), 0); });
            }

            for (auto &thread : threads)
                thread.join();
        }
    }

    int64 end = getTickCount();
    double averageTime = (end - start) / (getTickFrequency() * 100.0);
    cout << "Average Time for " << numThreads << " threads: " << averageTime << " seconds\n";

    return {blurredImage, averageTime};
}

void GaussianBlurProcessor::graphThreads()
{
    vector<double> averageTimes;
    vector<int> threadCounts = {1, 2, 4, 8, 16, 32};

    cout << "\nRecap of average times per thread count:\n";

    for (int threads : threadCounts)
    {
        auto [blurredImage, averageTime] = applyGaussianBlur(threads);
        averageTimes.push_back(averageTime);
    }

    plotGraph(threadCounts, averageTimes, "Average Time vs. Threads", "Threads", "Average Time (s)");
}


void GaussianBlurProcessor::GaussianBlurWithCustomThreads(int threads)
{
    auto [blurredImage, averageTime] = applyGaussianBlur(threads);
    imshow("Gaussian Blur", blurredImage);
    waitKey(0);
    destroyAllWindows();
}

void GaussianBlurProcessor::customGaussianBlurIntensity(Size intensity){
    Mat blurredImage;
    GaussianBlur(image, blurredImage, intensity, 0);
    imshow("Gaussian Blur", blurredImage);
    waitKey(0);
    destroyAllWindows();
}
