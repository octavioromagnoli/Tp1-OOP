#include "Guerrero.hpp"
#include <utility>
#include <iterator>
#include <memory>
#include <list>
using namespace std;



Guerrero::Guerrero(string name, int energy, int health, int level) : name(name), health(health), level(level), clan(Clan::Warrior), energy(energy), isdead(false)
{
  if (health <= 0)
  {
    isdead = true;
  }
}

Guerrero::~Guerrero () {}

string Guerrero::getName() const
{
  return name;
}

int Guerrero::getHealth() const
{
  return health;
}

bool Guerrero::setHealth(int newHealth)
{
  if (newHealth <= 0)
  {
    return false;
  }
  health = newHealth;
  return true;
}

void Guerrero::changeHealth(int newAddition)
{
  if ((health + newAddition) <= 0)
  {
    isdead = true;
    health = 0;
    return;
  }
  health += newAddition;
}

Clan Guerrero::getClan() const
{
  return clan;
}

int Guerrero::getLevel() const
{
  return level;
}

bool Guerrero::setLevel(int newLevel)
{
  if (newLevel < 0)
  {
    return false;
  }
  level = newLevel;
  return true;
}

bool Guerrero::isDead() const
{
  return isdead;
}

int Guerrero::getEnergy() const
{
  return energy;
}

void Guerrero::setEnergy(int newEnergy)
{
  if (newEnergy <= 0)
  {
    energy = 0;
  }

  energy = newEnergy;
}

bool Guerrero::equipWeapon(unique_ptr<Arma> armaNueva)
{
  if (!armaNueva || weapons.size() >= 2)
  {
    return false;
  }
  weapons.push_back(move(armaNueva));
  return true;
}

void Guerrero::discardWeapon(int index)
{
  if (index < 1 || index > static_cast<int>(weapons.size()))
  {
    return;
  }
  auto it = weapons.begin();
  advance(it, index - 1);
  weapons.erase(it);
}

Arma* Guerrero::getWeapon(int index) {
  if (index < 1 || index > static_cast<int>(weapons.size()))
  {
    return nullptr;
  }
  auto it = weapons.begin();
  advance(it, index - 1);
  return it->get();
}  

