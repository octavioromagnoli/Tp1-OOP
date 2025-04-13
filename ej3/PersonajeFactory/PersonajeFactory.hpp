#ifndef PERSONAJE_FACTORY_HPP
#define PERSONAJE_FACTORY_HPP

#include <memory>
#include "../../ej2/armas/interfaz/Arma.hpp"
#include "../../ej2/personajes/interfaz/Personaje.hpp"
using namespace std;

class PersonajeFactory
{
public:
  static unique_ptr<Personaje> crearPersonaje(Character character);
  static unique_ptr<Arma> crearArma(Weapon weapon);
  static unique_ptr<Personaje> crearPersonajeArmado(Character character, Weapon weapon);
};

#endif // PERSONAJE_FACTORY_HPP