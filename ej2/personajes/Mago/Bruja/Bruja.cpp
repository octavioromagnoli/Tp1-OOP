#include "Bruja.hpp"
#include <string>
#include <utility>
using namespace std;

Bruja::Bruja(int mana, int health, int level) : Mago("Bruja", mana, health, level) {}

pair<string, int> Bruja::castSpell() {
  if(mana < 100){
    return make_pair("Mana insuficiente", 0);
  }
  int retValue = 15 * level++;
  mana -= 100;
  return make_pair("Brujería Ancestral", retValue);
}