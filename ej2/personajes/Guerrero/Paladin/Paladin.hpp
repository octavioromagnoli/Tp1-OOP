#ifndef PALADIN_HPP
#define PALADIN_HPP
#include "../Guerrero.hpp"
#include <string>
#include <utility>

class Paladin : public Guerrero
{
  Paladin(int mana = 0, int health = 100, int level = 1);
  
  pair<string, int> powerCall() override;
};

#endif // PALADIN_HPP
