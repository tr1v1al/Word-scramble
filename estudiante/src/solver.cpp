
#include "solver.h"

// Es O(n²), donde n es el número de letras en letters. El interior del bucle while interior es O(1),
// de tal forma que el propio while interior es O(n) y en el peor caso, donde word tiene todas las letras o más y es de
// longitud n o más, el while interior reduce las iteraciones en una en cada iteración del while exterior y para cuando
// el vector auxiliar (copia de las letras introducidas) queda vacío o se comprueba que todas las letras están en word,
// las iteraciones terminan (Sum de i=0 a n de n-i) = (Sum de i=0 a n de i) = n+n-1+n-2+...+n-(n-1)+n-n =
// (n+1)*n - (Sum de i=0 a n de i) despejando queda -->
//
// (n+1)*n/2 = (Sum de i=0 a n de i) = (Sum de i=0 a n de n-i) --> O(n²)


bool Solver::wordHasLetters(const std::string &word, const std::vector<char> & letters) {
    bool matches = true;    // Booleano de retorno, true si word contiene letras de letters
    auto aux = letters;     // Vector de char auxiliar igual a letters para ir eliminando letras encontradas
    auto it_word = word.begin();
    // Recorremos la palabra word letra por letra
    while (it_word != word.end() && matches) {
        auto it_letters = aux.begin();
        bool found = false; // Booleano true si la letra de esta iteración aparece en aux
        while (it_letters != aux.end() && !found) {     // Recorremos el auxiliar
            if (toupper(*it_word) == *it_letters) {     // Si la letra aparece la eliminamos del aux
                std::swap(*it_letters, *(--aux.end()));
                aux.pop_back();
                found = true;
            }
            it_letters++;
        }
        if (!found) matches = false;        // Si una letra no aparece en el aux la palabra no es válida
        it_word++;
    }
    return matches;
}

Solver::Solver(const Dictionary &dict, const LettersSet &letters_set) {
    _dict = dict;
    _ls = letters_set;
}


std::pair<std::vector<std::string>, int>
Solver::getSolutions(const std::vector<char> &available_letters, bool score_game) {
    std::pair<std::vector<std::string>, int> ret_pair;

    if (score_game) {   // Juego por puntuación
        int max_score = 0, curr_score = 0;
        std::vector<std::string> aux;
        for (auto it : _dict)
            if (wordHasLetters(it, available_letters)) {
                curr_score = _ls.getScore(it);
                if (curr_score > max_score) {
                    max_score = curr_score;
                    aux.clear();
                    aux.push_back(it);
                }
                else if (curr_score == max_score)
                    aux.push_back(it);
            }
        ret_pair.first = aux;
        ret_pair.second = max_score;

    } else {    // Juego por longitud

        int num_letters = available_letters.size();     // Número de letras con las que jugamos
        while (num_letters > 0) {
            auto vec_length = _dict.wordsOfLength(num_letters);     // Palabras de num_letters letras
            std::vector<std::string> vec_letters;
            for (auto & it : vec_length)
                if (wordHasLetters(it, available_letters))
                    vec_letters.push_back(it);
            if  (vec_letters.size() == 0)   // Si no hay palabras de longitud num_letters que sean solución, probamos
                num_letters--;              // con num_letters--
            else {                          // Si existen tales palabras, son la solución buscada
                ret_pair.first = vec_letters;
                ret_pair.second = num_letters;
                num_letters = -1;
            }
        }
    }
    return ret_pair;
}