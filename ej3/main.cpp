
#include "PersonajeFactory/PersonajeFactory.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int randomIntBetween(int min, int max);

int main()
{
  srand(time(0));

  // Se decide la cantidad de magos y guerreros
  int cantidadMagos = randomIntBetween(3, 7);
  int cantidadGuerreros = randomIntBetween(3, 7);

  cout <<endl<< "Cantidad de Magos: " << cantidadMagos << endl;
  cout << "Cantidad de Guerreros: " << cantidadGuerreros << endl<<endl;

  vector<unique_ptr<Personaje>> personajes; //vector para guardar los personajes creados

  for (int i = 0; i < cantidadMagos; i++)
  {
    // Para cada mago, decido random que tipo de mago es
    int magoRandom = randomIntBetween(0, 3);
    Character tipoMago;
    switch (magoRandom)
    {
    case 0:
      tipoMago = Character::Bruja;
      break;
    case 1:
      tipoMago = Character::Conjurador;
      break;
    case 2:
      tipoMago = Character::Hechicero;
      break;
    default:
      tipoMago = Character::Nigromante;
      break;
    }

    auto mago = PersonajeFactory::crearPersonaje(tipoMago);
    if (mago)
    {
      // decido cuantas armas tendrá el personaje creado
      int armasNum = randomIntBetween(0, 2);
      for (int j = 0; j < armasNum; j++)
      {
        // decido qué armas serán entre los 9 tipos distintos
        int armaRand = randomIntBetween(0, 8);
        auto arma = PersonajeFactory::crearArma(static_cast<Weapon>(armaRand));
        if (arma)
        {
          // Le doy ownership al personaje
          mago->equipWeapon(move(arma));
        }
        else
        {
          throw runtime_error("Error al crear el arma.");
        }
      }
      personajes.push_back(move(mago));
    }
    else
    {
      throw runtime_error("Error al crear personaje Mago.");
    }
  }

  
  for (int i = 0; i < cantidadGuerreros; i++)
  {
    // Para cada mago, decido random que tipo de mago es
    int guerreroRandom = randomIntBetween(0, 4);
    Character tipoGuerrero;
    switch (guerreroRandom)
    {
    case 0:
      tipoGuerrero = Character::Barbaro;
      break;
    case 1:
      tipoGuerrero = Character::Caballero;
      break;
    case 2:
      tipoGuerrero = Character::Gladiador;
      break;
    case 3:
      tipoGuerrero = Character::Mercenario;
      break;
    default:
      tipoGuerrero = Character::Paladin;
      break;
    }

    auto guerrero = PersonajeFactory::crearPersonaje(tipoGuerrero);
    if (guerrero)
    {
      // Decido cuantas armas tendra el personaje
      int armasNum = randomIntBetween(0, 2);
      for (int j = 0; j < armasNum; j++)
      {
        // Decido qué tipo de armma tendrá el personaje entre las 9 posibles.
        int armaRand = randomIntBetween(0, 8);
        auto arma = PersonajeFactory::crearArma(static_cast<Weapon>(armaRand));
        if (arma)
        {
          // Le doy ownership del arma al personaje
          guerrero->equipWeapon(move(arma));
        }
        else
        {
          throw runtime_error("Error al crear arma.");
        }
      }
      personajes.push_back(move(guerrero));
    }
    else
    {
      throw runtime_error("Error al crear personaje Guerrero.");
    }
  }

  cout << "Se han creado " << personajes.size() << " personajes en total." << endl;
  cout << string(70, '=') << endl
       << "Personajes creados y sus armas" << endl
       << string(70, '=') << endl;

  for (size_t i = 0; i < personajes.size(); i++)
  {
    if (static_cast<int>(i) == 0){
      cout<<endl<< "Personajes tipo mago"<<endl<< string(50, '-') <<endl;
    }
    else if (static_cast<int>(i) == cantidadMagos){
      cout<<endl<< "Personajes tipo Guerrero"<<endl<< string(50, '-') <<endl;
    }
    auto personaje = personajes[i].get();
    cout << "Personaje: " << personaje->getName() << endl;
    cout << "Armas: " << endl;
    // obtengo ambas posibles armas, luego verifico si habia arma o es nullptr
    auto firstWeapon = personaje->getWeapon(1);
    auto secondWeapon = personaje->getWeapon(2);
    if (!firstWeapon)
    {
      cout << "El personaje no tiene armas" << endl
           << endl;
      continue;
    }
    else
    {
      cout << firstWeapon->getName() << endl;
    }
    if (secondWeapon)
    {
      cout << secondWeapon->getName() << endl;
    }

    cout << endl;
  }
  return 0;
}

int randomIntBetween(int min, int max)
{
  return min + (rand() % (max - min + 1));
}