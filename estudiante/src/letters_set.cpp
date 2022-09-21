/**
 * @file letters_set.cpp
 * @brief  Archivo de implementación del TDA LettersSet
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 */

#include "letters_set.h"

LettersSet::LettersSet(){};

LettersSet::LettersSet(const LettersSet & other){
    *this = other;
};

bool LettersSet::insert(const std::pair<char, LetterInfo> & val){
    auto it = letters.find(val.first);
    if (it == letters.end()) {
        auto ret = letters.insert(val);
        return ret.second;
    } else
        return false;
}

bool LettersSet::erase(const char & key){
    return letters.erase(key);
}

void LettersSet::clear(){
    letters.clear();
}

bool LettersSet::empty() const{
    return letters.empty();
}

unsigned int LettersSet::size() const{
    return letters.size();
}

int LettersSet::getScore(std::string word){
    int sum = 0;
    for (auto & it : word)
        sum += letters[toupper(it)].score;
    return sum;
}

LettersSet & LettersSet::operator=(const LettersSet & cl) = default;

LetterInfo & LettersSet::operator[](const char & val){
    return letters[val];
}

std::ostream & operator<<(std::ostream & os, const LettersSet & cl){
    os << "Letra Cantidad Puntos" << std::endl;
    for(auto & it : cl.letters)
        os << it.first << " " << it.second.repetitions << " " << it.second.score << std::endl;
    return os;
}

std::istream & operator>>(std::istream & is, LettersSet & cl){
    std::pair<char, LetterInfo> newpair;
    std::string letra, cantidad, puntos;
    is >> letra >> cantidad >> puntos;
    while(is) {
        is >> newpair.first >> newpair.second.repetitions >> newpair.second.score;
        cl.insert(newpair);
    }
    return is;
}

std::vector<std::pair<char, int>> LettersSet::getContent() const {
    std::vector<std::pair<char, int>> vec;
    for (auto & it : letters) {
        std::pair<char, int> p = {it.first, it.second.repetitions};
        vec.push_back(p);
    }
    return vec;
}