#ifndef MAGICO_HPP
#define MAGICO_HPP

#include "../interfaz/Arma.hpp"
#include <string>
#include <utility>
using namespace std;

enum class Element
{
  None,
  Nature,
  Darkness,
  Luminic
};

class Magico : public Arma
{
public:
  Magico(string name, int damage, Element element = Element::None, int level = 1, bool broken = false);

  string getName() const override;
  int getDamage() const override;
  Type getType() const override;
  int getLevel() const override;
  bool setLevel(int) override;
  bool isBroken() const override;
  void setBroken(bool) override;

  Element getElement() const;
  void setElement(Element);

  /*
    Retorna string con el ataque básico del arma y el daño que aplica.
  */
  virtual pair<string, int> basicMove() = 0;
  /*
    Retorna string con el ataque Elemental del arma y el daño que aplica.
  */
  virtual pair<string, int> elementalMove() = 0;
  /*
    Retorna string con el efecto Mágico del arma y el daño que aplica.
  */
  virtual pair<string, int> magicalEffect() = 0;

  virtual ~Magico();

protected:
  string name;
  int damage;
  Type type;
  int level;
  bool broken;

  Element element;
};

#endif // MAGICO_HPP
