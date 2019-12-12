//
//  ImageBox.hpp
//  Data Marker
//
//  Created by Andy Chen on 11/27/19.
//

#ifndef ImageBox_hpp
#define ImageBox_hpp

#include "ofMain.h"
#include "ofURLFileLoader.h"

class ImageBox {
public:
    void setup(const std::string &url, const int& width, const int& height, const int &x, const int &y);
    void draw();
    bool urlResponse(ofHttpResponse &response);
    void setImgUrl(const std:: string &url);
    std::string getImgUrl();
    void exit();
    
    
    ofParameter<bool> ImageVisible;
    ofImage img;
    ofHttpResponse response;
    std::string url;
    int x;
    int y;
};
#endif /* ImageBox_hpp */
