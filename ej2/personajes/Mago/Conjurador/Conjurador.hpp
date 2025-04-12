#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP
#include "../Mago.hpp"
#include <string>
#include <utility>

class Conjurador : public Mago
{
  Conjurador(int mana = 0, int health = 100, int level = 1);
  
  pair<string, int> castSpell() override;
};

#endif // CONJURADOR_HPP
