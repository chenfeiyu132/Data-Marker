#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofTrueTypeFont.h"
#include "JsonLoader.hpp"
#include "ofxUnitTests.h"
#include "ofURLFileLoader.h"

class ofApp : public ofBaseApp{

	public:
        
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void urlResponse(ofHttpResponse & response);
        void exit();
        //void imageActivate(bool &state);
        void tweetActivate(bool &state);
    
    
		ofxPanel gui;
        ofTrueTypeFont myfont;
        ofImage img;
        ofxToggle imageLoad;
        ofxToggle textLoad;
        andyWong::JsonLoader json;
};
