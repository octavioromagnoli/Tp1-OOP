#ifndef HECHICERO_HPP
#define HECHICERO_HPP
#include "../Mago.hpp"
#include <string>
#include <utility>

class Hechicero : public Mago
{
  Hechicero(int mana = 0, int health = 100, int level = 1);
  
  pair<string, int> castSpell() override;
};

#endif // HECHICERO_HPP
