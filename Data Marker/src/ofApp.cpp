#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panel = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT);
    panel->setWidth(ofGetWidth()-804);
    //Add import and export buttons
    
    panel->addFolder("File", ofColor::white);
    
    panel->getFolder("File")->addButton("Import")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        ofSystemAlertDialog("Please Select JSON File to be imported");
        importFile();
    });
    panel->getFolder("File")->addButton("Export")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        saveJson(currJsonPath, json);
    });
    panel->getFolder("File")->expand();

    //Add feature visibility options
    panel->addFolder("Visibility", ofColor::blue);
    
    panel->getFolder("Visibility")->addToggle("Tweet", true)->onToggleEvent([&](ofxDatGuiToggleEvent e) {
        e.checked == true ? textbox.Tweet=true : textbox.Tweet=false;
    });
    
    panel->getFolder("Visibility")->addToggle("Image", true)->onToggleEvent([&](ofxDatGuiToggleEvent e) {
        e.checked == true ? imgbox.ImageVisible = true : imgbox.ImageVisible = false;
    });
    
    panel->getFolder("Visibility")->expand();
    
    //Add navigating buttons
    panel->addFolder("Data Navigation", ofColor::green);
    
    panel->getFolder("Data Navigation")->addButton("Last Post")->onButtonEvent([&](ofxDatGuiButtonEvent button){
        if(tweet != json.begin()) {
            tweet--;
            updateTweet();
        } else {
            ofSystemAlertDialog("You are on the first post");
        }
    });
    
    panel->getFolder("Data Navigation")->addButton("Next Post")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        
        if(++tweet != json.end()) {
            updateTweet();
        } else {
            tweet--;
            ofSystemAlertDialog("You are on the last post");
        }
    });
    
    panel->getFolder("Data Navigation")->addButton("Last unlabeled post")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        ofJson::iterator tempj;
        if(tweet != json.begin()) {
            tempj = tweet;
            tempj--;
        } else {
            ofSystemAlertDialog("You are at the beginning of the set");
            return;
        }
        while(tempj != json.begin() && !tempj.value()["label"].is_null()) {
            tempj--;
        }
        if(!tempj.value()["label"].is_null()) {
            ofSystemAlertDialog("All tweets are labeled before");
        } else {
            tweet = tempj;
            updateTweet();
        }
    });
    
    panel->getFolder("Data Navigation")->addButton("Next unlabeled post")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        ofJson::iterator tempj;
        if(++tweet != json.end()) {
            tempj = --tweet;
            tempj++;
        } else {
            ofSystemAlertDialog("You are at the end of the set");
            tweet--;
            return;
        }
        while(tempj != json.end() && !tempj.value()["label"].is_null()) {
            tempj++;
        }
        if(!tempj.value()["label"].is_null()) {
            ofSystemAlertDialog("Tweet all labeled after");
        } else {
            tweet = tempj;
            updateTweet();
        }
    });
    panel->getFolder("Data Navigation")->expand();
    
    
    //Adds dropdown menu selection for mode
    vector<string> modeOptions = {"Binary", "Custom"};
    panel->addDropdown("Mode Selection", modeOptions);
    panel->getDropdown("Mode Selection")->onDropdownEvent(this, &ofApp::onModeSelectionEvent);
    panel->getDropdown("Mode Selection")->select(0);
    
    //Setting up labeling panel
    
    //text input field to add custom
    panel->addTextInput("Label Option");
    panel->getTextInput("Label Option")->onTextInputEvent([&](ofxDatGuiTextInputEvent input) {
        addLabelOption(input.text, labelOptions);
        input.target->setText("");
        ofLog() << input.text;
    });
    
    //initialize labelbox with binary label
    onModeChange(labelOptions);
    labelingBox.setup(labelOptions, "labels", ofGetWidth()-210, panel->getHeight());
    
    
    //default settings
    
    currMode = Mode::Binary;
    
    //path to JSON
    importFile();//datapoints initialized
    
    if(currJsonPath.empty()) {
        ofExit();
        std::exit(0);
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
    //sea green
    ofSetColor(18, 55, 34, 188);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    //draw main rectangle
    ofSetColor(253, 255, 208, 200);
    ofDrawRectangle(0, 0, ofGetWidth()-220, ofGetHeight());
    
    //draw frame for main rectangle
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(10);
    ofDrawRectangle(0, 0, ofGetWidth()-220, ofGetHeight());
    
    ofFill();
    ofSetColor(255);
    imgbox.draw();
    ofSetColor(0);
    ofDrawBitmapString("Image", imgbox.x + imgbox.img.getWidth()/2-5, imgbox.y-20);
    textbox.draw();
    timestampBox.draw();
    
    labelingBox.draw();
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
    updateTweet();
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
        ofSystemAlertDialog("Invalid empty path");
        return false;
    }
    ofFile file(ofToDataPath(path));
    if(file.exists()) {
        ofSystemAlertDialog("Json loaded successfully");
        json = ofLoadJson(path);
        tweet = json.begin();
        ofLog() << "json is of size: " << json.size();
        ofBackground(255);
        updateTweet();
        return true;
    } else {
        ofSystemAlertDialog("file not found or invalid");
        return false;
    }
}

