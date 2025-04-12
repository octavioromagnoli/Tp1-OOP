#include "Nigromante.hpp"
#include <string>
#include <utility>
using namespace std;

Nigromante::Nigromante(int mana, int health, int level) : Mago("Nigromante", mana, health, level) {}

pair<string, int> Nigromante::castSpell() {
  if(mana < 100){
    return make_pair("Mana insuficiente", 0);
  }
  int retValue = 15 * level;
  health += retValue;
  level++;
  mana -= 100;
  return make_pair("Retorno de los Muertos", retValue);
}