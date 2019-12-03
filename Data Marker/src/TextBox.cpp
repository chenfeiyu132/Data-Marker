//
//  TextBox.cpp
//  Data Marker Tests
//
//  Created by Andy Chen on 11/27/19.
//

#include "TextBox.hpp"

void TextBox::setup(const std::string &text, const int &x, const int &y) {
    
    Tweet.set("Tweet", true);
    ofTrueTypeFont::setGlobalDpi(72);
    myfont.load("verdana.ttf", 14, true, true);
    myfont.setLineHeight(18.0f);
    myfont.setLetterSpacing(1.037);
    this->x = x;
    this->y = y;
    this->text = text;
}



void TextBox::draw() {
    if(Tweet) {
        myfont.drawString(text, x, y);
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
int TextBox::getX() {
    return this->x;
}
int TextBox::getY() {
    return this->y;
}




