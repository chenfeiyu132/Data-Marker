//
//  ImageBox.cpp
//  Data Marker
//
//  Created by Andy Chen on 11/27/19.
//

#include "ImageBox.hpp"


void ImageBox::setup(const std::string &url, const int &x, const int &y) {
    if(!url.empty()) {
        this->url = url;
        response = ofLoadURL(url);
    } else {
        response = ofLoadURL("sdjaklsdjaskd");
    }
    urlResponse(response);
    this-> x = x;
    this-> y = y;
    ImageVisible.set("Image Visible", true);
}

void ImageBox::draw() {
    if(ImageVisible) {
        img.draw(x, y); //add relative coordinates after
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
        img.load("https://icon-library.net/images/picture-unavailable-icon/picture-unavailable-icon-5.jpg");
        return false;
    }
}

void ImageBox::setImgUrl(const std:: string &url) {
    this->url = url;
    img.load(this->url);
    ofRegisterURLNotification(this);
}

std::string ImageBox::getImgUrl() {
    return this->url;
}

void ImageBox::exit() {
    ofUnregisterURLNotification(this);
}
