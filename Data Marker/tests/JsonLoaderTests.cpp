//
//  JsonLoaderTests.cpp
//  Data Marker Tests
//
//  Created by Andy Chen on 11/24/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "../src/JsonLoader.hpp"

TEST_CASE("jsonLoading") {
    andyWong::JsonLoader json;
    SECTION("loading json with correct path") {
        REQUIRE(json.loadJson("/Users/Ju1y/Documents/Openframeworks/apps/myApps/fantastic-finale-chenfeiyu132/example_2.json"));
    }
    SECTION("loading json with random path") {
        REQUIRE(!json.loadJson("asdasdadad"));
    }
    SECTION("loading json with empty path") {
        REQUIRE(!json.loadJson(""));
    }
}
