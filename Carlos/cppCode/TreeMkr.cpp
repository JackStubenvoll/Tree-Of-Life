#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
Tree::Tree(int order){
    ifstream inputfile;
    string textfile = "AnimalKingdom.txt";
    inputfile.open(textfile);
    while(getline(inputfile, temp)){
        for(int i = 0; i < 1593758; i++){
            storage[i] = temp;
        }
        int tmp = 0;
        cout<< "got line " << temp << " " << endl;
        tmp++;
    }
}
Tree::~Tree(){
}
Tree::Tree(const Tree& other){
}