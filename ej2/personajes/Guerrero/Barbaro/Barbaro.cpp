#include "Barbaro.hpp"
#include <string>
#include <utility>
using namespace std;

Barbaro::Barbaro(int mana, int health, int level) : Guerrero("Barbaro", mana, health, level) {}

pair<string, int> Barbaro::powerCall() {
  if(energy < 100){
    return make_pair("Energía insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  energy -= 100;
  return make_pair("Furia Salvaje", retValue);
}