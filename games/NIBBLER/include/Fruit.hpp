/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "../../../core/IObject.hpp"

class Fruit : public IObject
{
public:
  Fruit();
  ~Fruit();

  void setSpriteSFML(sf::Sprite sprite);
  sf::Sprite getSpriteSFML() const;

  void setSpriteNCURSES(std::string sprite);
  std::string getSpriteNCURSES() const;

  void setNameSprite(std::string name_sprite);
  std::string getNameSprite() const;

  int getColorChar() const;

  void setName(std::string name);
  std::string getName() const;

  void setPos(float *pos);
  const float *getPos() const;

  void setScore(int score);
  int getScore() const;

protected:
  sf::Sprite _sprite_sfml;
  std::string _sprite_ncurses;

  std::string _name_sprite;
  std::string _name;

  int _score;
};

#endif /* !FRUIT_HPP_ */
