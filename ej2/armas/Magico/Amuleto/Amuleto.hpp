#ifndef AMULETO_HPP
#define AMULETO_HPP

#include <string>
#include <utility>
#include "../Magico.hpp"
using namespace std;

class Amuleto : public Magico
{
public:
  Amuleto(string name, int damage, Element element = Element::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> elementalMove() override;
  pair<string, int> magicalEffect() override;
};

#endif // AMULETO_HPP
