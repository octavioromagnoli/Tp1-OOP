#include "Combate.hpp"
#include <string>
using namespace std;

Combate::Combate(string name, int damage, Spirit spirit, int level, bool broken) : name(name), damage(damage), type(Type::Combat), level(level), broken(broken), spirit(spirit) {}

string Combate::getName() const
{
  return name;
}

int Combate::getDamage() const
{
  return damage;
}

Type Combate::getType() const
{
  return type;
}

int Combate::getLevel() const
{
  return level;
}

bool Combate::setLevel(int newLevel)
{
  if (newLevel < 1)
  {
    return false;
  }
  level = newLevel;
  return true;
}

bool Combate::isBroken() const
{
  return broken;
}

void Combate::setBroken(bool brokenState)
{
  broken = brokenState;
}

Spirit Combate::getSpirit() const
{
  return spirit;
}

void Combate::setSpirit(Spirit newSpirit)
{
  spirit = newSpirit;
}
