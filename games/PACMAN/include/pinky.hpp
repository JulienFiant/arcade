/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** pinky
*/

#ifndef PINKY_HPP_
#define PINKY_HPP_

#include "../../../core/IEntity.hpp"

class pinky : public IEntity
{
public:
  pinky();
  ~pinky();

  void setBonus(int = 0);
  int getBonus();

  void setSpriteSFML(sf::Sprite sprite);
  sf::Sprite getSpriteSFML() const;
  void changePosSpriteSFML(float x, float y);

  void setSpriteNCURSES(std::string sprite);
  std::string getSpriteNCURSES() const;

  void setNameSprite(std::string name_sprite);
  std::string getNameSprite() const;

  int getColorChar() const;

  void setName(std::string name);
  std::string getName() const;

  void setPos(float *pos);
  const float *getPos() const;

  std::vector<std::string> move(Event &evt, std::vector<std::string> _map_carac, std::vector<IObject *> &bonus);
  void check_bonus(std::vector<IObject *> &bonus);

  int getScore() const;

  void destroy_sprite();

protected:
  int _tileSize;
  int _mapStartX;
  int _mapStartY;

  sf::Sprite _sprite_sfml;
  std::string _sprite_ncurses;

  bool _SFMLSetup;

  std::vector<std::string> _name_sprite;
  std::vector<int> _color;
  std::string _name;
  size_t _sprite_idx;

  int _score;
  Clock timer;
};

#endif /* !PINKY_HPP_ */
