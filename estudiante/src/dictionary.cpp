/**
 * @file dictionary.cpp
 * @brief  Archivo de implementación del TDA Dictionary
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 */

#include "dictionary.h"

Dictionary::Dictionary() = default;

Dictionary::Dictionary(const Dictionary &other) = default;

bool Dictionary::exists(const std::string &val) const {
    return (words.find(val) != words.end());
}

bool Dictionary::insert(const std::string &val){
    if (!exists(val)){
        auto ret = words.insert(val);
        return ret.second;
    } else
        return false;
}

bool Dictionary::erase(const std::string &val){
    return words.erase(val);
}

void Dictionary::clear(){
    words.clear();
}

bool Dictionary::empty() const{
    return words.empty();
}

unsigned int Dictionary::size() const{
    return words.size();
}

int Dictionary::getOccurrences(const char c){
    int count = 0;
    for (auto & it1 : words)
        for (auto & it2 : it1)
            if (it2 == c)
                count++;
    return count;
}

int Dictionary::getTotalLetters(){
    int count = 0;
    for (auto & it : words)
        count += it.length();
    return count;
}

std::vector<std::string> Dictionary::wordsOfLength(int length){
    std::vector<std::string> ret;
    for (auto & it : words)
        if (it.length() == length)
            ret.push_back(it);
    return ret;
}

std::ostream & operator<<(std::ostream & os, const Dictionary & dic) {
    for (auto & it : dic.words)
        os << it << std::endl;
    return os;
}

std::istream & operator>>(std::istream & is, Dictionary & dic) {
    std::string word;
    is >> word;
    while (is) {
        dic.insert(word);
        is >> word;
    }
    return is;
}