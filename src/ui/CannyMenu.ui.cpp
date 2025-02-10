#include "CannyMenu.ui.hpp"

#include <iostream>

void CannyMenu::cannyMenu(cv::Mat& img) {

    
    int lowThreshold, highThreshold;
    std::cout << "Entrez le seuil bas pour Canny: ";
    std::cin >> lowThreshold;
    std::cout << "Entrez le seuil haut pour Canny: ";
    std::cin >> highThreshold;

    cv::Mat edges;
    cv::Canny(img, edges, lowThreshold, highThreshold);
    // displayImage("Canny Edge Detection", edges);

    img = edges;
    if (img.empty()) {
        std::cerr << "Erreur: Image vide, impossible d'afficher !" << std::endl;
        return;
    }
    cv::namedWindow("Canny Edge Detection", cv::WINDOW_NORMAL);
    cv::imshow("Canny Edge Detection", img);
    cv::waitKey(0);
}
