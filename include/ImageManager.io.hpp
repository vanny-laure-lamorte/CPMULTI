#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <opencv2/opencv.hpp>
#include <string>
/**
* @class ImageManager
* @brief Manages image loading and saving
*/
class ImageManager {
public:
/** 
* @brief Loads an image from the specified path
* @param path Path to the image file
*/
    static cv::Mat loadImage(const std::string& path);
    /**
     * @brief Saves an image to the specified path
     * @param path Path to save the image
     * @param img Image to save
     */
    static void saveImage(const std::string& path, const cv::Mat& img);
};

#endif // IMAGEMANAGER_H
