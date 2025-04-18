#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <limits>
#include <string>
using namespace std;

#include "../ej2/armas/Combate/Combate.hpp"
#include "../ej2/armas/Magico/Magico.hpp"
#include "../ej2/armas/interfaz/Arma.hpp"
#include "../ej2/personajes/interfaz/Personaje.hpp"
#include "../ej2/personajes/Mago/Mago.hpp"
#include "../ej2/personajes/Guerrero/Guerrero.hpp"
#include "Game.hpp"
#include "../ej3/PersonajeFactory/PersonajeFactory.hpp"


Game::Game(Character character1, Character character2, Weapon weapon1, Weapon weapon2)
{
  player1 = PersonajeFactory::crearPersonajeArmado(character1, weapon1);
  player2 = PersonajeFactory::crearPersonajeArmado(character2, weapon2);
}

void Game::start()
{
  srand(time(0));
  string winner;
  bool playing = true;
  int turno = 1;
  while (playing)
  {
    cout << string(75, '-') << endl
         << "\t\t\t\tTURNO " << turno++ << endl
         << string(75, '-') << endl;
    showMenu();
    int opcion1 = chooseActionMove(1, 3);
    int opcion2 = rand() % 3 + 1;
    showAttackMenu();
    int attack1 = chooseActionMove(1, 5);
    int attack2 = rand() % 5 + 1;
    int enchant2 = rand() % 4 + 1;

    cout << endl
         << "==> ";
    solveTurn(opcion1, opcion2, attack1, attack2, enchant2);
    cout << endl;

    // condición de finalizado, que un jugador no tenga HP
    if (player1->isDead())
    {
      playing = false;
      winner = player2->getName();
    }
    else if (player2->isDead())
    {
      playing = false;
      winner = player1->getName();
    }
  }

  cout << "====== ¡Juego terminado! El ganador fue " << winner << " ======" << endl;
}

