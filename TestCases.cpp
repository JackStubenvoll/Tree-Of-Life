#include "cs225/catch/catch.hpp"
#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

TEST_CASE("find including not valid searches", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->find("Apororhynchus aculeatus") == "Apororhynchus aculeatus Meyer, 1931 [species]");
    REQUIRE(tree->find("Sterreria rubra") == "Sterreria rubra (Faubel, 1976) [species]");
    REQUIRE(tree->find("connorjackjeffcarlos") == "Query not found");
}

TEST_CASE("mostConnected() works for whole tree", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->mostConnected(tree->root) == "Curculionidae Latreille, P.A., 1802 [family]");
}

TEST_CASE("findDistance() output test", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->findDistance("Gigantorhynchus Hamann", "Apororhynchida Thapar") == 4);
    REQUIRE(tree->findDistance("Gigantorhynchus Hamann", "Gigantorhynchus Hamann")==0);
    REQUIRE(tree->findDistance("Animalia", "Apororhynchida Thapar")==3);
}

TEST_CASE("lowestCommonAncestor() output test", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") == "Archiacanthocephala Meyer, 1931 [class]");
    REQUIRE(tree->lowestCommonAncestor("Animalia", "Apororhynchida Thapar") =="Animalia [kingdom]");
}
