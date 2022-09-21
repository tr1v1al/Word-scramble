/**
 * @file dictionary.h
 * @brief  Archivo de especificación del TDA Dictionary.
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 * @date Noviembre-Diciembre de 2021.
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas.
 */

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class Dictionary {
private:

    /**
     * @brief Las palabras serán almacenadas en un set, ya que los elementos deben ordenarse alfabéticamente.
     */
       std::set<std::string> words;
public:

    /**
      * @brief Constructor por defecto.
      * @return el objeto Dictionary creado.
      * @post Genera una instancia de la clase Dictionary con set <string> words vacío.
      */
    Dictionary();

    /**
      * @brief Constructor por copia.
      * @return el objeto Dictionary creado.
      * @post Genera una instancia de la clase Dictionary igual a la introducida.
      */
    Dictionary(const Dictionary &other);

    /**
      * @brief Función para saber si una palabra ya ha sido añadida previamente.
      * @param[in] val palabra en cuestión.
      * @return devuelve si estaba(true) o no(false).
      */
    bool exists(const std::string &val) const;

    /**
      * @brief Función para añadir una palabra al diccionario.
      * @param[in] val palabra a añadir.
      * @return devuelve si se ha podido añadir(true), o ya estaba(false).
      * @post El orden se determina por orden alfabético (lexicográfico) por defecto en set.
      */
    bool insert(const std::string &val);

    /**
      * @brief Función para borrar una palabra del diccionario.
      * @param[in] val palabra a borrar.
      * @return si se ha borrado (true) o no (false).
      */
    bool erase(const std::string &val);

    /**
      * @brief Función para vaciar el diccionario.
      */
    void clear();

    /**
      * @brief Función para conocer si el objeto referido Dictionary está vacío (equivalente a que el set esté vacío).
      * @return Si el objeto referido Dictionary está vacío.
      */
    bool empty() const;

    /**
      * @brief Función para conocer el número de palabras del diccionario.
      * @return Número de strings en words (set<string>).
      */
    unsigned int size() const;

    /**
     * @param c char al que contaremos sus apariciones en el diccionario.
     * @brief Función que cuenta y suma las apariciones del char @p c en todas las palabras que contiene el diccionario.
     * @return Entero suma de las apariciones de @p c en todas las palabras en el diccionario.
     */
    int getOccurrences(const char c);

    /**
     * @brief Función que cuenta y suma la longitud de todas las palabras que contiene el diccionario.
     * @return Entero suma de la longitud de todas las palabras en el diccionario.
     */
    int getTotalLetters();

    /**
     * @brief Devuelve en un vector de strings las palabras del diccionario con cierta longitud introducida.
     * @param length longitud de las palabras que se buscan.
     * @return vector con las palabras encontradas de longitud @p length.
     */
    std::vector<std::string> wordsOfLength(int length);

    /**
     * @brief Sobrecarga del operador <<, para imprimir en pantalla las palabras de un diccionario.
     * @param os Objeto ostream usado.
     * @param dic diccionario a imprimir.
     * @return @p os, para concatenar salidas en caso de ser necesario.
     */
    friend std::ostream & operator<<(std::ostream & os, const Dictionary & dic);
    /**
     * @brief Sobrecarga del operador >>, para insertar palabras en un diccionario.
     * @param is Objeto istream usado.
     * @param dic diccionario donde se insertarán las palabras.
     * @return @p is, para concatenar entradas en caso de ser necesario.
     */
    friend std::istream & operator>>(std::istream & is, Dictionary & dic);

    /**
     * @brief Para crear el iterator de dictionary, simplemente definimos cada función gracias al iterator interno del
     * set utilizado.
     */
    class iterator{
    private:
        std::set<std::string>::iterator it;
    public:
        iterator(){}
        iterator(const std::set<std::string>::iterator& otro):it(otro){}
        iterator(const iterator& otro):it(otro.it){}
        ~iterator(){}
        iterator& operator=(const std::set<std::string>::iterator& otro){it=otro;return *this;}
        iterator& operator=(const iterator& otro){it=otro.it;return *this;}
        std::string operator*()const{return *it;}
        iterator& operator++(){++it;return *this;}
        iterator& operator--(){--it;return *this;}
        iterator& operator++(int){it++;return *this;}
        iterator& operator--(int){it--;return *this;}
        bool operator!=(const iterator& otro){return it != otro.it;}
        bool operator==(const iterator& otro){return it == otro.it;}
    };
    iterator begin(){iterator i = words.begin();return i;}
    iterator end(){iterator i = words.end();return i;}

    /**
     * @brief Para crear el const_iterator de dictionary, simplemente definimos cada función gracias al const_iterator
     * interno del set utilizado.
     */
    class const_iterator{
    private:
        std::set<std::string>::const_iterator it;
    public:
        const_iterator(){}
        const_iterator(const std::set<std::string>::const_iterator& otro):it(otro){}
        const_iterator(const const_iterator& otro):it(otro.it){}
        ~const_iterator(){}
        const_iterator& operator=(const std::set<std::string>::const_iterator& otro){it=otro;return *this;}
        const_iterator& operator=(const const_iterator& otro){it=otro.it;return *this;}
        const std::string operator*()const{return *it;}
        const_iterator& operator++(){++it;return *this;}
        const_iterator& operator--(){--it;return *this;}
        const_iterator& operator++(int){it++;return *this;}
        const_iterator& operator--(int){it--;return *this;}
        bool operator!=(const const_iterator& otro){return it != otro.it;}
        bool operator==(const const_iterator& otro){return it == otro.it;}
    };
    const_iterator begin() const{const_iterator i = words.begin();return i;}
    const_iterator end() const{const_iterator i = words.end();return i;}

};

#endif
