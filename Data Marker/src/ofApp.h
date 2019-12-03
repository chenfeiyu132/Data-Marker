#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofJson.h"

#include "TextBox.hpp"
#include "ImageBox.hpp"



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
        bool loadJson(const std::string &path);
        void saveJson(const std::string &path);
        bool initializeDataGroup(const std::string &groupname);
        
		ofxPanel visibility; //supposedly for feature selection
        ofxPanel labelingBox;
        std::vector<std::string> labelNames;
        ofJson json;
        int datasetSize;
        std::vector<ofJson> tweets;
        ofParameterGroup parameterGroup;
        TextBox textbox;
        ImageBox imgbox;
};
