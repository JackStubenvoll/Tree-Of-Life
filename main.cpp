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
    std::cout << test->findDistance("Animalia", "Acanthocephala Rudolphi") << std::endl;
    std::cout << test->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") << std::endl;
    return 0;
}