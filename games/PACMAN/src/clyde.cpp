/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** clyde
*/

#include <iostream>
#include "../include/clyde.hpp"

clyde::clyde()
{
    _name_sprite.push_back("./assets/Pacman/clyde_neutral.png");
    _name_sprite.push_back("./assets/Pacman/ghost_scared.png");
    _name_sprite.push_back("./assets/Pacman/ghost_dead.png");
    _color.push_back(9);
    _color.push_back(5);
    _color.push_back(4);
    _name = "clyde";
    _sprite_idx = 0;
    _tileSize = 16;
    _mapStartX = 1;
    _mapStartY = 2;
    _score = 0;
    _sprite_ncurses = "O";
    _SFMLSetup = false;
    timer.start();
    _movClock.start();
    _mov[0] = 0.0f;
    _mov[1] = 0.0f;
}

clyde::~clyde()
{
}

void clyde::setBonus(int bonus)
{
    if (_sprite_idx != 2)
        _sprite_idx = bonus;
}

int clyde::getBonus()
{
    return (0);
}

void clyde::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
    _SFMLSetup = true;
}

sf::Sprite clyde::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void clyde::changePosSpriteSFML(float x, float y)
{
    _sprite_sfml.setPosition(x, y);
}

void clyde::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string clyde::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void clyde::setNameSprite(std::string name_sprite)
{
    _name_sprite[0] = name_sprite;
}

std::string clyde::getNameSprite() const
{
    return (_name_sprite[_sprite_idx]);
}

int clyde::getColorChar() const
{
    return (_color[_sprite_idx]);
}

void clyde::setName(std::string name)
{
    _name = name;
}

std::string clyde::getName() const
{
    return (_name);
}

void clyde::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *clyde::getPos() const
{
    return (_pos);
}

void clyde::check_bonus(std::vector<IObject *> &bonus)
{
}

std::vector<std::string> clyde::move(Event &evt, std::vector<std::string> _map_carac, std::vector<IObject *> &bonus)
{
    int dir = std::rand() % 4;

    if (_movClock.get_time() > 200.0)
    {
        if (_sprite_idx == 2)
        {
            float tmp[2] = {13, 15};
            float *v = VectorCalc::base_v2(_pos, tmp);
            _pos[0] += v[0] / 2.0;
            _pos[1] += v[1] / 2.0;
            if (abs(_pos[0] - 13) < 1 && abs(_pos[1] - 15) < 1)
            {
                _pos[0] = 13;
                _pos[1] = 15;
            }
            if (_pos[0] == 13 && _pos[1] == 15)
                _sprite_idx = 0;
        }
        else
        {
            if (_map_carac[_pos[1]][_pos[0] + 1] != '1' && dir == 0)
            {
                _mov[0] = 1.0f;
                _mov[1] = 0.0f;
            }
            else if (_map_carac[_pos[1]][_pos[0] - 1] != '1' && dir == 1)
            {
                _mov[0] = -1.0f;
                _mov[1] = 0.0f;
            }
            else if (_map_carac[_pos[1] + 1][_pos[0]] != '1' && dir == 2)
            {
                _mov[0] = 0.0f;
                _mov[1] = 1.0f;
            }
            else if (_map_carac[_pos[1] - 1][_pos[0]] != '1' && dir == 3)
            {
                _mov[0] = 0.0f;
                _mov[1] = -1.0f;
            }
            if (timer.get_time() < 10000)
                return (_map_carac);
            if (_map_carac[_pos[1] + _mov[1]][_pos[0] + _mov[0]] != '1')
            {
                _pos[0] += _mov[0];
                _pos[1] += _mov[1];
            }
            if (_pos[0] < 0)
                _pos[0] = (float)(_map_carac[0].length() - 1);
            if (_pos[0] > (float)(_map_carac[0].length() - 1))
                _pos[0] = 0;
        }
        _movClock.start();
    }
    return (_map_carac);
}

int clyde::getScore() const
{
    return (_score);
}

void clyde::destroy_sprite()
{
    sf::Sprite sp;
    _sprite_sfml = sp;
}
