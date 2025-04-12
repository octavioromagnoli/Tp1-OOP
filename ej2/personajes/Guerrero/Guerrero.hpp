#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "../interfaz/Personaje.hpp"
#include "../../armas/interfaz/Arma.hpp"
#include <string>
#include <memory>
#include <list>
using namespace std;

class Guerrero : public Personaje
{
public:
  Guerrero(string name, int mana = 0, int health = 100, int level = 1);

  string getName() const override;
  int getHealth() const override;
  bool setHealth(int) override;
  void changeHealth(int) override;
  Clan getClan() const override;
  int getLevel() const override;
  bool setLevel(int) override;
  bool isDead() const override;
  bool equipWeapon(unique_ptr<Arma>) override;
  void discardWeapon(int) override;

  int getEnergy() const;
  void setEnergy(int);

  virtual pair<string, int> powerCall() = 0;

  virtual ~Guerrero();

protected:
  string name;
  int health;
  int level;
  Clan clan;
  list<unique_ptr<Arma>> weapons;
  int energy;
  bool isdead;
};

#endif // GUERRERO_HPP
