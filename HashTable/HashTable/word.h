#ifndef WORD_H_
#define WORD_H_

#include <string>

class Word
{
private:
	std::string word;
public:
	Word() { word = ""; };
	Word(std::string w);
	std::string getWord() const;
};

#endif