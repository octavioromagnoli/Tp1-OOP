#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "../interfaz/Arma.hpp"
#include <string>
using namespace std;

enum class Spirit{
  None,
  Beast,
  Dragon,
  Shadow
};

class Combate: public Arma{
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
 

    virtual int basicMove() = 0;
    virtual int spiritualMove() = 0;
    virtual int spiritualEffect() = 0;

  protected:
    string name;
    int damage;
    Type type;
    int level;
    bool broken;

    Spirit spirit;
};

#endif//COMBATE_HPP