void ofApp::saveJson(const std::string &path, const ofJson jsonToSave) {
    ofSaveJson(path, jsonToSave);
    ofSystemAlertDialog("Json File saved successfully");
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
    labelingBox.clear();
    labelingBox.add(group);
}

void ofApp::removeLabelOption(const std::string &buttonName, ofParameterGroup &group) {
    group.remove(buttonName);
}

void ofApp::onModeChange(ofParameterGroup &group) {
    if(group.size() != 0) {
        group.clear();
    }
    labelingBox.clear();
    switch(currMode) {
        case Mode::Binary:
            panel->getTextInput("Label Option")->setEnabled(false);
            addLabelOption("yes", group);
            addLabelOption("no", group);
            break;
        case Mode::Custom:
            panel->getTextInput("Label Option")->setEnabled(true);
            break;
    }
}

void ofApp::onModeSelectionEvent(ofxDatGuiDropdownEvent e) {
    currMode = static_cast<Mode>(e.child);
    bool inputBoxEnabled = panel->getTextInput("Label Option")->getEnabled();
    if(currMode == Mode::Custom && !inputBoxEnabled) {
        onModeChange(labelOptions);
    } else if(currMode == Mode::Binary && inputBoxEnabled){
        onModeChange(labelOptions);
    }
    ofLog() << "Index: " << e.child << " was selected";
}

void ofApp::importFile() {
    ofFileDialogResult result = ofSystemLoadDialog("Please Import JSON file");
    if(result.bSuccess) {
        currJsonPath = result.getPath();
        loadJson(currJsonPath);
    } else {
        ofSystemAlertDialog("Error in getting JSON file, please try again");
    }
}

void ofApp::updateTweet() {
    if(!tweet.value()["full_text"].empty()) {
        textbox.setup(tweet.value()["full_text"], "Tweet", (ofGetWidth()-220)*4/5, (ofGetWidth()-220)/10, ofGetHeight()*6/7);
    } else {
        textbox.setup("No text available", "Tweet", (ofGetWidth()-220)*4/5, (ofGetWidth()-220)/10, ofGetHeight()*6/7);
    }
    if(!tweet.value()["extended_entities"]["media"][0]["media_url_https"].empty()) {
        imgbox.setup(tweet.value()["extended_entities"]["media"][0]["media_url_https"], (ofGetWidth()-220)*4/5, ofGetHeight()*3/5,(ofGetWidth()-220)/10, ofGetHeight()/6);
        ofLog() << "Media url found " << tweet.value()["extended_entities"]["media"][0]["media_url_https"];
    } else {
        imgbox.setup("", (ofGetWidth()-220)*4/5, ofGetHeight()*3/5, (ofGetWidth()-220)/10, ofGetHeight()/6);
    }
    if(!tweet.value()["created_at"].empty()) {
        timestampBox.setup(tweet.value()["created_at"], "Timestamp", (ofGetWidth()-220)/3, (ofGetWidth()-220)/20, ofGetHeight()*1/10);
        timestampBox.setBackgroundEnabled(false);
    } else {
        timestampBox.setup("No Timestamp Available", "Timestamp", (ofGetWidth()-220)/3, (ofGetWidth()-220)/20, ofGetHeight()*1/10);
        timestampBox.setBackgroundEnabled(false);
    }
}
