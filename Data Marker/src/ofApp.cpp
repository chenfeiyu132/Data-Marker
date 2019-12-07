#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //path to JSON
    loadJson("/Users/Ju1y/Documents/Openframeworks/apps/myApps/fantastic-finale-chenfeiyu132/example_2.json");
    initializeDataGroup("statuses"); //datapoints initialized
    currMode = Mode::Binary; //default mode
    
   
    
    ofBackground(255);
    if(!tweet.value()["text"].empty()) {
        textbox.setup(tweet.value()["text"], 200, 200);
    } else {
        textbox.setup("No text available", 200, 200);
    }
    imgbox.setup("https://openframeworks.cc/about/0.jpg", 30, 50);
    
    parameterGroup.add(textbox.Tweet);
    parameterGroup.add(imgbox.ImageVisible);
    visibility.setup(parameterGroup);
    //Setting up labeling panel
    ofParameterGroup labelOptions;
    if(currMode == Mode::Binary) {
        addLabelOption("yes", labelOptions);
        addLabelOption("no", labelOptions);
    }
    labelingBox.setup(labelOptions, "labels", 300, 300);
    
    
    /*for(std::string name : labelNames) {
        
        buttonParam.set(name);
        labelOptions.add(buttonParam);
    }*/
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
}


/*void ofApp::tweetActivate(bool &state) {
    if(state) {
        ofDrawBitmapString("testing testing", 200, 200);
    } else {
        ofClear(0, 0, 0, 1.f);
    }
}*/

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(253, 255, 208, 200);
    ofDrawRectangle(0, 0, ofGetWidth()-150, ofGetHeight());
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(10);
    ofDrawRectangle(0, 0, ofGetWidth()-150, ofGetHeight());
    ofFill();
    ofSetColor(255);
    imgbox.draw();
    ofSetColor(0);
    textbox.draw();
    
    labelingBox.draw();
    visibility.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit() {
    
}

bool ofApp::loadJson(const std::string &path) {
    if(path.empty()) {
        ofLog() << "Invalid empty path";
        return false;
    }
    ofFile file(ofToDataPath(path));
    if(file.exists()) {
        ofLog() << "found file = "<<path<<", loading";
        json = ofLoadJson(path);
        ofLog() << "json is of size: " << json.size();
        return true;
    } else {
        ofLog() << "file not found for state name = "<<path;
        return false;
    }
}

void ofApp::saveJson(const std::string &path) {
    
}

bool ofApp::initializeDataGroup(const std::string &groupname) {
    if(json[groupname].is_null()) {
        ofLog() << "group does not exist";
        return false;
    }
    datasetSize = 0;
    tweet = json[groupname].begin();
    return true;
}

void ofApp::onClickLabel(const void * sender) {
    ofParameter<void> * button = (ofParameter<void> *)sender;
    if(button->getName() == "yes") {
        tweet.value()["label"] = true;
        ofLog() << "yes was pressed";
        
    } else if(button->getName() == "no") {
        tweet.value()["label"] = false;
        ofLog() << "no was pressed";
        
    } else {
        tweet.value()["label"] = button->getName();
        ofLog() << button->getName() + " was pressed";
    }
}

void ofApp::addLabelOption(const std::string &buttonName, ofParameterGroup &group) {
    ofParameter<void> button{buttonName};
    button.addListener(this, &ofApp::onClickLabel);
    group.add(button);
}
