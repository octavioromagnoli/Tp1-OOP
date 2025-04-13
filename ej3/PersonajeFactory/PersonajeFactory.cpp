#include "PersonajeFactory.hpp"
#include "../../ej2/armas/interfaz/Arma.hpp"
#include "../../ej2/armas/Combate/Espada/Espada.hpp"
#include "../../ej2/armas/Combate/Garrote/Garrote.hpp"
#include "../../ej2/armas/Combate/Hacha-doble/Hachadoble.hpp"
#include "../../ej2/armas/Combate/Hacha-simple/Hacha.hpp"
#include "../../ej2/armas/Combate/Lanza/Lanza.hpp"
#include "../../ej2/armas/Magico/Amuleto/Amuleto.hpp"
#include "../../ej2/armas/Magico/Baston/Baston.hpp"
#include "../../ej2/armas/Magico/Libro-hechizos/Libro.hpp"
#include "../../ej2/armas/Magico/Pocion/Pocion.hpp"

#include "../../ej2/personajes/interfaz/Personaje.hpp"
#include "../../ej2/personajes/Guerrero/Mercenario/Mercenario.hpp"
#include "../../ej2/personajes/Guerrero/Barbaro/Barbaro.hpp"
#include "../../ej2/personajes/Guerrero/Caballero/Caballero.hpp"
#include "../../ej2/personajes/Guerrero/Gladiador/Gladiador.hpp"
#include "../../ej2/personajes/Guerrero/Paladin/Paladin.hpp"
#include "../../ej2/personajes/Mago/Bruja/Bruja.hpp"
#include "../../ej2/personajes/Mago/Conjurador/Conjurador.hpp"
#include "../../ej2/personajes/Mago/Hechicero/Hechicero.hpp"
#include "../../ej2/personajes/Mago/Nigromante/Nigromante.hpp"

#include <memory>
#include <stdexcept>
using namespace std;

unique_ptr<Personaje> PersonajeFactory::crearPersonaje(Character character)
{
  switch (character)
  {
  case Character::Barbaro:
    return make_unique<Barbaro>();
  case Character::Caballero:
    return make_unique<Caballero>();
  case Character::Gladiador:
    return make_unique<Gladiador>();
  case Character::Mercenario:
    return make_unique<Mercenario>();
  case Character::Paladin:
    return make_unique<Paladin>();
  case Character::Bruja:
    return make_unique<Bruja>();
  case Character::Conjurador:
    return make_unique<Conjurador>();
  case Character::Hechicero:
    return make_unique<Hechicero>();
  case Character::Nigromante:
    return make_unique<Nigromante>();
  default:
    return nullptr;
  }
}

unique_ptr<Arma> PersonajeFactory::crearArma(Weapon weapon)
{
  switch (weapon)
  {
  case Weapon::Espada:
    return make_unique<Espada>("Espada", 10);
  case Weapon::Garrote:
    return make_unique<Garrote>("Garrote", 10);
  case Weapon::Hachadoble:
    return make_unique<Hachadoble>("Hacha Doble", 10);
  case Weapon::Hachasimple:
    return make_unique<Hacha>("Hacha", 10);
  case Weapon::Lanza:
    return make_unique<Lanza>("Lanza", 10);
  case Weapon::Amuleto:
    return make_unique<Amuleto>("Amuleto", 10);
  case Weapon::Baston:
    return make_unique<Baston>("Bastón", 10);
  case Weapon::Libro:
    return make_unique<Libro>("Libro", 10);
  case Weapon::Pocion:
    return make_unique<Pocion>("Poción", 10);
  default:
    return nullptr;
  }
}

unique_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(Character character, Weapon weapon)
{
  
  auto retPersonaje = PersonajeFactory::crearPersonaje(character);
  if (!retPersonaje)
  {
    throw runtime_error("Error al crear Personaje");
  }

  auto arma = PersonajeFactory::crearArma(weapon);
  if (!arma)
  {
    throw runtime_error("Error al crear Arma");
  }

  retPersonaje->equipWeapon(move(arma));
  return retPersonaje;
}