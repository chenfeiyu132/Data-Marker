//
//  FeatureBox.hpp
//  Data Marker Tests
//
//  Created by Andy Chen on 11/27/19.
//

#ifndef FeatureBox_hpp
#define FeatureBox_hpp

#include "ofMain.h"
#include "ImageBox.hpp"

class FeatureBox{
public:
    void setup();
    void draw();
    
    ImageBox tweetImg;
    ofParameterGroup boxParameters;
    ofParameter<bool> Tweet;
    ofTrueTypeFont myfont;
};

#endif /* FeatureBox_hpp */
