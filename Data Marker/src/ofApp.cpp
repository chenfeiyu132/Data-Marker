#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //path to JSON

     //json.loadJson("/Users/Ju1y/Documents/Openframeworks/apps/myApps/fantastic-finale-chenfeiyu132/example_2.json");
    ofBackground(54, 54, 54, 255);
    ofTrueTypeFont::setGlobalDpi(72);
    ofRegisterURLNotification(this);
    gui.setup();
    //imageLoad.addListener(this, &ofApp::imageActivate);
    gui.add(imageLoad.ofxToggle::setup("show Image", true));
    gui.add(textLoad.ofxToggle::setup("show Tweet", true));
    
    myfont.load("verdana.ttf", 14, true, true);
    myfont.setLineHeight(18.0f);
    myfont.setLetterSpacing(1.037);
    img.load("https://openframeworks.cc/about/0.jpg");
}

void ofApp::urlResponse(ofHttpResponse & response){
    //case if success
    if(response.status == 200) {
        ofLog() << "Picture Download successful";
        img.load(response.data);
    } else {
        ofLog() << "Picture unavailable";
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}


void ofApp::tweetActivate(bool &state) {
    if(state) {
        ofDrawBitmapString("testing testing", 200, 200);
    } else {
        ofClear(0, 0, 0, 1.f);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(225);
    if(imageLoad) {
        img.draw(0, 0);
    }
    if(textLoad) {
        ofDrawBitmapString("testing testing", 200, 200);
    }
    gui.draw();
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
    ofUnregisterURLNotification(this);
}
