#include <string>
#include <utility>
#include "Amuleto.hpp"
using namespace std;

Amuleto::Amuleto(string name, int damage, Element element, int level, bool broken) : Magico(name, damage, element, level, broken) {}

pair<string, int> Amuleto::basicMove()
{
  return make_pair("Ataque de Amuleto", damage);
}

pair<string, int> Amuleto::elementalMove()
{
  string retString = "Ataque débil de Amuleto";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Llamado del Bosque";
    retValue = 10;
    break;

  case Element::Darkness:
    retString = "Marca Maldita";
    retValue = 20;
    break;

  case Element::Luminic:
    retString = "Aura Celestial";
    retValue = 30;
    break;
  }

  return make_pair(retString, retValue);
}

pair<string, int> Amuleto::magicalEffect()
{
  string retString = "Efecto débil de Amuleto";
  int retValue = 5;

  switch (element)
  {
  case Element::None:
    break;

  case Element::Nature:
    retString = "Corazón del Bosque";
    retValue = 30;
    break;

  case Element::Darkness:
    retString = "Contrato Oscuro";
    retValue = 15;
    break;

  case Element::Luminic:
    retString = "Luz del Guardian";
    retValue = 10;
    break;
  }

  return make_pair(retString, retValue);
}