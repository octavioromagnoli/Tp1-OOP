#include <string>
#include <utility>
#include "Lanza.hpp"
using namespace std;

Lanza::Lanza(string name, int damage, Spirit spirit, int level, bool broken) : Combate(name, damage, spirit, level, broken) {}

pair<string, int> Lanza::basicMove()
{
  return make_pair("Ataque de Lanza", damage);
}

pair<string, int> Lanza::spiritualMove()
{
  string retString = "Ataque débil de Lanza";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Zarpazo Perforador";
    retValue = 30;
    break;

  case Spirit::Dragon:
    retString = "Pinche Celestial";
    retValue = 10;
    break;

  case Spirit::Shadow:
    retString = "Emboscada Silenciosa";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Lanza::spiritualEffect()
{
  string retString = "Efecto débil de Lanza";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Marca Venenosa";
    retValue = 15;
    break;

  case Spirit::Dragon:
    retString = "Escamas Eternas";
    retValue = 30;
    break;

  case Spirit::Shadow:
    retString = "Silencio Mortal";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}