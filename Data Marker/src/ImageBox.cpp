//
//  ImageBox.cpp
//  Data Marker
//
//  Created by Andy Chen on 11/27/19.
//

#include "ImageBox.hpp"


void ImageBox::setup() {
    ofRegisterURLNotification(this);
    img.load("https://openframeworks.cc/about/0.jpg");
    ImageVisible.set("Image Visible", true);
}

void ImageBox::draw() {
    if(ImageVisible) {
        img.draw(0, 0); //add relative coordinates after
    }
}

bool ImageBox::urlResponse(ofHttpResponse & response){
    //case if success
    if(response.status == 200) {
        ofLog() << "Picture Download successful";
        img.load(response.data);
        return true;
    } else {
        ofLog() << "Picture unavailable";
        return false;
    }
}

void ImageBox::exit() {
    ofUnregisterURLNotification(this);
}
