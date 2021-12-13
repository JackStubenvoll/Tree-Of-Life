#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    ifstream inputfile;
    Tree::Tree* test = new Tree::Tree();
    std::cout << test->find("Animalia") << std::endl;
}