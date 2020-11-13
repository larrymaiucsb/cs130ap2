#include "hash24.h"
#include "dictionary.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;



Dictionary::Dictionary(string fname, int tsize){
    vector<int> counter1;
    vector<int> counter2;
    vector<string> counter3;
    ifstream f;
    f.open(fname);
    string line;
    int number_of_lines = 0;


    table.resize(tsize);   
    counter1.resize(21);
    counter2.resize(21);
         
    while (getline(f, line))
    {
        number_of_lines++; 
            int index = pHash.hash(line);
            //index = pHash.hash(index);
            index = index % tsize;
        

       
        
            table[index].push_back(line);           //makes vectors of elements in each slot usiong primary hash only
        
    }

    int max_size = 0;

    for (int i = 0; i < tsize; i++)
    {
        cout << i<<endl;
        int size = table[i].size();
        vector<string> tableOne = table[i];
        if (size > max_size)
        {
            max_size = size;
            counter3 = table[i];
            cout << "51"<<endl;
        }
        cout << "53"<<endl;
        counter2[size]++;
    }

    cout << "57" << endl;

    for (int i = 0; i < tsize; i++)
    {
        int counter = 0;
        
        if(table[i].size() == 0){
            
        }

        else
        {
            int newsize = table[i].size() * table[i].size();
            vector<string> v;
            v.resize(newsize);
            bool checker = false;
            Hash24 nH;
            while(checker == false){
                counter++;
               nH = Hash24();
                for(int j =0; j < table[i].size(); j++){
                    string word;
                    word = table[i][j];
                    int index = nH.hash(table[i][j]);
                    //index = nH.hash(index);
                    index = index % newsize;
                    if (v[index].empty()){   
                        v[index] = word;
                        if(j== table[i].size()-1){
                            checker = true;

                        }
                    }
                    else{
                        break;        
                    }
    
                }
            }

        }

        counter1[counter]++;
       


    }
    
    pHash.dump();
    cout <<"Number of words = "<< tsize<<endl;
    cout<<"Table size = "<< tsize<<endl;
    cout<<"Max collisions = " << max_size<<endl;
    for(int i = 0; i < 21; i++){
        cout << "# of primary slots with " << i << " words = "<< counter2[i]<<endl;
    }
    cout << "** Words in the slot with most collisions ***"<<endl;
    for(int i = 0; i < counter3.size(); i++){
        cout<< counter3[i]<<endl;
    }


    int sum1 = 0;

    for(int i = 0; i < 21; i++){
        cout << "# of secondary hash tables trying " << i << "hash functions = " << counter1[i]<<endl;
        sum1 += counter1[i] * i;
    }
    double average = sum1/tsize;
    
    cout << "Average # of hash functions tried = " << average <<endl;
    
    
}
    
    
    
    
    
    /*
    
    bool Dictionary::find(string word){
        if (word == )
    }
    void Dictionary::writeToFile(string fname){

        ofstream file_obj;
        file_obj.open(fname, ios::out | ios::trunc);
        file_obj.write((char*)&pHash, sizeof(pHash));

        file_obj.write((char*&pHash, sizeof(pHash));

        for (int =0; i < this->tsize; i++){
            string word= this->pTable[i];
            int wordLength = this->pTable[i].size();
            file_obj.write((char*)&wordLength, sizeof(wordLength));
            file_obj.write(word.c_str(), wordLength); 

        }

        for(int k =0; k < this->tsize; k++){
            Hash24 temp = this->sHashes[k];
            size_t size = sizeof(temp);
            file_obj.write((char*)&temp, size);
        }

        for(int m = 0; m <this->tsize; m++){
            int vecSize = this->sTables [m].size();
            file_obj.write((char*)&vecSize, sizeof(vecSize));

            for(int n = 0; n < vecSize; n++){
                string word = this->sTables[m][n];
                int wordLength = word.size();
                file_obj.write((char*)&wordLength, sizeof(wordLength));
                file_obj.write(word.c_str(), wordLength);
                wordLength = 0;
            }
        }

        file_obj.close();
        return;
    }



    Dictionary Dictionary::readFromFile(string fname){
        ifstream file_obj;
        file_obj.open(fname, ios::in | ios::binary);

        size_t tsize;
        file_obj.read((char*)&tsize, sizeof(tsize));

        Hash24 pHash;
        file_obj.read((char*)&pHash, sizeof(pHash));

        string* pTable = new string[tsize];
        for(int i = 0; i < tsize; i++){
            int size = 0;
            file_obj.read((char*)&size, sizeof(size));
            char* strData= new char[size];
            file_obj.read(strData, size);
            string word(strData);
            word = word.substr(0,size);
            pTable[i] = word;
            delete[] strData;
        }

        Hash24* sHashes = new Hash24[tsize];
        for(int i = 0; i < tsize; i++){
            Hash24 temp;
            file_obj.read((char*)&temp, sizeof(temp));
            sHashes[i] = temp;
        }

        vector<string>* sTables = new vector<string>[tsize];
        for(int i = 0; i < tsize; i++){
            int vLength;
            file_obj.read((char*)&vLength, sizeof(vLength));
            sTables[i].resize(vLength);
            for(int j = 0; j < vLength; j++){
                int wLength;
                file_obj.read((char*)&wLength, sizeof(wLength));

                char* strData= new char[wLength];
                file_obj.read(strData, wLength);
                string word(strData);
                word = word.substr(0, wLength);
                sTables[i][j] = word;
                delete[] strData;
                }
            }
        file_obj.close();

        Dictionary dict(tsize, pTable, sTables, pHash, sHashes);

        return dict;

        }

}
*/