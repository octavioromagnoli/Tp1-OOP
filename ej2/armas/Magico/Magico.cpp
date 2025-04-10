#include <string>
using namespace std;
#include "Magico.hpp"


Magico::Magico(string name, int damage, Element element, int level, bool broken) : name(name), damage(damage), type(Type::Magic), level(level), broken(broken), element(element){}

string Magico::getName() const{
  return name;
}

int Magico::getDamage() const{
  return damage;
}

Type Magico::getType() const{
  return type;
}

int Magico::getLevel() const{
  return level;
}

bool Magico::setLevel(int newLevel) {
  if(newLevel < 1){
    return false;
  }
  level = newLevel;
  return true;
}

bool Magico::isBroken() const{
  return broken;
}

void Magico::setBroken(bool brokenState){
  broken = brokenState;
}

Element Magico::getElement() const{
  return element;
}

void Magico::setElement(Element newElement){
  element = newElement;
  return;
}
