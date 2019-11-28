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
    void setup();
    void draw();
    bool urlResponse(ofHttpResponse &response);
    void exit();
    
    
    ofParameter<bool> ImageVisible;
    ofImage img;
};
#endif /* ImageBox_hpp */
