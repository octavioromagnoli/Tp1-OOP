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

#include<ostream>
#include<memory>
using namespace std;

int main(){
  auto libro = make_unique<Libro>;
  auto bruja = make_unique<Bruja>;

  auto espada = make_unique<Espada>();
  return 0;
}