void Game::solveTurn(int chose1, int chose2, int attack1, int attack2, int enchant2)
{
  if (chose1 == chose2)
  {
    cout << "Ambos eligieron la misma opción, no hay daño." << endl;
    return;
  }
  pair<string, int> actualMove;
  pair<Type, int> enchantmentMove;
  // Decido si gano jugador 1, si no empataron ni gano player1, significa que gano player2
  if ((chose1 == 1 && chose2 == 2) || (chose1 == 2 && chose2 == 3) || (chose1 == 3 && chose2 == 1))
  {
    // si el turno es de encantar arma manejo la lógica por separado
    if (attack1 == 5)
    {
      enchantmentMove = showEnchantMenu();
      enchantWeapon1(enchantmentMove.first, enchantmentMove.second);
      cout << player1->getName() << " encantó su arma " << player1->getWeapon(1)->getName() << endl;
      return;
    }
    actualMove = obtainAttackValues1(attack1);
    // si el turno es de habilidad de personaje, el print indica curación en vez de daño
    if (attack1 == 4)
    {
      cout << player1->getName() << " se curó " << actualMove.second << " puntos de salud usando su habilidad " << actualMove.first << endl;
    }
    else
    {
      cout << player1->getName() << " atacó con " << player1->getWeapon(1)->getName() << " usando " << actualMove.first << " y hace " << actualMove.second << " puntos de daño. " << endl;

      player2->changeHealth(-actualMove.second);
    }
  }
  else
  {
    // si el turno es de encantar arma manejo la lógica por separado
    if (attack2 == 5)
    {
      enchantWeapon2(enchant2);
      cout << player2->getName() << " encantó su arma " << player2->getWeapon(1)->getName() << endl;
      return;
    }
    actualMove = obtainAttackValues2(attack2);
    // si el turno es de habilidad de personaje, el print indica curación en vez de daño
    if (attack2 == 4)
    {
      cout << player2->getName() << " se curó " << actualMove.second << " puntos de salud usando su habilidad " << actualMove.first << endl;
    }
    else
    {
      cout << player2->getName() << " atacó con " << player2->getWeapon(1)->getName() << " usando " << actualMove.first << " y hace " << actualMove.second << " puntos de daño. " << endl;
      player1->changeHealth(-actualMove.second);
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
    // Manejo de input de tipo incorrecto
    if (cin.fail())
    {
      cout << "Error, la entrada es de tipo inválido. Ingrese de nuevo su opción: " << endl;
      cin.clear();                                         // Limpia el estado de error de cin
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada
    }
    // Manejo de tipo correcto pero fuera del rango especificado
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

  finalPrint << "== " << player1->getName() << " es de nivel " << player1->getLevel();

  // Realizo downcast para mostrar las opciones y data correctas segun el tipo de personaje
  Mago *player1Mago = dynamic_cast<Mago *>(player1.get());
  Guerrero *player1Guerrero = dynamic_cast<Guerrero *>(player1.get());

  if (player1Mago)
  {
    finalPrint << " y tiene " << player1Mago->getMana() << " Mana " << " ==" << endl;
    characterPrint << "(4) Lanzar hechizo del personaje ";
  }
  else if (player1Guerrero)
  {
    finalPrint << " y tiene " << player1Guerrero->getEnergy() << " Energía " << " ==" << endl;
    characterPrint << "(4) Hablidad de poder del personaje ";
  }

  // Realizo downcast como condición para mostrar las opciones y data correctas segun el tipo de arma
  if (dynamic_cast<Magico *>(player1->getWeapon(1)))
  {
    weaponPrints << "(1) Ataque básico, (2) Movimiento Elemental, (3) Efecto Magico ";
  }
  else
  {
    weaponPrints << "(1) Ataque básico, (2) Movimiento Espiritual, (3) Efecto Espiritual ";
  }

  // Armo el string final para imprimir
  finalPrint << weaponPrints.str() << characterPrint.str() << "(5) Encantar Arma : ";

  cout << endl
       << "Seleccione qué desea hacer en su turno de ataque:" << endl;
  cout << finalPrint.str();
}

pair<string, int> Game::obtainAttackValues1(int playerSelection)
{
  // Downcast para poder tratar al personaje diferente según su tipo
  // Utilizo que dynamic cast devuelve nullptr ante downcast inválido.
  Mago *player1Mago = dynamic_cast<Mago *>(player1.get());
  Guerrero *player1Guerrero = dynamic_cast<Guerrero *>(player1.get());

  if (player1Mago)
    player1Mago->setMana(player1Mago->getMana() + (rand() % 10) * 10);
  if (player1Guerrero)
    player1Guerrero->setEnergy(player1Guerrero->getEnergy() + (rand() % 10) * 10);

  if (playerSelection == 4) // se seleccionó habilidad del personajes
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

  // Repito el downcasting para evaluar tipo, ahora con el arma
  // se utiliza el ataque indicado para el tipo de arma
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
      throw runtime_error("Selección inválida ha sido evaluada para jugador 1");
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
      throw runtime_error("Selección inválida ha sido evaluada para jugador 1");
    };
  }
  else
  {
    throw runtime_error("Tipo de arma invalido");
  }
}

pair<string, int> Game::obtainAttackValues2(int gameSelection)
{
  // Downcast para poder tratar al personaje diferente según su tipo
  // Utilizo que dynamic cast devuelve nullptr ante downcast inválido.
  Mago *player2Mago = dynamic_cast<Mago *>(player2.get());
  Guerrero *player2Guerrero = dynamic_cast<Guerrero *>(player2.get());

  if (player2Mago)
    player2Mago->setMana(player2Mago->getMana() + (rand() % 10) * 10);
  if (player2Guerrero)
    player2Guerrero->setEnergy(player2Guerrero->getEnergy() + (rand() % 10) * 10);

  if (gameSelection == 4) //si tocó habilidad del personaje
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
  // Repito el downcasting para evaluar tipo, ahora con el arma
  // se utiliza el ataque indicado para el tipo de arma
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
      throw runtime_error("Seleccion invalida ha sido evaluada para jugador 2");
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
      throw runtime_error("Seleccion invalida ha sido evaluada para jugador 2");
    };
  }
  else
  {
    throw runtime_error("Tipo de arma invalido");
  }
}

