#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "../ej2/armas/interfaz/Arma.hpp"
#include "../ej2/personajes/interfaz/Personaje.hpp"

#include <memory>
#include <utility>


class Game
{
private:
    unique_ptr<Personaje> player1;
    unique_ptr<Personaje> player2;

public:
    Game(Character character1, Character character2, Weapon weapon1, Weapon weapon2);
    void start();
    void showMenu();
    int chooseActionMove(int min, int max);
    void showAttackMenu();
    pair<string, int> obtainAttackValues1(int playerSelection);
    pair<string, int> obtainAttackValues2(int playerSelection);
    void solveTurn(int actionPlayer1, int actionPlayer2, int attack1, int attack2);
    bool endGame();
};


#endif // JUEGO_HPP
