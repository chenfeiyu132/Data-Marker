#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //path to JSON

     //json.loadJson("/Users/Ju1y/Documents/Openframeworks/apps/myApps/fantastic-finale-chenfeiyu132/example_2.json");
    ofBackground(255);
    boxGroup.setup();
    parameterGroup.add(boxGroup.boxParameters);
    visibility.setup(parameterGroup);
    //Setting up labeling panel
    labelingBox.setup();
    labelNames.push_back("Yes");
    labelNames.push_back("No");
    ofxButton temp;
    for(std::string name : labelNames) {
        labelingBox.add(temp.setup(name));
    }
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
    boxGroup.draw();
    
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
