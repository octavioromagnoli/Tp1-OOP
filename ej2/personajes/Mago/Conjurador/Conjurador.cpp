#include "Conjurador.hpp"
#include <string>
#include <utility>
using namespace std;

Conjurador::Conjurador(int mana, int health, int level) : Mago("Conjurador", mana, health, level) {}

pair<string, int> Conjurador::castSpell() {
  if(mana < 100){
    return make_pair("Mana insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  mana -= 100;
  return make_pair("Invocación elemental", retValue);
}