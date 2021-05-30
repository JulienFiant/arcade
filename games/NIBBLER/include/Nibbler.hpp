/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../../include/IGameModule.hpp"
#include "Head.hpp"
#include "Tail.hpp"
#include "Fruit.hpp"
#include "../../include/Wall.hpp"

class Nibbler : public IGameModule
{
public:
  Nibbler();
  ~Nibbler();

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

#endif /* !NIBBLER_HPP_ */
