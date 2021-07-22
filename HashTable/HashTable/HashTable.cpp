#include <math.h>
#include <string>
#include <iostream>
#include "HashTable.h"


hashTable::hashTable()
{
    table = new Table * [SIZE];
    for (int i = 0; i < SIZE; i++)
        table[i] = nullptr;
}

hashTable::~hashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        Table* temp = table[i];
        while (table[i] != nullptr)
        {
            table[i] = table[i]->next;
            delete temp;
            temp = table[i];
        }

    }
    delete[] table;
}

void hashTable::displayHash() const
{
    Table* TablePtr;
    int len = 0;
    for (int i = 0; i < SIZE; i++)
    {
        len = 0;
        cout << i << ": ";
        TablePtr = table[i];
        if (table[i] != nullptr)
        {
            while (TablePtr != nullptr)
            {
                cout << TablePtr->word.getWord() << "-->";
                TablePtr = TablePtr->next;
                len++;
            }
        }
        cout << "Length: " << len << endl;
    }
}

void hashTable::insertWord(std::string word)
{
    int index = hashFunction(word);
    Table* currentPtr = table[index];
    Table* previousPtr = table[index];
    Table* newNode = new Table;
    newNode->word = word;
    newNode->next = nullptr;

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else {
        while (currentPtr != nullptr && newNode->word.getWord() > word)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (currentPtr == NULL) {
            newNode->next = previousPtr->next;
            previousPtr->next = newNode;
        }
        else if (previousPtr == table[index]) {
            newNode->next = table[index];
            table[index] = newNode;

        }
        else {
            previousPtr = previousPtr->next;
            newNode->next = previousPtr->next;
            previousPtr->next = newNode;
        }
    }
}

bool hashTable::findWord(std::string word)
{
    int index = hashFunction(word);
    Table* entry = table[index];
    Table* TablePtr;

    if (entry->word.getWord() == word)
    {
        return true;
    }
    else
    {
        TablePtr = entry;
        while (TablePtr->word.getWord() != word)
        {
            TablePtr = TablePtr->next;
            if (TablePtr->word.getWord() == word)
                return true;
        }
    }
    return false;
}

int hashTable::hashFunction(std::string word)
{
    int result = 0;
    for (unsigned i = 0; i < word.length(); i++)
    {
        result += word[i] * pow(3, i);
    }
    return result % SIZE;
}

