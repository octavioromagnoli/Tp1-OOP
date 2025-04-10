#ifndef HACHADOBLE_H
#define HACHADOBLE_H

#include <string>
#include <utility>
#include "../Combate.hpp"
using namespace std;

class Hachadoble : public Combate
{
  Hachadoble(string name, int damage, Spirit spirit = Spirit::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> spiritualMove() override;
  pair<string, int> spiritualEffect() override;
};

#endif // HACHADOBLE_H
