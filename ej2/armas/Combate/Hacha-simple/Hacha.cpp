#include <string>
#include <utility>
#include "Hacha.hpp"
using namespace std;

Hacha::Hacha(string name, int damage, Spirit spirit, int level, bool broken) : Combate(name, damage, spirit, level, broken) {}

pair<string, int> Hacha::basicMove()
{
  return make_pair("Ataque de Hacha", damage);
}

pair<string, int> Hacha::spiritualMove()
{
  string retString = "Ataque débil de Hacha";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Carga Salvaje";
    retValue = 10;
    break;

  case Spirit::Dragon:
    retString = "Garra Incandescente";
    retValue = 30;
    break;

  case Spirit::Shadow:
    retString = "Filo Silente";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Hacha::spiritualEffect()
{
  string retString = "Efecto débil de Hacha";
  int retValue = 5;

  switch (spirit)
  {
  case Spirit::None:
    break;

  case Spirit::Beast:
    retString = "Furia Indómita";
    retValue = 30;
    break;

  case Spirit::Dragon:
    retString = "Ira dormida";
    retValue = 10;
    break;

  case Spirit::Shadow:
    retString = "Llama Ubmría";
    retValue = 25;
    break;
  }

  return make_pair(retString, retValue);
}