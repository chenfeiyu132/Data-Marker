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

class TextBox{
public:
    void setup(const std::string &text, const int &x, const int &y);
    void draw();
    void setText(const std::string &text);
    string getText();

    void setCoordinates(const int &x, const int &y);
    void setX(const int &x);
    void setY(const int &y);
    int getX();
    int getY();
    ofParameter<bool> Tweet;

private:
    int x;
    int y;
    std::string text;
    ofTrueTypeFont myfont;
};

#endif /* TextBox_hpp */
