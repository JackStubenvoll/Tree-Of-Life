#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    //ifstream inputfile;
    std::cout << " cock and ball torture 1" << std::endl;
    Tree* test = new Tree();
    std::cout << "cock and ball torture 2" << std::endl;
    std::cout << test->find("Apororhynchus aculeatus") << std::endl;
    std::cout << test->mostConnected(test->root) << std::endl;
    std::cout << "dist1: " << test->findDistance("Animalia", "Acanthocephala") << std::endl;
    std::cout << "dist2: " << test->findDistance("Animalia", "Apororhynchida Thapar") << std::endl;
    std::cout << "dist3: " << test->findDistance("Gigantorhynchus Hamann", "Apororhynchida Thapar") << std::endl;
    std::cout << test->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") << std::endl;
    return 0;
}