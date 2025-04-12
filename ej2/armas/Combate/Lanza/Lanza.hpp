#ifndef LANZA_H
#define LANZA_H

#include <string>
#include <utility>
#include "../Combate.hpp"
using namespace std;

class Lanza : public Combate
{
public:
  Lanza(string name, int damage, Spirit spirit = Spirit::None, int level = 1, bool broken = false);

  pair<string, int> basicMove() override;
  pair<string, int> spiritualMove() override;
  pair<string, int> spiritualEffect() override;
};

#endif // LANZA_H
