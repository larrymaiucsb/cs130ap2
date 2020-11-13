#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "hash24.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Dictionary{
    public:

        Dictionary(string fname, int tsize);


        bool find(string word);
        void writeToFile(string fname);
        static Dictionary readFromFile(string fname);
       

    private:

        Dictionary();

        size_t tsize;
        vector<string>* sTables;
        vector<vector<string> > table;
        //vector<string>* table;
        Hash24 pHash;
        vector<Hash24> sHash;
};
#endif