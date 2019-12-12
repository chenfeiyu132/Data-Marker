//
//  TextBox.hpp
//  Data Marker Tests
//
//  Created by Andy Chen on 11/27/19.
//

#ifndef TextBox_hpp
#define TextBox_hpp

#include "ofMain.h"
#include "ImageBox.hpp"
#include "ofxParagraph.h"

class TextBox{
public:
    void setup(const std::string &text, const int& width, const int &x, const int &y);
    void draw();
    void setText(const std::string &text);
    string getText();

    void setCoordinates(const int &x, const int &y);
    void setX(const int &x);
    void setY(const int &y);
    void setWidth(const int &width);
    int getX();
    int getY();
    int getWidth();
    ofParameter<bool> Tweet;
    ofxParagraph paragraph;
    

private:
    int x;
    int y;
    int width;
    std::string text;
    
};

#endif /* TextBox_hpp */
