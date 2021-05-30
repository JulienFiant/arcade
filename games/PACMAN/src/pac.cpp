/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** pac
*/

#include <iostream>
#include "../include/pac.hpp"

pac::pac()
{
    _name_sprite = "./assets/Pacman/pac_neutral.png";
    _name = "pac";
    _tileSize = 16;
    _mapStartX = 1;
    _mapStartY = 2;
    _score = 0;
    _bonus = 0;
    _sprite_ncurses = "O";
    _SFMLSetup = false;
    _movClock.start();
    _mov[0] = 0.0f;
    _mov[1] = 0.0f;
}

pac::~pac()
{
}

void pac::setBonus(int bonus)
{
    _bonus = bonus;
}

int pac::getBonus()
{
    return (_bonus);
}

void pac::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
    _SFMLSetup = true;
}

sf::Sprite pac::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void pac::changePosSpriteSFML(float x, float y)
{
    _sprite_sfml.setPosition(x, y);
}

void pac::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string pac::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void pac::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string pac::getNameSprite() const
{
    return (_name_sprite);
}

int pac::getColorChar() const
{
    return (3);
}

void pac::setName(std::string name)
{
    _name = name;
}

std::string pac::getName() const
{
    return (_name);
}

void pac::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *pac::getPos() const
{
    return (_pos);
}

void pac::check_bonus(std::vector<IObject *> &bonus)
{
    std::vector<IObject *>::iterator o = bonus.begin();
    for (size_t i = 0; i < bonus.size(); ++i)
    {
        if (EQ_F(_pos[0], bonus[i]->getPos()[0], 0.001) && EQ_F(_pos[1], bonus[i]->getPos()[1], 0.001))
        {
            if (bonus[i]->getName().find("PacGum") == 0)
                _score += bonus[i]->getScore();
            if (bonus[i]->getName() == "PacGumSpecial")
            {
                _bonus = 1;
                timer.start();
            }
            bonus.erase(o);
        }
        ++o;
    }
}

std::vector<std::string> pac::move(Event &evt, std::vector<std::string> _map_carac, std::vector<IObject *> &bonus)
{
    if (_bonus == 1 && timer.get_time() > 10000)
    {
        _bonus = 0;
        timer.pause();
    }
    if (_map_carac[_pos[1]][_pos[0] + 1] != '1' &&
        _map_carac[_pos[1]][_pos[0] + 1] != '9' && evt._evtType == Event::D)
    {
        _mov[0] = 1.0f;
        _mov[1] = 0.0f;
        _sprite_ncurses = "<";
    }
    else if (_map_carac[_pos[1]][_pos[0] - 1] != '1' &&
             _map_carac[_pos[1]][_pos[0] + 1] != '9' && evt._evtType == Event::Q)
    {
        _mov[0] = -1.0f;
        _mov[1] = 0.0f;
        _sprite_ncurses = ">";
    }
    else if (_map_carac[_pos[1] + 1][_pos[0]] != '1' &&
             _map_carac[_pos[1]][_pos[0] + 1] != '9' && evt._evtType == Event::S)
    {
        _mov[0] = 0.0f;
        _mov[1] = 1.0f;
        _sprite_ncurses = "^";
    }
    else if (_map_carac[_pos[1] - 1][_pos[0]] != '1' &&
             _map_carac[_pos[1]][_pos[0] + 1] != '9' && evt._evtType == Event::Z)
    {
        _mov[0] = 0.0f;
        _mov[1] = -1.0f;
        _sprite_ncurses = "v";
    }
    if (_movClock.get_time() > 100.0)
    {
        if (_map_carac[_pos[1] + _mov[1]][_pos[0] + _mov[0]] != '1' &&
            _map_carac[_pos[1] + _mov[1]][_pos[0] + _mov[0]] != '9')
        {
            _pos[0] += _mov[0];
            _pos[1] += _mov[1];
        }
        if ((int)_pos[0] == (int)(_map_carac.front()).size())
            _pos[0] = 0;
        if ((int)_pos[0] == -1)
            _pos[0] = (_map_carac.front()).size() - 1;
        _movClock.start();
    }
    check_bonus(bonus);
    return (_map_carac);
}

int pac::getScore() const
{
    return (_score);
}

void pac::destroy_sprite()
{
    sf::Sprite sp;
    _sprite_sfml = sp;
}
