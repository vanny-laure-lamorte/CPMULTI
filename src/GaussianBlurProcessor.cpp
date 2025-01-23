#include "../include/GaussianBlurProcessor.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <map>

using namespace cv;
using namespace std;

GaussianBlurProcessor::GaussianBlurProcessor()
    : kernelSize(15, 15)
{
    image = imread("../assets/image.jpg", IMREAD_COLOR);
}
GaussianBlurProcessor::~GaussianBlurProcessor()
{
    destroyAllWindows();
}

Mat GaussianBlurProcessor::applyGaussianBlur(int numThreads, int numAttempts)
{
    Mat blurredImage;
    double totalTime = 0;

    // Loop for multiple attempts
    for (int attempt = 1; attempt <= numAttempts; ++attempt)
    {
        int64 start = getTickCount();

        // Perform the Gaussian blur with the specified number of threads
        if (numThreads == 1)
        {
            GaussianBlur(image, blurredImage, kernelSize, 0);
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
                                     { GaussianBlur(image(region), partialResults[i], kernelSize, 0); });
            }

            for (auto &thread : threads)
                thread.join();
        }

        int64 end = getTickCount();
        double duration = (end - start) / getTickFrequency();
        totalTime += duration;
    }

    double averageTime = totalTime / numAttempts;
    cout << "\nAverage time with " << numThreads << " threads over " << numAttempts << " attempts: " << averageTime << " seconds\n";

    return blurredImage; // Return the final blurred image (only the last attempt will be returned)
}

void GaussianBlurProcessor::saveImage(const Mat &image, const string &filename)
{
    imwrite(filename, image);
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

void GaussianBlurProcessor::handleChoice(int choice){
    if (choice == 1){
        int threads;
        cout << "Enter number of threads to apply Gaussian Blur: ";
        cin >> threads;
        if (threads < 1)
        {
            cout << "Error: Number of threads should be greater than 0.\n";
            return;
        }

        Mat blurredImage = applyGaussianBlur(threads, 1);
        imshow("Gaussian Blur (" + to_string(threads) + " Threads)", blurredImage);
        waitKey(0);
        destroyAllWindows();
    }else if (choice == 2)
    {
        int numAttempts, numThreads;
        cout << "Enter number of attempts: ";
        cin >> numAttempts;
        cout << "Enter number of threads (constant for all attempts): ";
        cin >> numThreads;
        if (numAttempts < 1 || numThreads < 1)
        {
            cout << "Error: Number of attempts and threads should be greater than 0.\n";
            return;
        }

        applyGaussianBlur(numThreads, numAttempts);
    }else if (choice == 3)
    {
        int numAttempts;
        int numThreads;
        vector<int> threadCounts;

        cout << "Enter number of attempts: ";
        cin >> numAttempts;

        cout << "Enter the number of thread counts (separate values by space, end input with a non-numeric character): ";

        // Read the thread counts
        while (cin >> numThreads)
        {
            threadCounts.push_back(numThreads);
        }

        // Clear the error flag caused by non-numeric input (to continue with other operations)
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Run the Gaussian blur with different thread counts
        for (int threads : threadCounts)
        {
            applyGaussianBlur(threads, numAttempts);
        }
    }else{
        cout << "Invalid option! Please choose a valid option from the menu.\n";
    }
}

void GaussianBlurProcessor::displayMenu()
{
    cout << "\n----- Gaussian Blur Options -----\n";
    cout << "1. Apply Gaussian Blur with a custom number of threads\n";
    cout << "2. Perform multiple attempts with a constant number of threads\n";
    cout << "3. Perform 1000 attempts with varying numbers of threads\n";
    cout << "0. Exit\n";
    cout << "----------------------------------\n";
    cout << "Please enter an option (0-3): ";
}
