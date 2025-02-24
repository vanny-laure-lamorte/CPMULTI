#include "ImageManager.io.hpp"
#include <iostream>

cv::Mat ImageManager::loadImage(int imageIndex) {
    if (imagePaths.empty()) {
        initializeImagePaths();
    }
    
    auto it = imagePaths.find(imageIndex);
    if (it != imagePaths.end()) {
        // Charger l'image à partir du chemin associé à l'index
        cv::Mat image = cv::imread(it->second);
        if (image.empty()) {
            std::cerr << "Erreur: Impossible de charger l'image " << it->second << std::endl;
        }
        return image;
    } else {
        std::cerr << "Erreur: Index d'image invalide." << std::endl;
        return cv::Mat(); // Retourne une image vide si l'index est invalide
    }
}

void ImageManager::saveImage(const std::string& path, const cv::Mat& img) {
    if (!cv::imwrite(path, img)) {
        std::cerr << "Erreur lors de l'enregistrement de l'image !" << std::endl;
    } else {
        std::cout << "Image sauvegardée sous : " << path << std::endl;
    }
}
