//
//  FeatureBox.cpp
//  Data Marker Tests
//
//  Created by Andy Chen on 11/27/19.
//

#include "FeatureBox.hpp"

void FeatureBox::setup() {
    tweetImg.setup();
    boxParameters.setName("Feature Controls");
    boxParameters.add(Tweet.set("Tweet", true));
    boxParameters.add(tweetImg.ImageVisible);
    ofTrueTypeFont::setGlobalDpi(72);
    myfont.load("verdana.ttf", 14, true, true);
    myfont.setLineHeight(18.0f);
    myfont.setLetterSpacing(1.037);
    
}



void FeatureBox::draw() {
    tweetImg.draw();
    if(Tweet) {
        myfont.drawString("testing testing", 200, 200);
    }
}


