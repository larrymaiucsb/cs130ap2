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
        Dictionary(size_t tsize, string* pTable, vector<string>* sTables, Hash24 pHash, Hash24* sHashes){
            this->tsize = tsize;

        }
        ~Dictionary();

        bool find(string word);
        void writeToFile(string fname);
        static Dictionary readFromFile(string fname);

    private:

        Dictionary();

        size_t tsize;
        
        vector<vector<string> > table;
        Hash24 pHash;
        vector<Hash24> sHash;
};
#endif