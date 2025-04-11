#include "Mago.hpp"
#include <utility>
#include <iterator>
#include <memory>
#include <list>
using namespace std;



Mago::Mago(string name, int mana, int health, int level) : name(name), health(health), level(level), clan(Clan::Mage), mana(mana), isdead(false)
{
  if (health <= 0)
  {
    isdead = true;
  }
}

Mago::~Mago () {}

string Mago::getName() const
{
  return name;
}

int Mago::getHealth() const
{
  return health;
}

bool Mago::setHealth(int newHealth)
{
  if (newHealth <= 0)
  {
    return false;
  }
  health = newHealth;
  return true;
}

void Mago::changeHealth(int newAddition)
{
  if ((health + newAddition) <= 0)
  {
    isdead = true;
    health = 0;
    return;
  }
  health += newAddition;
}

Clan Mago::getClan() const
{
  return clan;
}

int Mago::getLevel() const
{
  return level;
}

bool Mago::setLevel(int newLevel)
{
  if (newLevel < 0)
  {
    return false;
  }
  level = newLevel;
  return true;
}

bool Mago::isDead() const
{
  return isdead;
}

int Mago::getMana() const
{
  return mana;
}

void Mago::setMana(int newMana)
{
  if (newMana <= 0)
  {
    mana = 0;
  }

  mana = newMana;
}

bool Mago::equipWeapon(unique_ptr<Arma> armaNueva)
{
  if (!armaNueva || weapons.size() >= 2)
  {
    return false;
  }
  weapons.push_back(move(armaNueva));
  return true;
}

void Mago::discardWeapon(int index)
{
  if (index > static_cast<int>(weapons.size()))
  {
    return;
  }
  auto it = weapons.begin();
  advance(it, index - 1);
  weapons.erase(it);
}

