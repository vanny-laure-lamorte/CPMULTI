#include <opencv2/photo.hpp>
#include <iostream>

#include "denoisingMenu.ui.hpp"

void DenoisingMenu::denoisingMenu(cv::Mat& img)
{
    if (img.empty()) {
        std::cerr << "Erreur: Aucune image chargée !" << std::endl;
        return;
    }

    int h;
    std::cout << "Entrez le paramètre de débruitage (10-50 recommandé) : ";
    std::cin >> h;

    if (h < 1 || h > 100) {
        std::cerr << "Valeur invalide, utilisation de la valeur par défaut (10)." << std::endl;
        h = 10;
    }

    cv::Mat denoisedImage;
    cv::fastNlMeansDenoisingColored(img, denoisedImage, h, h, 7, 21);

    img = denoisedImage;

    cv::imshow("Denoised Image", img);
    cv::waitKey(0);
}