
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "solver.h"
#include "letters_bag.h"

int main (int argc, char * argv[]) {
    std::ifstream file_letters, file_dict;
    std::string letters_path, dict_path, game_mode;
    int num_letters = 0;
    LettersSet ls;
    Dictionary dict;

    // Inicializamos el generador de números aleatorios
    srand(time(NULL));

    // Comprobar validez de la llamada
    if (argc != 5){
        std::cerr << "Error: Numero incorrecto de parametros.\n";
        std::cerr << "Uso: partida_letras <FichLetras> <FichDiccionario> <ModoJuego> <CantidadPalabras>\n";
        exit (1);
    }
    // Obtener argumentos
    letters_path  = argv[1];
    dict_path     = argv[2];
    game_mode     = argv[3];
    num_letters   = atoi(argv[4]);

    file_letters.open(letters_path);

    if(file_letters) {
        file_letters >> ls;
    } else {
        std::cout << "Could't open file " << letters_path << std::endl;
        std::cerr << "Could't open file " << letters_path << std::endl;
    }

    file_dict.open(dict_path);

    if(file_dict) {
        file_dict >> dict;
    } else {
        std::cout << "Could't open file " << dict_path << std::endl;
        std::cerr << "Could't open file " << dict_path << std::endl;
    }

    file_letters.close();
    file_dict.close();

    // Crear LettersBag y extraer letras

    LettersBag bag(ls);
    auto vec_letters = bag.extractLetters(num_letters);

    // Generar solución

    Solver sol(dict, ls);
    bool score_game = true;
    if (game_mode == "L")
        score_game = false;
    auto solutions = sol.getSolutions(vec_letters, score_game);

    // Salida

    std::cout << "LETRAS DISPONIBLES:" << std::endl;
    for (auto & it : vec_letters)
        std::cout << it << " ";
    std::cout << std::endl << "SOLUCIONES:" << std::endl;
    for (auto & it : solutions.first)
        std::cout << it << std::endl;
    std::cout << "PUNTUACION:" << std::endl << solutions.second;

    return 0;
}
