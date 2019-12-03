//
//  JsonLoader.cpp
//  Data Marker
//
//  Created by Andy Chen on 11/21/19.
//

#include "JsonLoader.hpp"

namespace andyWong {

JsonLoader::JsonLoader()
    :jsonLoaded(false)
    ,size(0)
    {}

bool JsonLoader::loadJson(const std::string& path) {
    if(path.empty()) {
        ofLog() << "Invalid empty path";
        return false;
    }
    ofFile file(ofToDataPath(path));
    if(file.exists()) {
        ofLog() << "found file = "<<path<<", loading";
        json = ofLoadJson(path);
        size = json.size();
        ofLog() << "json is of size: " << size;
        jsonLoaded = true;
        return true;
    } else {
        ofLog() << "file not found for state name = "<<path;
        return false;
    }
}
    
int JsonLoader::jsonSize() {
    return size;
}

bool JsonLoader::beginLabeling() {
    if(size == 0 && jsonLoaded) {
        ofLog() << "json empty please load valid json file";
        return false;
    } else if(!jsonLoaded) {
        ofLog() << "Please load json file first";
        return false;
    }
    ofLog() << "Labeling process starting";
}


    
}

