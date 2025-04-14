#include <iostream>

#include "../ej2/armas/Combate/Combate.hpp"
#include "../ej2/armas/Magico/Magico.hpp"

#include "../ej2/armas/interfaz/Arma.hpp"

#include "../ej2/personajes/interfaz/Personaje.hpp"
#include "../ej2/personajes/Mago/Mago.hpp"
#include "../ej2/personajes/Guerrero/Guerrero.hpp"

#include "Game.hpp"
#include "../ej3/PersonajeFactory/PersonajeFactory.hpp"

// TODO arreglar Game.cpp (punteros) y poner interfaz para seleccionar a los personajes y sus armas

int main() {
  Game game(Character::Paladin, Character::Nigromante, Weapon::Garrote, Weapon::Amuleto);

  
  game.start();
  return 0;
}