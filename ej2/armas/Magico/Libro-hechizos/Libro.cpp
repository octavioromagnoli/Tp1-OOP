#include <string>
#include <utility>
#include "Libro.hpp"
using namespace std;

Libro::Libro(string name, int damage, Element element, int level, bool broken) : Magico(name, damage, element, level, broken) {}

pair<string, int> Libro::basicMove()
{
  return make_pair("Ataque de Libro", damage);
}

pair<string, int> Libro::elementalMove()
{
  string retString = "Ataque débil de Libro";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Invocar Enjambre";
    retValue = 20;
    break;

  case Element::Darkness:
    retString = "Maleficio Persistente";
    retValue = 30;
    break;

  case Element::Luminic:
    retString = "Palabra Sagrada";
    retValue = 10;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Libro::magicalEffect()
{
  string retString = "Efecto débil de Libro";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Conjuro Herbal";
    retValue = 20;
    break;

  case Element::Darkness:
    retString = "Soledad Profana";
    retValue = 15;
    break;

  case Element::Luminic:
    retString = "Verso Lumínico";
    retValue = 30;
    break;
  }

  return make_pair(retString, retValue);
}