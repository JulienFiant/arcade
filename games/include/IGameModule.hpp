/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <string>
#include <iostream>
#include <vector>
#include "../../core/Event.hpp"
#include "../../core/IEntity.hpp"
#include "../../core/IObject.hpp"
#include "../../core/VectorCalc.hpp"
#include <ncurses.h>

class IGameModule
{
public:
  virtual ~IGameModule() = default;
  virtual void init_all() = 0;
  virtual void getevent(Event &evt) = 0;
  virtual void play() = 0;
  virtual bool game_over() = 0;
  virtual int getScore() const = 0;
  virtual void setScore(int score) = 0;
  virtual std::vector<IObject *> &getMap() = 0;
  virtual std::vector<IObject *> &getBonus() = 0;
  virtual std::vector<IEntity *> &getPlayer() = 0;
  virtual std::vector<IEntity *> &getEnemies() = 0;
  virtual void destroy_sprite() = 0;
};

typedef void *create_t();
typedef void destroy_t(void *p);

#endif /* !IGAMEMODULE_HPP_ */
