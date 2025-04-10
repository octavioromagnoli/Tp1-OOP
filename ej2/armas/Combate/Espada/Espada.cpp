#include <string>
#include <utility>
#include "Espada.hpp"
using namespace std;

Espada::Espada(string name, int damage, Spirit spirit, int level, bool broken) : Combate(name, damage, spirit, level, broken) {}

pair<string, int> Espada::basicMove()
{
  return make_pair("Ataque de Espada", 10);
}

pair<string, int> Espada::spiritualMove()
{
  string retString = "Ataque débil de Espada";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Corte Salvaje";
    retValue = 10;
    break;

  case Spirit::Dragon:
    retString = "Corte Dracónico";
    retValue = 30;
    break;

  case Spirit::Shadow:
    retString = "Corte Espectral";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Espada::spiritualEffect()
{
  string retString = "Efecto débil de Espada";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Sangre Ansestral";
    retValue = 15;
    break;

  case Spirit::Dragon:
    retString = "Instinto Ardiente";
    retValue = 15;
    break;

  case Spirit::Shadow:
    retString = "Acechador Sombrío";
    retValue = 30;
    break;
  }

  return make_pair(retString, retValue);
}