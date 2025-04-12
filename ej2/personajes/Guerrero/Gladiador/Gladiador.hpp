#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP
#include "../Guerrero.hpp"
#include <string>
#include <utility>

class Gladiador : public Guerrero
{
public:
  Gladiador(int mana = 0, int health = 100, int level = 1);

  pair<string, int> powerCall() override;
};

#endif // GLADIADOR_HPP
