//
//  JsonLoader.cpp
//  Data Marker
//
//  Created by Andy Chen on 11/21/19.
//

#include "JsonLoader.hpp"

namespace andyWong {
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
            return true;
        } else {
            ofLog() << "file not found for state name = "<<path;
            return false;
        }
    }

    
}

