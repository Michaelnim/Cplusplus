#include "Word.h"

Word::Word(std::string firstWord) {
	word = firstWord;
}

std::string Word::getWord() const {
	return word;
}

