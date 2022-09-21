/**
 * @file solver.h
 * @brief  Archivo de declaración de la clase Solver.
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 * @date Diciembre de 2021.
 * @details Se consigue un vector de palabras enlazadas con su puntuación las palabras de un TDA Dictionary; las
 * palabras aceptadas en la partida; que se puedan formar como combinación de un subconjunto de las letras de un TDA
 * LettersSet; información de letras aceptadas (repeticiones y puntuación); cuyas puntuaciones vendrán dadas por la
 * longitud máxima o la máxima suma de puntuación de cada letra para cada palabra, según se elija (la puntuación
 * devuelta en cada palabra debe tener el mismo valor, ya que se devuelve más de un elemento en el vector si existen
 * palabras que comparten la puntuación máxima).
 */

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "dictionary.h"
#include "letters_set.h"
#include <vector>
#include <string>

/**
 * @brief Clase Solver.
 */
class Solver {
private:
    /**
     * @brief palabras admitidas introducidas en formato TDA Dictionary.
     */
    Dictionary _dict;

    /**
     * @brief información de las letras admitidas en formato TDA LettersSet.
     */
    LettersSet _ls;

    /**
     * @brief Comprueba si una palabra se puede formar con las letras de un vector de caracteres.
     * @param word palabra.
     * @param letters letras del vector de caracteres.
     * @details Cada carácter del vector solo se puede usar una vez. Además está función es O(n²).
     * @return 1 (True) si se puede, 0 (false) si no se puede.
     */
    bool wordHasLetters(const std::string & word, const std::vector<char>  & letters);
public:
    /**
     * @brief Constructor con parámetros
     * @param dict
     * @param letters_set
     * @details Crea Solver con un Dictionary @p dict y un LettersSet @p letters_ser asociados
     * Claramente O(1)
     */
    Solver(const Dictionary & dict, const LettersSet & letters_set);
    /**
     * @brief Construye un vector de pares de palabra y su puntuación con todas las palabras puntuación
     * máxima del _dict que se puedan formar con las letras de un vector introducido.
     * @param available_letters vector de letras cuyas combinaciones se tomarán en cuenta.
     * @param score_game si es 1 se juega por puntuación; 0, por longitud.
     * @return vector de pares de palabra y su puntuación con todas las palabras puntuación máxima del _dict
     * que se puedan formar con las letras de @p available_letters y cuya puntuación depende del modo de juego,
     * pero todas las puntuaciones asociadas del vector son la misma, que que se eligen las palabras de mayor
     * longitud o puntuación según @p score_game.
     */
    std::pair<std::vector<std::string>, int> getSolutions(const std::vector<char> & available_letters, bool score_game);
};

#endif