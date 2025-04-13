#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <string>
#include <memory>
#include "../../armas/interfaz/Arma.hpp"
using namespace std;

enum class Clan
{
  Mage,
  Warrior
};

enum class Character{
  Barbaro,
  Caballero,
  Gladiador,
  Mercenario,
  Paladin,
  Bruja,
  Conjurador,
  Hechicero,
  Nigromante
};

class Personaje
{
public:
  virtual ~Personaje(){};
  virtual string getName() const = 0;
  virtual int getHealth() const = 0;
  virtual bool setHealth(int) = 0;
  virtual void changeHealth(int) = 0;
  virtual Clan getClan() const = 0;
  virtual int getLevel() const = 0;
  virtual bool setLevel(int) = 0;
  virtual bool isDead() const = 0;
  virtual bool equipWeapon(unique_ptr<Arma>) = 0;
  virtual void discardWeapon(int) = 0;
  virtual Arma *getWeapon(int) = 0;
};

#endif // PERSONAJE_HPP