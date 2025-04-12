#ifndef POCION_HPP
#define POCION_HPP

#include <string>
#include <utility>
#include "../Magico.hpp"
using namespace std;

class Pocion : public Magico
{
public:
  Pocion(string name, int damage, Element element = Element::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> elementalMove() override;
  pair<string, int> magicalEffect() override;
};

#endif // POCION_HPP
