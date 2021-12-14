#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//int main(){
int main()
{
    Tree* test = new Tree();
    // std::cout << test->find("Apororhynchus aculeatus") << std::endl;
    // std::cout << test->mostConnected(test->root) << std::endl;
    // std::cout << "dist1: " << test->findDistance("Animalia", "Acanthocephala") << std::endl;
    // std::cout << "dist2: " << test->findDistance("Animalia", "Apororhynchida Thapar") << std::endl;
    // std::cout << "dist3: " << test->findDistance("Gigantorhynchus Hamann", "Apororhynchida Thapar") << std::endl;
    // std::cout << test->lowestCommonAncestor("Apororhynchidae Shipley", "Giganthorhynchidae Hamann") << std::endl;
    // std::cout << test->lowestCommonAncestor("Animalia", "Apororhynchida Thapar") <<std::endl;
    string input;
    std::cout << "Input query for find: ";
    std::getline(cin, input);
    std::cout << "\nReturn value: " << test->find(input) << std::endl;
    
    std::cout << "Input query for mostConnected: ";
    std::getline(cin, input);
    std::cout << "\nReturn value: " << test->mostConnected(input) << std::endl;

    string input2;
    std::cout << "Input first query for findDistance: ";
    std::getline(cin, input);
    std::cout << "\nInput second query for findDistance: ";
    std::getline(cin, input2);
    std::cout << "\nReturn value: " << test->findDistance(input, input2) << std::endl;

    std::cout << "Input first query for lowestCommonAncestor: ";
    std::getline(cin, input);
    std::cout << "\nInput second query for lowestCommonAncestor: ";
    std::getline(cin, input2);
    std::cout << "\nReturn value: " << test->lowestCommonAncestor(input, input2) << std::endl;
    return 0;
}
