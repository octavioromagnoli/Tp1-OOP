#ifndef ESPADA_H
#define ESPADA_H

#include <string>
#include <utility>
#include "../Combate.hpp"
using namespace std;

class Espada : public Combate
{
  Espada(string name, int damage, Spirit spirit = Spirit::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> spiritualMove() override;
  pair<string, int> spiritualEffect() override;
};

#endif // ESPADA_H
