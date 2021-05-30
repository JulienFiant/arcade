/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../../include/IDisplayModule.hpp"
#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Ncurses : public IDisplayModule
{
public:
  Ncurses();
  ~Ncurses();

  //commun à IDisplay
  std::string menu(std::vector<std::string>);

  void InitWindow();
  void init_map();
  void getevent(Event &evt);
  void create_map(std::vector<std::string> src_map);
  void set_map(std::vector<IObject *> &);
  void set_player(std::vector<IEntity *> &);
  void set_enemy(std::vector<IEntity *> &);
  void set_bonus(std::vector<IObject *> &);
  void display_all();
  int game_over();

  int getScore() const;

  std::vector<std::string> getMapN();

protected:
  int pos[2];
  int _score;

  std::vector<int> _enemie_color;

  std::string _pac;
  std::string _blinky;
  std::string _pinky;
  std::string _inky;
  std::string _clyde;

  sf::Sprite set_sprite(int x, int y, std::string);
  std::vector<std::string> _map;
  std::vector<std::string> _map_raw;
  std::vector<IObject *> _obj_map;
  std::vector<IObject *> _bonus;
  std::vector<IEntity *> _enemies;
  std::vector<IEntity *> _player;
  int _ch;
};

#endif /* !NCURSES_HPP_ */
