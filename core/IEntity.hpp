/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#define EQ_F(a, b, e) (abs(a - b) < e)

#include "Event.hpp"
#include "IObject.hpp"
#include "../games/include/Clock.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ncurses.h>
#include <vector>
#include <math.h>
#include "VectorCalc.hpp"

class IObject;

class IEntity
{
public:
  virtual ~IEntity() = 0;

  virtual void setBonus(int) = 0;
  virtual int getBonus() = 0;

  virtual void setSpriteSFML(sf::Sprite sprite) = 0;
  virtual sf::Sprite getSpriteSFML() const = 0;
  virtual void changePosSpriteSFML(float x, float y) = 0;

  virtual void setSpriteNCURSES(std::string sprite) = 0;
  virtual std::string getSpriteNCURSES() const = 0;

  virtual void setNameSprite(std::string name_sprite) = 0;
  virtual std::string getNameSprite() const = 0;

  virtual int getColorChar() const = 0;

  virtual void setName(std::string name) = 0;
  virtual std::string getName() const = 0;

  virtual void setPos(float *pos) = 0;
  virtual const float *getPos() const = 0;

  virtual std::vector<std::string> move(Event &evt, std::vector<std::string> _map_carac, std::vector<IObject *> &bonus) = 0;
  virtual void check_bonus(std::vector<IObject *> &bonus) = 0;

  virtual int getScore() const = 0;

  virtual void destroy_sprite() = 0;

  protected:
    float _mov[2];
    float _pos[2];
    Clock _movClock;
};

#endif /* !IENTITY_HPP_ */
