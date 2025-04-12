#include <string>
#include <utility>
#include "Garrote.hpp"
using namespace std;

Garrote::Garrote(string name, int damage, Spirit spirit, int level, bool broken) : Combate(name, damage, spirit, level, broken) {}

pair<string, int> Garrote::basicMove()
{
  return make_pair("Ataque de Garrote", damage);
}

pair<string, int> Garrote::spiritualMove()
{
  string retString = "Ataque débil de Garrote";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Quebrantahuesos";
    retValue = 30;
    break;

  case Spirit::Dragon:
    retString = "Impacto Sísmico";
    retValue = 20;
    break;

  case Spirit::Shadow:
    retString = "Golpe Oscuro";
    retValue = 10;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Garrote::spiritualEffect()
{
  string retString = "Efecto débil de Garrote";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Golpe de Hierro";
    retValue = 10;
    break;

  case Spirit::Dragon:
    retString = "Estrendor Titánico";
    retValue = 25;
    break;

  case Spirit::Shadow:
    retString = "Choque de Sombras";
    retValue = 30;
    break;
  }

  return make_pair(retString, retValue);
}