/**
 * @file letters_set.h
 * @brief  Archivo de especificación del TDA LettersSet.
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 * @date Noviembre-Diciembre de 2021.
 * @details Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra.
 */

#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <map>
#include <string>
#include <iostream>
#include <vector>

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

struct LetterInfo {
    /**
     * @brief Número de veces que se puede usar char.
     */
    int repetitions;
    /**
     * @brief Puntuación de una letra a la que irá asociada en LetterSet.
     */
    int score;
};
/**
 * @brief TDA LettersSet
 */
class LettersSet {
private:

    /**
     * @brief map donde se relaciona cada char con su información.
     */
    std::map <char, LetterInfo> letters;
public:

    /**
      * @brief Constructor por defecto.
      * @return el objeto LettersSet creado.
      * @post Genera una instancia de la clase LettersSet con letters vacío.
      */
    LettersSet();

    /**
      * @brief Constructor por copia.
      * @return el objeto LettersSet creado.
      * @post Genera una instancia de la clase LettersSet igual a la introducida.
      */
    LettersSet(const LettersSet & other);

    /**
      * @brief Función para añadir un carácter y su información al mapa letters.
      * @param[in] val pareja de carácter e información LetterInfo a añadir.
      * @return devuelve si se ha podido añadir(true), o ya estaba(false).
      */
    bool insert(const std::pair<char, LetterInfo> & val);

    /**
      * @brief Función para borrar un carácter y su información.
      * @param[in] key char a borrar.
      * @return si se ha borrado (true) o no (false).
      */
    bool erase(const char & key);

    /**
      * @brief Función para vaciar letters.
      */
    void clear();

    /**
      * @brief Función para conocer si el objeto referido LettersSet está vacío (equivalente a que el map esté vacío).
      * @return Si el objeto referido LettersSet está vacío.
      */
    bool empty() const;

    /**
      * @brief Función para conocer el número de chars de los que se tiene información en este objeto LettersSet.
      * @return Número de chars del objeto referido LettersSet.
      */
    unsigned int size() const;
    /**
     * @brief Se calcula la puntuación de una palabra sumando la puntuación de cada letra.
     * @param word palabra cuya puntuación se va a calcular.
     * @return suma de las puntuaciones de cada char de la palabra, aunque se repita.
     */
    int getScore(std::string word);

    /**
     * @brief operador de asignación.
     * @param cl objeto LettersSet cuyos valores asignaremos.
     * @return valor asignado al objeto LettersSet que llama a =, para concatenar asignaciones.
     */
    LettersSet & operator=(const LettersSet & cl);

    /**
     * @brief operador consulta para la información en formato LetterInfo de un char introducido.
     * @param val char introducido.
     * @return Información en formato LetterInfo de @p val.
     */
    LetterInfo & operator[](const char & val);

    /**
    * @brief Sobrecarga del operador <<, para imprimir en pantalla cada letra y su información de un objeto LettersSet.
    * @param os Objeto ostream usado.
    * @param cl LettersSet a imprimir.
    * @return @p os, para concatenar salidas en caso de ser necesario.
    */
    friend std::ostream & operator<<(std::ostream & os, const LettersSet & cl);

    /**
    * @brief Sobrecarga del operador <<, para insertar caracteres y su información.
    * @param is Objeto istream usado.
    * @param cl LettersSet a insertar.
    * @return @p is, para concatenar entradas en caso de ser necesario.
    */
    friend std::istream & operator>>(std::istream & is, LettersSet & cl);

    /**
     * @brief Función que almacena en un vector de pareja char, int, los caracteres y sus repeticiones de un objeto
     * LettersSet.
     * @return vector de pareja char, int, los caracteres y sus repeticiones del objeto LettersSet referenciado.
     */
    std::vector<std::pair<char, int>> getContent() const;
};

#endif
