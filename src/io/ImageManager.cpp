#include "ImageManager.io.hpp"
#include <iostream>

cv::Mat ImageManager::loadImage(const std::string& path) {
    cv::Mat image = cv::imread(path);
    if (image.empty()) {
        std::cerr << "Erreur: Impossible de charger l'image " << path << std::endl;
    }
    return image;
}

void ImageManager::saveImage(const std::string& path, const cv::Mat& img) {
    if (!cv::imwrite(path, img)) {
        std::cerr << "Erreur lors de l'enregistrement de l'image !" << std::endl;
    } else {
        std::cout << "Image sauvegardée sous : " << path << std::endl;
    }
}
