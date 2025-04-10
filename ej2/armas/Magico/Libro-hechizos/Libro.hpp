#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>
#include <utility>
#include "../Magico.hpp"
using namespace std;

class Libro : public Magico
{
  Libro(string name, int damage, Element element = Element::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> elementalMove() override;
  pair<string, int> magicalEffect() override;
};

#endif // LIBRO_HPP
