/**
 * @file letters_bag.h
 * @brief  Archivo de especificación del TDA LettersBag.
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 * @date Noviembre-Diciembre de 2021.
 * @details Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"
#include <vector>

class LettersBag{
private:

    /**
      * @brief Bolsa de letras usando TDA Bag con clase Ttmplate T = char.
      */
    Bag <char> letters;

    /**
      * @brief Función auxiliar para el constructor de copia.
      * @param[in] lettersSet mapa con información de cada carácter. Véase en letters_set.h .
      */
    void copy(const LettersSet & lettersSet);
public:

    /**
      * @brief Constructor por defecto.
      * @return el objeto LettersBag creado.
      * @post Genera una instancia de la clase LettersBag con Bag <char> vacío.
      */
    LettersBag();

    /**
      * @brief Constructor mediante mapa con información de cada carácter.
      * @param letterSet mapa con información de cada carácter. Véase en letters_set.h .
      * @return el objeto LettersBag creado a partir de @p letterSet.
      * @post Genera una instancia de la clase LettersBag con Bag <char> construido gracias a la información de
      * @p letterSet.
      */
    LettersBag(const LettersSet & letterSet);

    /**
      * @brief Función para añadir un elemento a la bolsa interna.
      * @param[in] l char a añadir.
      * @return void.
      * @post Se añade al final del vector elements interno de letters (Bag <char> interno).
      */
    void insertLetter(const char & l);

    /**
      * @brief Función para obtener un char aleatorio de la bolsa de letras.
      * @return char aleatorio.
      * @post Se saca el char de la bolsa a su vez.
      */
    char extractLetter();

    /**
      * @param num número de veces que se llama a extractLetter internamente.
      * @brief Función para obtener n chars aleatorios de la bolsa de letras.
      * @return vector con n chars aleatorios.
      * @post Se sacan los n chars de la bolsa a su vez.
      */
    std::vector<char> extractLetters(int num);

    /**
      * @brief Función para limpiar la bolsa, vaciarla.
      */
    void clear();

    /**
      * @brief Función para conocer el número de chars de la bolsa de letras.
      * @return Número de elementos del objeto referido LettersBag.
      * @post El objeto referido LettersBag no se modifica.
      */
    unsigned int size();

    /**
     * @brief Operador asignación de bolsas de letras.
     * @param other bolsa de letras para asignar.
     * @return objeto asignado, para concatenar asignaciones.
     */
    LettersBag & operator=(const LettersBag & other);
};

#endif
