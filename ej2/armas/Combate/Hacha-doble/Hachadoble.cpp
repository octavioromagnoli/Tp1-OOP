#include <string>
#include <utility>
#include "Hachadoble.hpp"
using namespace std;

Hachadoble::Hachadoble(string name, int damage, Spirit spirit, int level, bool broken) : Combate(name, damage, spirit, level, broken) {}

pair<string, int> Hachadoble::basicMove()
{
  return make_pair("Ataque de Hacha Doble", damage);
}

pair<string, int> Hachadoble::spiritualMove()
{
  string retString = "Ataque débil de Hacha Doble";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Desgarrar";
    retValue = 10;
    break;

  case Spirit::Dragon:
    retString = "Aliento Colosal";
    retValue = 30;
    break;

  case Spirit::Shadow:
    retString = "Reflejo Fugaz";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Hachadoble::spiritualEffect()
{
  string retString = "Efecto débil de Hachadoble";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Rugido de Guerra";
    retValue = 20;
    break;

  case Spirit::Dragon:
    retString = "Dominio Dracónico";
    retValue = 15;
    break;

  case Spirit::Shadow:
    retString = "Danza de Sombras";
    retValue = 30;
    break;
  }

  return make_pair(retString, retValue);
}