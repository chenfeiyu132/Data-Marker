#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //path to JSON
   ofFileDialogResult result = ofSystemLoadDialog("Import JSON file");
    if(result.bSuccess) {
        currJsonPath = result.getPath();
        loadJson(currJsonPath);
    } else {
        ofSystemAlertDialog("JSON file not found or invalid JSON file");
        ofExit();
        std::exit(0);
    }
    
    initializeDataGroup(""); //datapoints initialized
    currMode = Mode::Binary; //default mode
    
    panel = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    
    //Add import and export buttons
    panel->addButton("Import");
    panel->getButton("Import")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        ofSystemAlertDialog("Please Select JSON File to be imported");
        currJsonPath = result.getPath();
        loadJson(currJsonPath);
    });
    panel->addButton("Export")->onButtonEvent([&](ofxDatGuiButtonEvent button) {
        saveJson(currJsonPath, json);
    });
    
    
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
    
    //initialize labelbox with binary labels
    onModeChange(labelOptions);
    labelingBox.setup(labelOptions, "labels", 300, 300);
    
    ofBackground(255);
    if(!tweet.value()["full_text"].empty()) {
        textbox.setup(tweet.value()["full_text"], 200, 200);
    } else {
        textbox.setup("No text available", 200, 200);
    }
    if(!tweet.value()["entities"]["urls"].empty()) {
        imgbox.setup(tweet.value()["entities"]["urls"][0], 30, 50);
    } else {
        imgbox.setup("", 30, 50);
    }
    
    
    parameterGroup.add(textbox.Tweet);
    parameterGroup.add(imgbox.ImageVisible);
    visibility.setup(parameterGroup);
    
    
    
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
        ofSystemAlertDialog("Invalid empty path");
        return false;
    }
    ofFile file(ofToDataPath(path));
    if(file.exists()) {
        ofSystemAlertDialog("found file = " + path + " loading");
        json = ofLoadJson(path);
        ofLog() << "json is of size: " << json.size();
        return true;
    } else {
        ofSystemAlertDialog("found not found or invalid");
        return false;
    }
}

void ofApp::saveJson(const std::string &path, const ofJson jsonToSave) {
    ofSaveJson(path, jsonToSave);
    ofSystemAlertDialog("Json File saved successfully");
}

bool ofApp::initializeDataGroup(const std::string &groupname) {
    
    if(groupname == ""){
        if(json.is_null()) {
            ofLog() << "group does not exist";
            return false;
        }
    } else {
        if(json[groupname].is_null()) {
            ofLog() << "group does not exist";
            return false;
        }
    }
    datasetSize = 0;
    if(groupname == ""){
        tweet = json.begin();
    } else {
        tweet = json[groupname].begin();
    }
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
