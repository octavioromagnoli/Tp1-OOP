#include "Mercenario.hpp"
#include <string>
#include <utility>
using namespace std;

Mercenario::Mercenario(int energy, int health, int level) : Guerrero("Mercenario", energy, health, level) {}

pair<string, int> Mercenario::powerCall() {
  if(energy < 100){
    return make_pair("Energía insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  energy -= 100;
  return make_pair("Bono de Guerra", retValue);
}