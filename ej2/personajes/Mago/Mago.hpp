#ifndef MAGO_HPP
#define MAGO_HPP

#include "../interfaz/Personaje.hpp"
#include "../../armas/interfaz/Arma.hpp"
#include <string>
#include <memory>
#include <utility>
#include <list>
using namespace std;

class Mago : public Personaje
{
public:
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
  Arma* getWeapon(int) override;

  int getMana() const;
  void setMana(int);

  virtual pair<string, int> castSpell() = 0;

  virtual ~Mago();

protected:
  Mago(string name, int mana = 0, int health = 100, int level = 1);

  string name;
  int health;
  int level;
  Clan clan;
  list<unique_ptr<Arma>> weapons;
  int mana;
  bool isdead;
};

#endif // MAGO_HPP
