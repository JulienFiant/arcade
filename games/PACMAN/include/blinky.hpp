/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** blinky
*/

#ifndef BLINKY_HPP_
#define BLINKY_HPP_

#include "../../../core/IEntity.hpp"

class blinky : public IEntity
{
public:
  blinky();
  ~blinky();

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
  size_t _sprite_idx;
  std::string _name;

  int _score;
  Clock timer;
};

#endif /* !BLINKY_HPP_ */
