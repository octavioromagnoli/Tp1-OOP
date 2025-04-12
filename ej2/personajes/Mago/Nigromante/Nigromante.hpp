#ifndef NIGROMANTE_HPP
#define NIGROMANTE_HPP
#include "../Mago.hpp"
#include <string>
#include <utility>

class Nigromante : public Mago
{
  Nigromante(int mana = 0, int health = 100, int level = 1);
  
  pair<string, int> castSpell() override;
};

#endif // NIGROMANTE_HPP
