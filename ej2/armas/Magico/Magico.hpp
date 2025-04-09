#ifndef MAGICO_HPP
#define MAGICO_HPP

#include "../interfaz/Arma.hpp"
#include <iostream>
using namespace std;

enum class Element{
  None,
  Nature,
  Darkness,
  Luminic
};

class Magico: public Arma{
  public:
    Magico(string name, int damage, Element element, int level = 1, bool broken = false);

    string getName() const override;
    int getDamage() const override;
    Type getType() const override;
    int getLevel() const override;
    bool setLevel(int) override;
    bool isBroken() const override;
    void setBroken(bool) override;

    Element getElement() const;
    void setElement(Element);
 

    virtual int basicMove() = 0;
    virtual int elementalMove() = 0;
    virtual int magicalEffect() = 0;

  protected:
    string name;
    int damage;
    Type type;
    int level;
    bool broken;

    Element element;
};

#endif//MAGICO_HPP

