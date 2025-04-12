#ifndef BRUJA_HPP
#define BRUJA_HPP
#include "../Mago.hpp"
#include <string>
#include <utility>

class Bruja : public Mago
{
public:
  Bruja(int mana = 0, int health = 100, int level = 1);

  pair<string, int> castSpell() override;
};

#endif // BRUJA_HPP
