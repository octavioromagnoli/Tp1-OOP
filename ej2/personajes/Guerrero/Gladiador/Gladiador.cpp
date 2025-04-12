#include "Gladiador.hpp"
#include <string>
#include <utility>
using namespace std;

Gladiador::Gladiador(int energy, int health, int level) : Guerrero("Gladiador", energy, health, level) {}

pair<string, int> Gladiador::powerCall() {
  if(energy < 100){
    return make_pair("Energía insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  energy -= 100;
  return make_pair("Llamado de las Arenas", retValue);
}