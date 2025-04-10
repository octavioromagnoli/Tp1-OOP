#include <string>
#include <utility>
#include "Baston.hpp"
using namespace std;

Baston::Baston(string name, int damage, Element element, int level, bool broken) : Magico(name, damage, element, level, broken) {}

pair<string, int> Baston::basicMove()
{
  return make_pair("Ataque de bastón", 10);
}

pair<string, int> Baston::elementalMove()
{
  string retString = "Ataque débil de Baston";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Tormenta de Raíces";
    retValue = 30;
    break;

  case Element::Darkness:
    retString = "Explosión de Sombras";
    retValue = 20;
    break;

  case Element::Luminic:
    retString = "Rayo de Luz";
    retValue = 10;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Baston::magicalEffect()
{
  string retString = "Efecto débil de Baston";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Eco Terrenal";
    retValue = 15;
    break;

  case Element::Darkness:
    retString = "Sangre Arcana";
    retValue = 15;
    break;

  case Element::Luminic:
    retString = "Manto de Luz";
    retValue = 30;
    break;
  }

  return make_pair(retString, retValue);
}