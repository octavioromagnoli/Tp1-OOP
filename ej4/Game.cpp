#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <limits>
using namespace std;

#include "../ej2/armas/Combate/Combate.hpp"
#include "../ej2/armas/Magico/Magico.hpp"
#include "../ej2/armas/interfaz/Arma.hpp"
#include "../ej2/personajes/interfaz/Personaje.hpp"
#include "../ej2/personajes/Mago/Mago.hpp"
#include "../ej2/personajes/Guerrero/Guerrero.hpp"
#include "Game.hpp"
#include "../ej3/PersonajeFactory/PersonajeFactory.hpp"

// TODO agregar lógica para encantar el arma (en el cout para que de la opcion y en solveTurn)

// ! revisar punteros raw para no dejar dangling pointers

Game::Game(Character character1, Character character2, Weapon weapon1, Weapon weapon2)
{
  player1 = PersonajeFactory::crearPersonajeArmado(character1, weapon1);
  player2 = PersonajeFactory::crearPersonajeArmado(character2, weapon2);
}

void Game::start()
{
  srand(time(0));
  bool playing = true;
  while (playing)
  {
    showMenu();
    int opcion1 = chooseActionMove(1, 3);
    int opcion2 = rand() % 3 + 1;
    showAttackMenu();
    int attack1 = chooseActionMove(1, 4);
    int attack2 = rand() % 4 + 1;

    solveTurn(opcion1, opcion2, attack1, attack2);

    if (player1->isDead() || player2->isDead())
    {
      playing = false;
    }
  }

  cout << "¡Juego terminado!\n";
}

void Game::solveTurn(int chose1, int chose2, int attack1, int attack2)
{
  if (chose1 == chose2)
  {
    cout << "Ambos eligieron la misma opción, no hay daño." << endl;
    return;
  }
  pair<string, int> actualMove;
  if ((chose1 == 1 && chose2 == 2) || (chose1 == 2 && chose2 == 3) || (chose1 == 3 && chose2 == 1))
  {
    actualMove = obtainAttackValues1(attack1);
    if (attack1 == 4)
    {
      cout << player1->getName() << " se curó " << actualMove.second << " puntos de salud usando su habilidad " << actualMove.first << endl;
    }
    else
    {
      cout << player1->getName() << " atacó con " << player1->getWeapon(1)->getName() << " usando " << actualMove.first << " y hace " << actualMove.second << " puntos de daño. " << endl;

      player2->changeHealth(- actualMove.second);
    }
  }
  else
  {
    actualMove = obtainAttackValues2(attack2);
    if (attack2 == 4)
    {
      cout << player2->getName() << " se curó " << actualMove.second << " puntos de salud usando su habilidad " << actualMove.first << endl;
    }
    else
    {
      cout << player2->getName() << " atacó con " << player2->getWeapon(1)->getName() << " usando " << actualMove.first << " y hace " << actualMove.second << " puntos de daño. " << endl;
      player1->changeHealth(- actualMove.second);
    }
  }
}

void Game::showMenu()
{
  cout << player1->getName() << " tiene " << player1->getHealth() << " HP" << endl;
  cout << player2->getName() << " tiene " << player2->getHealth() << " HP" << endl;
  cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
}

int Game::chooseActionMove(int min, int max)
{
  bool gotAnswer = false;
  int opcion;
  while (!gotAnswer)
  {
    cin >> opcion;
    if (cin.fail())
    {
      cout << "Error, la entrada es de tipo inválido. Ingrese de nuevo su opción: " << endl;
      cin.clear();                                         // Limpia el estado de error de cin
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada
    }
    else if (opcion < min || opcion > max)
    {
      cout << "Error, debe elegir un número entre " << min << " y " << max << ". Ingrese de nuevo su opción: " << endl;
    }
    else
      gotAnswer = true;
  }
  return opcion;
}

