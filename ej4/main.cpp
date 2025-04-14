#include <iostream>

#include "../ej2/armas/Combate/Combate.hpp"
#include "../ej2/armas/Magico/Magico.hpp"

#include "../ej2/armas/interfaz/Arma.hpp"

#include "../ej2/personajes/interfaz/Personaje.hpp"
#include "../ej2/personajes/Mago/Mago.hpp"
#include "../ej2/personajes/Guerrero/Guerrero.hpp"

#include "Game.hpp"
#include "../ej3/PersonajeFactory/PersonajeFactory.hpp"

int main()
{
  cout << "---------- Elija su personaje para el jugador 1: ----------" << endl;
  cout << "(0) Barbaro, (1) Caballero, (2) Gladiador, (3) Mercenario, (4) Paladin, "
          "(5) Bruja, (6) Conjurador, (7) Hechicero, (8) Nigromante"
       << endl;
  Character player1 = static_cast<Character>(Game::chooseActionMove(0, 8));

  cout << "---------- Elija su arma para el jugador 1: ----------" << endl;
  cout << "(0) Espada, (1) Garrote, (2) Hachadoble, (3) Hachasimple, (4) Lanza, "
          "(5) Amuleto, (6) Baston, (7) Libro, (8) Pocion"
       << endl;
  Weapon weapon1 = static_cast<Weapon>(Game::chooseActionMove(0, 8));

  int character2 = static_cast<int>(rand() % 9);
  int gun2 = static_cast<int>(rand() % 9);
  Character player2 = static_cast<Character>(character2);
  Weapon weapon2 = static_cast<Weapon>(gun2);

  cout << string(95, '=') << endl
       << "REGLAS IMPORTANTES" << endl
       << "1. La primera selección de ataque decide quién ataca (estilo piedra, papel o tijera)." << endl
       << "2. En la segunda elección se decide qué se quiere hacer con el turno en caso de ganar." << endl
       << "3. Los ataques de arma que no sean básicos son poco efectivos si el arma no está encantada." << endl
       << "4. La habilidad de personaje no hace nada si no tiene suficiente Mana o Energía (necesita 100)." << endl
       << "5. La habilidad de personaje lo cura una cantidad dependiente de su nivel. ¡Usarla hace que suba de nivel!" << endl
       << string(95, '=') << endl;

  Game game(player1, player2, weapon1, weapon2);

  game.start();
  return 0;
}