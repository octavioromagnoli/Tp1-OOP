#include "armas/interfaz/Arma.hpp"
#include "armas/Combate/Espada/Espada.hpp"
#include "armas/Combate/Garrote/Garrote.hpp"
#include "armas/Combate/Hacha-doble/Hachadoble.hpp"
#include "armas/Combate/Hacha-simple/Hacha.hpp"
#include "armas/Combate/Lanza/Lanza.hpp"
#include "armas/Magico/Amuleto/Amuleto.hpp"
#include "armas/Magico/Baston/Baston.hpp"
#include "armas/Magico/Libro-hechizos/Libro.hpp"
#include "armas/Magico/Pocion/Pocion.hpp"

#include "personajes/interfaz/Personaje.hpp"
#include "personajes/Guerrero/Mercenario/Mercenario.hpp"
#include "personajes/Guerrero/Barbaro/Barbaro.hpp"
#include "personajes/Guerrero/Caballero/Caballero.hpp"
#include "personajes/Guerrero/Gladiador/Gladiador.hpp"
#include "personajes/Guerrero/Paladin/Paladin.hpp"
#include "personajes/Mago/Bruja/Bruja.hpp"
#include "personajes/Mago/Conjurador/Conjurador.hpp"
#include "personajes/Mago/Hechicero/Hechicero.hpp"
#include "personajes/Mago/Nigromante/Nigromante.hpp"

#include <iostream>
#include <memory>
#include <string>
using namespace std;

string armTypeString(Type type);
string spiritString(Spirit spirit);
string elementString(Element element);
string clanString(Clan clan);
void printNice(const string &title);

