#ifndef HACHA_H
#define HACHA_H

#include <string>
#include <utility>
#include "../Combate.hpp"
using namespace std;

class Hacha : public Combate
{
  Hacha(string name, int damage, Spirit spirit = Spirit::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> spiritualMove() override;
  pair<string, int> spiritualEffect() override;
};

#endif // HACHA_H