pair<Type, int> Game::showEnchantMenu()
{
  Type retType;
  ostringstream finalPrint;
  finalPrint << "Ganó el turno! puede seleccionar un ";

  // Downcast para verificar el tipo correcto de arma e imprimir correctamente
  // Encantamiento es cambio de elemento para magicas y de espíritu para Combate

  auto weaponMagico = dynamic_cast<Magico *>(player1->getWeapon(1));
  if (weaponMagico)
  {
    finalPrint << "Elemento para su arma:" << endl
               << " (1) Ninguno, (2) Naturaleza, (3) Oscuridad, (4) Lumínico: ";
    retType = Type::Magic;
  }

  auto weaponCombate = dynamic_cast<Combate *>(player1->getWeapon(1));
  if (weaponCombate)
  {
    finalPrint << "Espíritu para su arma: " << endl
               << " (1) Ninguno, (2) Bestia, (3) Dragón, (4) Sombra: ";
    retType = Type::Combat;
  }

  cout << finalPrint.str();
  int retValue = chooseActionMove(1, 4);
  return make_pair(retType, retValue);
}

void Game::enchantWeapon1(Type armaTipo, int selection)
{
  // El tipo de arma es dado por showEnchantMenu, por lo que no necesito
  // Hacer downcasting como condición para verificar el tipo
  switch (armaTipo)
  { //encantamiento afecta a element para armas mágicas y spirit para armas combate
  case Type::Magic:
  {
    auto weaponMagico = dynamic_cast<Magico *>(player1->getWeapon(1));
    if (weaponMagico)
    {
      switch (selection)
      {
      case 2:
        weaponMagico->setElement(Element::Nature);
        break;
      case 3:
        weaponMagico->setElement(Element::Darkness);
        break;
      case 4:
        weaponMagico->setElement(Element::Luminic);
        break;
      default:
        weaponMagico->setElement(Element::None);
        break;
      }
    }
    break;
  }
  case Type::Combat:
  {
    auto weaponCombate = dynamic_cast<Combate *>(player1->getWeapon(1));
    if (weaponCombate)
    {
      switch (selection)
      {
      case 2:
        weaponCombate->setSpirit(Spirit::Beast);
        break;
      case 3:
        weaponCombate->setSpirit(Spirit::Dragon);
        break;
      case 4:
        weaponCombate->setSpirit(Spirit::Shadow);
        break;
      default:
        weaponCombate->setSpirit(Spirit::None);
        break;
      }
    }
    break;
  }
  default:
    throw runtime_error("Tipo de arma invalido");
  }
}

void Game::enchantWeapon2(int selection)
{
  // Downcasting para evaluar el tipo de arma
  auto weaponMagico = dynamic_cast<Magico *>(player2->getWeapon(1));
  auto weaponCombate = dynamic_cast<Combate *>(player2->getWeapon(1));

  //El encantamiento modifica spirit para armas de combate y element para armas mágicas
  if (weaponMagico)
  {
    switch (selection)
    {
    case 2:
      weaponMagico->setElement(Element::Nature);
      break;
    case 3:
      weaponMagico->setElement(Element::Darkness);
      break;
    case 4:
      weaponMagico->setElement(Element::Luminic);
      break;
    default:
      weaponMagico->setElement(Element::None);
      break;
    }
  }

  if (weaponCombate)
  {
    switch (selection)
    {
    case 2:
      weaponCombate->setSpirit(Spirit::Beast);
      break;
    case 3:
      weaponCombate->setSpirit(Spirit::Dragon);
      break;
    case 4:
      weaponCombate->setSpirit(Spirit::Shadow);
      break;
    default:
      weaponCombate->setSpirit(Spirit::None);
      break;
    }
  }
}
