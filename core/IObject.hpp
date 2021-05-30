/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "VectorCalc.hpp"

class IObject
{
public:
  virtual ~IObject() = default;

  virtual void setSpriteSFML(sf::Sprite sprite) = 0;
  virtual sf::Sprite getSpriteSFML() const = 0;

  virtual void setSpriteNCURSES(std::string sprite) = 0;
  virtual std::string getSpriteNCURSES() const = 0;

  virtual void setNameSprite(std::string name_sprite) = 0;
  virtual std::string getNameSprite() const = 0;

  virtual int getColorChar() const = 0;

  virtual void setName(std::string name) = 0;
  virtual std::string getName() const = 0;

  virtual void setPos(float *pos) = 0;
  virtual const float *getPos() const = 0;

  virtual void setScore(int score) = 0;
  virtual int getScore() const = 0;

protected:
  float _pos[2];
};

#endif /* !IOBJECT_HPP_ */
