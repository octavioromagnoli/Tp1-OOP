#ifndef GARROTE_H
#define GARROTE_H

#include <string>
#include <utility>
#include "../Combate.hpp"
using namespace std;

class Garrote : public Combate
{
  Garrote(string name, int damage, Spirit spirit = Spirit::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> spiritualMove() override;
  pair<string, int> spiritualEffect() override;
};

#endif // GARROTE_H
