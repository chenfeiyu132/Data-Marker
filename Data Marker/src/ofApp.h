#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofJson.h"

#include "FeatureBox.hpp"

struct dataPoint{
    int Id;
    ofJson data;
    std::string label;
};

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
        void exit();
        
        //void imageActivate(bool &state);
        //void tweetActivate(bool &state);
    
        
		ofxPanel visibility; //supposedly for feature selection
        ofxPanel labelingBox;
        std::vector<std::string> labelNames;
        ofJson json;
        std::vector<dataPoint> tweets;
        ofParameterGroup parameterGroup;
        FeatureBox boxGroup;
};
