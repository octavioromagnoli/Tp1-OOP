#include "Paladin.hpp"
#include <string>
#include <utility>
using namespace std;

Paladin::Paladin(int mana, int health, int level) : Guerrero("Paladin", mana, health, level) {}

pair<string, int> Paladin::powerCall() {
  if(energy < 100){
    return make_pair("Energía insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  energy -= 100;
  return make_pair("Defensa Divina", retValue);
}