//
//  JsonLoader.hpp
//  Data Marker
//
//  Created by Andy Chen on 11/21/19.
//  The purpose of the JsonLoader is to take in a path to a json file and check if its valid.
// if it is, we will then automatically process the hiearchy of information and give user options as to which information the user wants to see.

#ifndef JsonLoader_hpp
#define JsonLoader_hpp

#include <stdio.h>
#include "ofJson.h"
#include <unordered_set>
#include <vector>
#include <string>
namespace andyWong{

    struct dataPoint{
        int Id;
        ofJson data;
        std::string label;
    };

    class JsonLoader {
        private:
            std::unordered_set<std::string> fields;
            int size;
            bool jsonLoaded;
            
            ofJson json;
        public:
            JsonLoader();
            bool loadJson(const std::string &path);
            bool saveJson(const std::string &path);
            int jsonHeight(const ofJson& json, int currH);//for future use of visualizing JSON branch
            int jsonSize();
            bool beginLabeling();
            
    };
}

#endif /* JsonLoader_hpp */
