/**
 * @file letters_bag.cpp
 * @brief  Archivo de implementación del TDA LettersBag
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 */

#include "letters_bag.h"

LettersBag::LettersBag() = default;

void LettersBag::copy(const LettersSet & letterSet){
    int num = 0;
    auto vec = letterSet.getContent();
    for (auto & it : vec)
        for (int i = 0; i < it.second; ++i)
            letters.add(it.first);
}

LettersBag::LettersBag(const LettersSet & letterSet) {
    copy(letterSet);
}

void LettersBag::insertLetter(const char & l){
    letters.add(l);
}

char LettersBag::extractLetter(){
    return letters.get();
}

std::vector<char> LettersBag::extractLetters(int num){
    std::vector<char> ret;
    for (int i = 0; i < num; ++i)
        ret.push_back(extractLetter());
    return ret;
}

void LettersBag::clear(){
    letters.clear();
}

unsigned int LettersBag::size(){
    return letters.size();
}

LettersBag & LettersBag::operator=(const LettersBag & other) = default;