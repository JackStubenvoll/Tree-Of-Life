#include "cs225/catch/catch.hpp"
#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
Tree* tree = new Tree();
TEST_CASE("find() prints the correct line", "[tree]") {
    REQUIRE(tree->find("Apororhynchus aculeatus") == "Apororhynchus aculeatus Meyer, 1931 [species]");
    REQUIRE(tree->find("Sterreria rubra") == "Sterreria rubra (Faubel, 1976) [species]");
}

TEST_CASE("mostConnected() works for whole tree", "[tree]") {

    REQUIRE(tree->mostConnected(tree->root) == "Curculionidae Latreille, P.A., 1802 [family]");
}

TEST_CASE("findDistance() output test", "[tree]") {

    REQUIRE(tree->findDistance("Gigantorhynchus Hamann", "Apororhynchida Thapar") == 4 );
}

TEST_CASE("lowestCommonAncestor() output test", "[tree]") {

    REQUIRE(tree->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") == "Archiacanthocephala Meyer, 1931 [class]");
}