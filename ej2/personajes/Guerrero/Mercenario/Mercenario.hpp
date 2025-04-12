#ifndef MERCENARIO_HPP
#define MERCENARIO_HPP
#include "../Guerrero.hpp"
#include <string>
#include <utility>

class Mercenario : public Guerrero
{
public:
  Mercenario(int mana = 0, int health = 100, int level = 1);

  pair<string, int> powerCall() override;
};

#endif // MERCENARIO_HPP