void Game::showAttackMenu()
{
  ostringstream finalPrint;
  ostringstream characterPrint;
  ostringstream weaponPrints;

  finalPrint << player1->getName() << " es de nivel " << player1->getLevel();

  Mago *player1Mago = dynamic_cast<Mago *>(player1.get());
  Guerrero *player1Guerrero = dynamic_cast<Guerrero *>(player1.get());
  if (player1Mago)
  {
    finalPrint << " y tiene " << player1Mago->getMana() << " Mana " << endl;
    characterPrint << "(4) Lanzar hechizo del personaje ";
  }
  else if (player1Guerrero)
  {
    finalPrint << " y tiene " << player1Guerrero->getEnergy() << " Energía " << endl;
    characterPrint << "(4) Hablidad de poder del personaje ";
  }
  player1Mago = nullptr;
  player1Guerrero = nullptr;

  if (dynamic_cast<Magico *>(player1->getWeapon(1)))
  {
    weaponPrints << "(1) Ataque básico, (2) Movimiento Elemental, (3) Efecto Magico ";
  }
  else
  {
    weaponPrints << "(1) Ataque básico, (2) Movimiento Espiritual, (3) Efecto Espiritual ";
  }

  finalPrint << weaponPrints.str() << characterPrint.str() << endl;

  cout << "Seleccione que desea hacer en su turno de ataque:" << endl;
  cout << finalPrint.str();
}

pair<string, int> Game::obtainAttackValues1(int playerSelection)
{
  Mago *player1Mago = dynamic_cast<Mago *>(player1.get());
  Guerrero *player1Guerrero = dynamic_cast<Guerrero *>(player1.get());
  if (player1Mago) player1Mago->setMana(player1Mago->getMana() + (rand() % 10) * 10);
  if (player1Guerrero) player1Guerrero->setEnergy(player1Guerrero->getEnergy() + (rand() % 10) * 10);


  if (playerSelection == 4)
  {
    if (player1Mago)
    {
      return player1Mago->castSpell();
    }
    else if (player1Guerrero)
    {
      return player1Guerrero->powerCall();
    }
  }
  if (dynamic_cast<Magico *>(player1->getWeapon(1)))
  {
    auto weapon = dynamic_cast<Magico *>(player1->getWeapon(1));
    switch (playerSelection)
    {
    case 1:
      return weapon->basicMove();
    case 2:
      return weapon->elementalMove();
    case 3:
      return weapon->magicalEffect();
    default:
      throw runtime_error("Invalid player selection");
    };
  }
  else if (dynamic_cast<Combate *>(player1->getWeapon(1)))
  {
    auto weapon = dynamic_cast<Combate *>(player1->getWeapon(1));
    switch (playerSelection)
    {
    case 1:
      return weapon->basicMove();
    case 2:
      return weapon->spiritualMove();
    case 3:
      return weapon->spiritualEffect();
    default:
      throw runtime_error("Invalid player selection");
    };
  }
  else
  {
    throw runtime_error("Invalid weapon type");
  }
}

pair<string, int> Game::obtainAttackValues2(int gameSelection)
{
  Mago *player2Mago = dynamic_cast<Mago *>(player2.get());
  Guerrero *player2Guerrero = dynamic_cast<Guerrero *>(player2.get());
  if (player2Mago) player2Mago->setMana(player2Mago->getMana() + (rand() % 10) * 10);
  if (player2Guerrero) player2Guerrero->setEnergy(player2Guerrero->getEnergy() + (rand() % 10) * 10);


  if (gameSelection == 4)
  {

    if (player2Mago)
    {
      return player2Mago->castSpell();
    }
    else if (player2Guerrero)
    {
      return player2Guerrero->powerCall();
    }
  }
  if (dynamic_cast<Magico *>(player2->getWeapon(1)))
  {
    auto weapon = dynamic_cast<Magico *>(player2->getWeapon(1));
    switch (gameSelection)
    {
    case 1:
      return weapon->basicMove();
    case 2:
      return weapon->elementalMove();
    case 3:
      return weapon->magicalEffect();
    default:
      throw runtime_error("Invalid player selection");
    };
  }
  else if (dynamic_cast<Combate *>(player2->getWeapon(1)))
  {
    auto weapon = dynamic_cast<Combate *>(player2->getWeapon(1));
    switch (gameSelection)
    {
    case 1:
      return weapon->basicMove();
    case 2:
      return weapon->spiritualMove();
    case 3:
      return weapon->spiritualEffect();
    default:
      throw runtime_error("Invalid player selection");
    };
  }
  else
  {
    throw runtime_error("Invalid weapon type");
  }
}
