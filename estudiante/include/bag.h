/**
 * @file bag.h
 * @brief  Archivo de especificación del TDA Bag
 * @author Rodríguez Cao, Eduardo.
 * @author Ruiz Aguilar, Manuel.
 * @date Noviembre-Diciembre de 2021.
 * @details Este TDA abstracto nos permite trabajar con una colección de elementos que
 * permite la extracción de elementos de forma aleatoria sin reemplazamiento.
 */

#ifndef __BAG_H__
#define __BAG_H__
#include <iostream>
#include <vector>
#include <cstdlib>

template <class T>
class Bag {
private:

    /**
      * @brief Vector de elementos de la clase T.
      * @a la clase T es una clase Template, por eso en este mismo archivo se describen los métodos.
      */

    std::vector<T> elements;
public:

    /**
      * @brief Constructor por defecto.
      * @return bolsa, el objeto Bag creado.
      * @post Genera una instancia de la clase Bag <T> con vector<T> vacío.
      */
    Bag();

    /**
      * @brief Constructor por copia.
      * @return Bag, el objeto Bag creado.
      * @post Genera una instancia de la clase Bag igual a la introducida.
      */
    Bag(const Bag<T> & other);

    /**
      * @brief Función para añadir un elemento a la bolsa.
      * @param[in] element de la clase T.
      * @return void.
      * @post Se añade al final del vector elements.
      */
    void add(const T & element);

    /**
      * @brief Función para obtener un elemento aleatorio de la bolsa.
      * @pre empty() == false.
      * @return elemento aleatorio de la clase T.
      * @post Se saca el elemento de la bolsa a su vez.
      */
    T get();

    /**
      * @brief Función para limpiar la bolsa, vaciarla.
      * @pre empty() == false.
      */
    void clear();

    /**
      * @brief Función para conocer el número de elementos del objeto referido Bag (eq. al tamaño del vector).
      * @return Número de elementos del objeto referido Bag.
      * @post El objeto referido Bag no se modifica.
      */
    unsigned int size() const;

    /**
      * @brief Función para conocer si el objeto referido Bag está vacío (equivalente a que el vector esté vacío).
      * @return Si el objeto referido Bag está
      * vacío.
      * @post El objeto referido Bag no se modifica.
      */
    bool empty();

    /**
     * @brief Operador asignación de bolsas.
     * @param other bolsa para asignar.
     * @return objeto asignado, para concatenar asignaciones.
     */
    Bag<T> & operator=(const Bag<T> & other);
};

template <class T>
Bag<T>::Bag() = default;

template <class T>
Bag<T>::Bag(const Bag<T> & other) {
    *this = other;
}

template <class T>
void Bag<T>::add(const T & element){
    elements.push_back(element);
}

template <class T>
T Bag<T>::get(){
    int index = rand()%size();
    T ret = elements[index];
    std::swap(elements[index], elements[size()-1]);
    elements.pop_back();
    return ret;
}

template <class T>
void Bag<T>::clear(){
    elements.clear();
}

template <class T>
unsigned int Bag<T>::size() const {
    return elements.size();
}

template <class T>
bool Bag<T>::empty() {
    return elements.empty();
}

template <class T>
Bag<T> & Bag<T>::operator=(const Bag<T> & other) = default;

#endif