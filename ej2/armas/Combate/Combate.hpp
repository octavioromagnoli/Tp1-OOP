#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "../interfaz/Arma.hpp"
#include <string>
using namespace std;

enum class Spirit
{
  None,
  Beast,
  Dragon,
  Shadow
};

class Combate : public Arma
{
public:
  Combate(string name, int damage, Spirit spirit = Spirit::None, int level = 1, bool broken = false);

  string getName() const override;
  int getDamage() const override;
  Type getType() const override;
  int getLevel() const override;
  bool setLevel(int) override;
  bool isBroken() const override;
  void setBroken(bool) override;

  Spirit getSpirit() const;
  void setSpirit(Spirit);

  
  /*
    Retorna string con el ataque básico del arma y el daño que aplica.
  */
 virtual pair<string, int> basicMove() = 0;
 /*
   Retorna string con el ataque Elemental del arma y el daño que aplica.
 */
 virtual pair<string, int> spriritualMove() = 0;
 /*
   Retorna string con el efecto Mágico del arma y el daño que aplica.
 */
 virtual pair<string, int> spriritualEffect() = 0;


protected:
  string name;
  int damage;
  Type type;
  int level;
  bool broken;

  Spirit spirit;
};

#endif // COMBATE_HPP
