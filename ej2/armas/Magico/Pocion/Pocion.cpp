#include <string>
#include <utility>
#include "Pocion.hpp"
using namespace std;

Pocion::Pocion(string name, int damage, Element element, int level, bool broken) : Magico(name, damage, element, level, broken) {}

pair<string, int> Pocion::basicMove()
{
  return make_pair("Ataque de Poción", 10);
}

pair<string, int> Pocion::elementalMove()
{
  string retString = "Ataque débil de Poción";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Explosión de Esporas";
    retValue = 30;
    break;

  case Element::Darkness:
    retString = "Niebla Negra";
    retValue = 10;
    break;

  case Element::Luminic:
    retString = "Bruma Luminosa";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Pocion::magicalEffect()
{
  string retString = "Efecto débil de Pocion";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Enverdecer";
    retValue = 10;
    break;

  case Element::Darkness:
    retString = "Escudo Sombrío";
    retValue = 30;
    break;

  case Element::Luminic:
    retString = "Luz Líquida";
    retValue = 20;
    break;
  }

  return make_pair(retString, retValue);
}