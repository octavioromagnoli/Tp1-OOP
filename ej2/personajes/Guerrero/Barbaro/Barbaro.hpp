#ifndef BARBARO_HPP
#define BARBARO_HPP
#include "../Guerrero.hpp"
#include <string>
#include <utility>

class Barbaro : public Guerrero
{
public:
  Barbaro(int mana = 0, int health = 100, int level = 1);

  pair<string, int> powerCall() override;
};

#endif // BARBARO_HPP
