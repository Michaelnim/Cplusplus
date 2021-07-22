#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <string>
#include "word.h"

using namespace std;

class hashTable
{
private:
    struct Table
    {
        Word word;
        Table* next;
    };
    Table** table;
    const int SIZE = 10000;

public:
    hashTable();
    ~hashTable();
    void displayHash() const;
    void insertWord(std::string word);
    bool findWord(std::string word);
    int hashFunction(std::string word);
    
};

#endif
