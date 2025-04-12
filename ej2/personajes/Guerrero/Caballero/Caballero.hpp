#ifndef CABALLERO_HPP
#define CABALLERO_HPP
#include "../Guerrero.hpp"
#include <string>
#include <utility>

class Caballero : public Guerrero
{
  Caballero(int mana = 0, int health = 100, int level = 1);
  
  pair<string, int> powerCall() override;
};

#endif // CABALLERO_HPP
