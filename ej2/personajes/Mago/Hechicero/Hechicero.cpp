#include "Hechicero.hpp"
#include <string>
#include <utility>
using namespace std;

Hechicero::Hechicero(int mana, int health, int level) : Mago("Hechicero", mana, health, level) {}

pair<string, int> Hechicero::castSpell() {
  if(mana < 100){
    return make_pair("Mana insuficiente", 0);
  }
  int retValue = 15 * level++;
  mana -= 100;
  return make_pair("Explosión Arcana", retValue);
}