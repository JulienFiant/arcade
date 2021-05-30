/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../../include/IDisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Sfml : public IDisplayModule
{
public:
  Sfml();
  ~Sfml();

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
  void move(Event &evt);
  int getScore() const;

  std::vector<sf::Texture *> _textures;
protected:
  sf::Sprite set_sprite(int x, int y, std::string);

  int _tileSize;
  int _mapStartX;
  int _mapStartY;

  sf::RenderWindow _window;
  sf::Event _evt;

  sf::Font font;
  sf::Text text;

  std::vector<std::string> _map_carac;

  std::vector<IObject *> _map;
  std::vector<IObject *> _bonus;
  std::vector<IEntity *> _enemies;
  std::vector<IEntity *> _player;

  int _score;
};

#endif /* !SFML_HPP_ */
