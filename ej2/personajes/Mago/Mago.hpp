#ifndef MAGO_HPP
#define MAGO_HPP

#include "../interfaz/Personaje.hpp"
#include "../../armas/interfaz/Arma.hpp"
#include <string>
#include <memory>
#include <list>
using namespace std;

class Mago : public Personaje
{
public:
  Mago(string name, int mana = 0, int health = 100, int level = 1);

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

  int getMana() const;
  void setMana(int);

  virtual void castSpell(const string &target) = 0;

  virtual ~Mago();

protected:
  string name;
  int health;
  int level;
  Clan clan;
  list<unique_ptr<Arma>> weapons;
  int mana;
  bool isdead;
};

#endif // MAGO_HPP
