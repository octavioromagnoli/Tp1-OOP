#ifndef BASTON_HPP
#define BASTON_HPP

#include <string>
#include <utility>
#include "../Magico.hpp"
using namespace std;

class Baston : public Magico
{
public:
  Baston(string name, int damage, Element element = Element::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> elementalMove() override;
  pair<string, int> magicalEffect() override;
};

#endif // BASTON_HPP
