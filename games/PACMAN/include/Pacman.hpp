/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../include/IGameModule.hpp"
#include "pac.hpp"
#include "PacGumSmall.hpp"
#include "PacGumSpecial.hpp"
#include "blinky.hpp"
#include "clyde.hpp"
#include "inky.hpp"
#include "pinky.hpp"
#include "../../include/Wall.hpp"

class Pacman : public IGameModule
{
public:
  Pacman();
  ~Pacman();

  void init_all();
  void getevent(Event &evt);
  void play();
  bool game_over();

  int getScore() const;
  void setScore(int score);

  std::vector<IObject *> &getMap();
  std::vector<IObject *> &getBonus();
  std::vector<IEntity *> &getPlayer();
  std::vector<IEntity *> &getEnemies();

  void destroy_sprite();

  std::vector<std::string> _strMap;
  std::vector<IObject *> _map;
  std::vector<IObject *> _bonus;
  std::vector<IEntity *> _enemies;
  std::vector<IEntity *> _player;

protected:
  int _score;
};

#endif /* !PACMAN_HPP_ */
