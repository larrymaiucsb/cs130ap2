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
    sHash.resize(tsize);
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
        int size = table[i].size();
        vector<string> tableOne = table[i];
        if (size > max_size)
        {
            max_size = size;
            counter3 = table[i];
            counter3.resize(max_size);
            
        }
        
        counter2[size]++;
    }

   


   
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
            
            while(checker == false){
              
              counter++;
               Hash24 nH;
                for(int j =0; j < table[i].size(); j++){
                  
                    string word;
                    word = table[i][j];
                    int index = nH.hash(table[i][j]);
                    index = nH.hash(index);
                    index = index % newsize;
                    if (v[index].empty()){
                       
                        v[index] = word;
                        if(j== table[i].size()-1){
                            checker = true;
                            table[i] = v;
                            sHash[i] = nH;
                             
                        }
                        
                    }
                    else{
                      checker = true;
                      
                              
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
     

    

    for(int i = 1; i < 21; i++){
        cout << "# of secondary hash tables trying " << i << " hash functions = " << counter1[i] <<endl;
    }
    
    
    cout << "Average # of hash functions tried = "  <<endl;
    
    
}
    
    
    
    
