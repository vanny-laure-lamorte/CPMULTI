#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
#include <map>

/**
 * @class ImageManager
 * @brief Manages image loading and saving
 */
class ImageManager
{

public:
    /**
     * @brief Loads an image from the specified path
     * @param path Path to the image file
     */
    cv::Mat loadImage(int imageIndex);

    /**
     * @brief Saves an image to the specified path
     * @param path Path to save the image
     * @param img Image to save
     */
    void saveImage(const std::string &path, const cv::Mat &img);

    std::map<int, std::string> imagePaths;

    void initializeImagePaths()
    {
        imagePaths[1] = "../assets/dragon.jpg";
        imagePaths[2] = "../assets/horse.jpg";
        imagePaths[3] = "../assets/monkey.jpg";
        imagePaths[4] = "../assets/pig.jpg";
        imagePaths[5] = "../assets/rabbit.jpg";
        imagePaths[6] = "../assets/rooster.jpg";
        imagePaths[7] = "../assets/sheep.jpg";
        imagePaths[8] = "../assets/snake.jpg";
        imagePaths[9] = "../assets/tiger.jpg";
    }
};
#endif // IMAGEMANAGER_H
