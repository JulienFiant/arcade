/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include "../../core/Event.hpp"
#include "../../core/IObject.hpp"
#include "../../core/IEntity.hpp"

class IDisplayModule
{
public:
  virtual ~IDisplayModule() = default;

  virtual std::string menu(std::vector<std::string>) = 0;

  virtual void InitWindow() = 0;
  virtual void init_map() = 0;
  virtual void getevent(Event &evt) = 0;
  virtual void create_map(std::vector<std::string> src_map) = 0;

  virtual void set_map(std::vector<IObject *> &) = 0;
  virtual void set_player(std::vector<IEntity *> &) = 0;
  virtual void set_enemy(std::vector<IEntity *> &) = 0;
  virtual void set_bonus(std::vector<IObject *> &) = 0;

  virtual void display_all() = 0;
  virtual int game_over() = 0;
  virtual int getScore() const = 0;

  /*
  virtual void initBlinky() = 0;
  virtual void initPinky() = 0;
  virtual void initInky() = 0;
  virtual void initClyde() = 0;

  virtual void setBlinky(int x, int y) = 0;
  virtual void setPinky(int x, int y) = 0;
  virtual void setInky(int x, int y) = 0;
  virtual void setClyde(int x, int y) = 0;
  */
};

typedef void *create_t();
typedef void destroy_t(void *p);

#endif /* !IDISPLAYMODULE_HPP_ */
