//
//  TextBox.cpp
//  Data Marker Tests
//
//  Created by Andy Chen on 11/27/19.
//

#include "TextBox.hpp"

void TextBox::setup(const std::string &text, const std::string &title, const int &width, const int &x, const int &y) {
    
    Tweet.set("Tweet", true);
    this->x = x;
    this->y = y;
    this->text = text;
    this->width = width;
    this->title = title;
    this->backgroundEnabled = true;
    paragraph = ofxParagraph(text, width);
    paragraph.setFont("verdana.ttf", 12);
    paragraph.setIndent(0);
    paragraph.setAlignment(ofxParagraph::ALIGN_CENTER);
}



void TextBox::draw() {
    if(Tweet) {
        ofSetColor(15);
        ofDrawBitmapString(title, x+paragraph.getWidth()/2-text.length(), y-paragraph.getHeight()/2-12);
        if(backgroundEnabled){
            ofSetColor(255);
            ofDrawRectRounded(x, y-paragraph.getHeight()/2, paragraph.getWidth(), paragraph.getHeight()*2, 10);
        }
        ofSetColor(0);
        paragraph.draw(x, y);
    }
}

void TextBox::setText(const std::string &text) {
    this->text = text;
}
std::string TextBox::getText() {
    return text;
}

void TextBox::setCoordinates(const int &x, const int &y) {
    this->x = x;
    this->y = y;
}
void TextBox::setX(const int &x) {
    this->x = x;
}
void TextBox::setY(const int &y) {
    this->y = y;
}
void TextBox::setWidth(const int &width) {
    this->width = width;
    paragraph = ofxParagraph(text, this->width);
}
void TextBox::setBackgroundEnabled(const bool &enabled) {
    this->backgroundEnabled = enabled;
}
int TextBox::getX() {
    return this->x;
}
int TextBox::getY() {
    return this->y;
}
int TextBox::getWidth(){
    return this->width;
}
bool TextBox::getBackgroundEnabled(){
    return this->backgroundEnabled;
}





