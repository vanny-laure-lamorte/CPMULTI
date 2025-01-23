#include "../include/GaussianBlurProcessor.hpp"

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

void GaussianBlurProcessor::userChoice()
{
    int choice;

    while (true)
    {
        displayMenu();
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting...\n";
            break;
        }

        handleChoice(choice);
    }
}

void GaussianBlurProcessor::displayMenu()
{
    cout << "\n----- Gaussian Blur Options -----\n";
    cout << "1. Apply Gaussian Blur with a custom number of threads\n";
    cout << "2. Graph average time vs. number of threads (1, 2, 4, 8, 16, 32 threads)\n";
    cout << "3. Custom Gaussian Blur level\n";
    cout << "0. Exit\n";
    cout << "----------------------------------\n";
    cout << "Please enter an option (0-3): ";
}

void GaussianBlurProcessor::handleChoice(int choice)
{
    switch (choice)
    {
    case 1:
    {
        int threads;
        cout << "Enter number of threads: ";
        cin >> threads;
        auto [blurredImage, averageTime] = applyGaussianBlur(threads);
        imshow("Gaussian Blur", blurredImage);
        waitKey(0);
        destroyAllWindows();
        break;
    }
    case 2:
    {
        graphThreads();
        break;
    }
    case 3:
    {
        int kernelOption;
        cout << "\n----- Choose Kernel Size -----\n";
        cout << "1. Low blur\n";
        cout << "2. Medium blur\n";
        cout << "3. High blur\n";
        cout << "4. Very High blur\n";
        cout << "0. Exit\n";
        cin >> kernelOption;

        Size kernelSize;
        switch (kernelOption)
        {
        case 1:
            kernelSize = Size(5, 5);
            break;
        case 2:
            kernelSize = Size(15, 15);
            break;
        case 3:
            kernelSize = Size(31, 31);
            break;
        case 4:
            kernelSize = Size(61, 61);
            break;
        case 0:
            return;
        default:
            cout << "Invalid option\n";
            return;
        }

        Mat blurredImage;
        GaussianBlur(image, blurredImage, kernelSize, 0);
        imshow("Gaussian Blur", blurredImage);
        waitKey(0);
        destroyAllWindows();
        break;
    }
    case 0:
        cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid option\n";
        break;
    }
}