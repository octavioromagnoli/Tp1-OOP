#include "Caballero.hpp"
#include <string>
#include <utility>
using namespace std;

Caballero::Caballero(int mana, int health, int level) : Guerrero("Caballero", mana, health, level) {}

pair<string, int> Caballero::powerCall() {
  if(energy < 100){
    return make_pair("Energía insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  energy -= 100;
  return make_pair("Guardia de Escudería", retValue);
}