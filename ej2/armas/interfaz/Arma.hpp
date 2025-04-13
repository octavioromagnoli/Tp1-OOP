#ifndef ARMAS_HPP
#define ARMAS_HPP

#include <string>
using namespace std;

enum class Type
{
  Magic,
  Combat
};

enum class Weapon{
  Espada,
  Garrote,
  Hachadoble,
  Hachasimple,
  Lanza,
  Amuleto,
  Baston,
  Libro,
  Pocion
};

class Arma
{
public:
  virtual ~Arma(){}; 
  virtual string getName() const = 0;
  virtual int getDamage() const = 0;
  virtual Type getType() const = 0;
  virtual int getLevel() const = 0;
  virtual bool setLevel(int) = 0;
  virtual bool isBroken() const = 0;
  virtual void setBroken(bool) = 0;
};

#endif // ARMAS_HPP