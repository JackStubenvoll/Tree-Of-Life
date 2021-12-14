#include "cs225/catch/catch.hpp"
#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
TEST_CASE("find including not valid searches", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->find("Apororhynchus aculeatus") == "Apororhynchus aculeatus Meyer, 1931 [species]");
    cout<<"search result:" <<tree->find("Apororhynchus aculeatus") << endl;
    REQUIRE(tree->find("Sterreria rubra") == "Sterreria rubra (Faubel, 1976) [species]");
    cout<<"search result:" <<tree->find("Sterreria rubra") << endl;
    
    REQUIRE(tree->find("connorjackjeffcarlos") == "Query not found");
    cout<<"search result:" <<tree->find("connorjackjeffcarlos")<<endl;
}

TEST_CASE("mostConnected() works for whole tree", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->mostConnected(tree->root) == "Curculionidae Latreille, P.A., 1802 [family]");
    cout<<"most connected: "<<tree->mostConnected(tree->root) << endl;
}

TEST_CASE("mostConnected(strong)","[tree]"){
Tree* tree = new Tree();
    REQUIRE(tree->mostConnected("Acanthocephala")=="Neoechinorhynchus Stiles & Hassall, 1905 [genus]");
    cout<<"most connected: "<<tree->mostConnected("Acanthocephala")<<endl;
    REQUIRE(tree->mostConnected("Gigantorhynchus Hamann")=="Gigantorhynchus Hamann, 1892 [genus]");
    cout<<"most connected: "<< tree->mostConnected("Gigantorhynchus Hamann") << endl;
}

TEST_CASE("findDistance() output test", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->findDistance("Gigantorhynchus Hamann", "Apororhynchida Thapar") == 4);
    cout << "disntance:" <<tree->findDistance("Gigantorhynchus Hamann", "Apororhynchida Thapar") <<endl;
    REQUIRE(tree->findDistance("Gigantorhynchus Hamann", "Gigantorhynchus Hamann")==0);
    cout << "disntance:" << tree->findDistance("Gigantorhynchus Hamann", "Gigantorhynchus Hamann")<< endl;
    REQUIRE(tree->findDistance("Animalia", "Apororhynchida Thapar")==3);
    cout<< "disntance:" << tree->findDistance("Animalia", "Apororhynchida Thapar") << endl;
}

TEST_CASE("lowestCommonAncestor() output test", "[tree]") {
Tree* tree = new Tree();
    REQUIRE(tree->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") == "Archiacanthocephala Meyer, 1931 [class]");
    cout<< "lowest common ancestor:" << tree->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") << endl;
    REQUIRE(tree->lowestCommonAncestor("Animalia", "Apororhynchida Thapar") =="Animalia [kingdom]");
    cout<< "lowest common ancestor:" << tree->lowestCommonAncestor("Animalia", "Apororhynchida Thapar") << endl;
}