int main()
{
  auto libro = make_unique<Libro>("Libro de Luz", 10, Element::Luminic);
  auto bruja = make_unique<Bruja>(100);

  auto espada = make_unique<Espada>("Espada Dragón", 12, Spirit::Dragon);
  auto paladin = make_unique<Paladin>(100);
  paladin->equipWeapon(move(espada));

  printNice("Metodos de personaje");
  cout << "Nombre: " << bruja->getName() << endl;
  cout << "Salud: " << bruja->getHealth() << endl;
  bruja->setHealth(80);
  cout << "Clan: " << clanString(bruja->getClan()) << endl;
  cout << "Salud después de setHealth(80): " << bruja->getHealth() << endl;
  bruja->changeHealth(-20);
  cout << "Salud después de changeHealth(-20): " << bruja->getHealth() << endl;
  cout << "Nivel: " << bruja->getLevel() << endl;
  bruja->setLevel(5);
  cout << "Nivel después de setLevel(5): " << bruja->getLevel() << endl;
  cout << "¿Está muerta?: " << (bruja->isDead() ? "Sí" : "No") << endl;

  cout << "Equipar arma: " << (bruja->equipWeapon(move(libro)) ? "Éxito" : "Fallo") << endl;
  bruja->discardWeapon(1);
  cout << "Arma descartada." << endl;

  cout << "Maná: " << bruja->getMana() << endl;
  bruja->setMana(110);
  cout << "Maná después de setMana(110): " << bruja->getMana() << endl;

  printNice("Habilidades especiales personaje clan Mago");
  cout << "Maná antes de lanzar hechizo: " << bruja->getMana() << endl;
  cout << "Salud antes de lanzar hechizo: " << bruja->getHealth() << endl;

  auto [spellName, healedAmount] = bruja->castSpell();
  cout << "La bruja utilizó " << spellName << ", curó: " << healedAmount << " puntos de salud." << endl;

  cout << "Maná después de lanzar hechizo: " << bruja->getMana() << endl;
  cout << "Salud después de lanzar hechizo: " << bruja->getHealth() << endl;

  printNice("Habilidades especiales personaje Clan Guerrero");
  cout << "Energía antes de llamada de poder: " << paladin->getEnergy() << endl;
  cout << "Salud antes de llamada de poder: " << paladin->getHealth() << endl;

  auto [powerName, boostedAmount] = paladin->powerCall();
  cout << "El paladín utilizó " << powerName << ", aumentó: " << boostedAmount << " puntos de salud." << endl;

  cout << "Energía después de llamada de poder: " << paladin->getEnergy() << endl;
  cout << "Salud después de llamada de poder: " << paladin->getHealth() << endl;

  printNice("Métodos de arma");

  auto weaponPaladin = paladin->getWeapon(1);
  if (weaponPaladin)
  {
    cout << "Nombre: " << weaponPaladin->getName() << endl;
    cout << "Daño: " << weaponPaladin->getDamage() << endl;
    cout << "Tipo: " << armTypeString(weaponPaladin->getType()) << endl;
    cout << "Nivel: " << weaponPaladin->getLevel() << endl;

    cout << "Establecer nivel a 5: " << (weaponPaladin->setLevel(5) ? "Éxito" : "Fallo") << endl;
    cout << "Nivel después de setLevel(5): " << weaponPaladin->getLevel() << endl;

    cout << "¿Está rota?: " << (weaponPaladin->isBroken() ? "Sí" : "No") << endl;
    weaponPaladin->setBroken(true);
    cout << "¿Está rota después de setBroken(true)?: " << (weaponPaladin->isBroken() ? "Sí" : "No") << endl;
  }
  else
  {
    cout << "El Paladín no tiene un arma equipada en la posición 1." << endl;
  }

  printNice("Ataques especiales Arma tipo Mágica");

  auto newLibro = make_unique<Libro>("Libro Oscuro", 15, Element::Darkness);
  bruja->equipWeapon(move(newLibro));
  auto weaponBruja = bruja->getWeapon(1);
  if (weaponBruja)
  {
    cout << "Arma de la Bruja: " << weaponBruja->getName() << endl;
    cout << "Tipo de arma de la Bruja: " << armTypeString(weaponBruja->getType()) << endl;

    if (auto libro = dynamic_cast<Libro *>(weaponBruja))
    {
      cout << "Elemento del arma de la Bruja: " << elementString(libro->getElement()) << endl;
      auto [basicAttack, basicDamage] = libro->basicMove();
      cout << "Ataque básico: " << basicAttack << ", Daño: " << basicDamage << endl;

      auto [elementalAttack, elementalDamage] = libro->elementalMove();
      cout << "Ataque elemental: " << elementalAttack << ", Daño: " << elementalDamage << endl;

      auto [magicEffect, magicDamage] = libro->magicalEffect();
      cout << "Efecto mágico: " << magicEffect << ", Daño: " << magicDamage << endl;
    }
  }
  else
  {
    cout << "El arma de la Bruja no es un Libro." << endl;
  }

  printNice("Ataques especiales Arma tipo Combate");

  if (weaponPaladin)
  {

    if (auto espada = dynamic_cast<Espada *>(weaponPaladin))
    {
      cout << "Nombre del arma del Paladín: " << espada->getName() << endl;
      cout << "Tipo de arma del Paladín: " << armTypeString(espada->getType()) << endl;
      cout << "Espíritu del arma del Paladín: " << spiritString(espada->getSpirit()) << endl;
      auto [basicAttack, basicDamage] = espada->basicMove();
      cout << "Ataque básico: " << basicAttack << ", Daño: " << basicDamage << endl;

      auto [elementalAttack, elementalDamage] = espada->spiritualMove();
      cout << "Ataque elemental: " << elementalAttack << ", Daño: " << elementalDamage << endl;

      auto [magicEffect, magicDamage] = espada->spiritualEffect();
      cout << "Efecto mágico: " << magicEffect << ", Daño: " << magicDamage << endl;
    }
    else
    {
      cout << "El arma del Paladín no es una Espada." << endl;
    }
  }
  else
  {
    cout << "El Paladín no tiene un arma equipada en la posición 1." << endl;
  }

  return 0;
}

string spiritString(Spirit spirit)
{
  switch (spirit)
  {
  case Spirit::None:
    return "None";
  case Spirit::Beast:
    return "Beast";
  case Spirit::Dragon:
    return "Dragon";
  case Spirit::Shadow:
    return "Shadow";
  default:
    return "Unknown";
  }
}

string elementString(Element element)
{
  switch (element)
  {
  case Element::None:
    return "None";
  case Element::Nature:
    return "Nature";
  case Element::Darkness:
    return "Darkness";
  case Element::Luminic:
    return "Luminic";
  default:
    return "Unknown";
  }
}

string clanString(Clan clan)
{
  switch (clan)
  {
  case Clan::Mage:
    return "Mage";
  case Clan::Warrior:
    return "Warrior";
  default:
    return "Unknown";
  }
}

string armTypeString(Type type)
{
  switch (type)
  {
  case Type::Magic:
    return "Magic";
  case Type::Combat:
    return "Combat";
  default:
    return "Unknown";
  }
}

void printNice(const string &title)
{
  cout << string(70, '=') << endl;
  cout << "   " << title << endl;
  cout << string(70, '=') << endl;
}
