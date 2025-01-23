#include "../include/CannyEdgeDetection.hpp"


void CannyEdgeDetection::CannyThreshold(int, void*)
{
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );
}

void CannyEdgeDetection::runCannyEdgeDetection()
{
    src = imread( "../assets/Test1.jpg", IMREAD_COLOR );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        return;
    }
    
    dst.create( src.size(), src.type() );
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    namedWindow( window_name, WINDOW_AUTOSIZE );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, [](int pos, void* userdata) {
        static_cast<CannyEdgeDetection*>(userdata)->CannyThreshold(pos, userdata);
    }, this);
    CannyThreshold(0, 0);
    waitKey(0);
}