/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Head
*/

#include <iostream>
#include "../include/Head.hpp"

Head::Head()
{
    _name_sprite = "./assets/Nibbler/Head_neutral.png";
    _name = "Head";
    _tileSize = 16;
    _mapStartX = 1;
    _mapStartY = 2;
    _score = 0;
    _bonus = 0;
    _sprite_ncurses = "O";
    _SFMLSetup = false;
    timer.start();
    _movClock.start();
    _mov[0] = 0.0f;
    _mov[1] = 0.0f;
}

Head::~Head()
{
}

void Head::setBonus(int bonus)
{
    _bonus = bonus;
}

int Head::getBonus()
{
    return (_bonus);
}

void Head::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
    _SFMLSetup = true;
}

sf::Sprite Head::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void Head::changePosSpriteSFML(float x, float y)
{
    _sprite_sfml.setPosition(x, y);
}

void Head::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string Head::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void Head::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string Head::getNameSprite() const
{
    return (_name_sprite);
}

int Head::getColorChar() const
{
    return (3);
}

void Head::setName(std::string name)
{
    _name = name;
}

std::string Head::getName() const
{
    return (_name);
}

void Head::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *Head::getPos() const
{
    return (_pos);
}

void Head::check_bonus(std::vector<IObject *> &bonus)
{
    std::vector<IObject *>::iterator o = bonus.begin();
    for (size_t i = 0; i < bonus.size(); ++i)
    {
        if (EQ_F(_pos[0], bonus[i]->getPos()[0], 0.001) && EQ_F(_pos[1], bonus[i]->getPos()[1], 0.001))
        {
            if (bonus[i]->getName().find("Fruit") == 0)
                _score += bonus[i]->getScore();
            if (bonus[i]->getName() == "Fruit")
            {
                _bonus = 1;
            }
            bonus.erase(o);
        }
        ++o;
    }
}

std::vector<std::string> Head::move(Event &evt, std::vector<std::string> _map_carac, std::vector<IObject *> &bonus)
{
    if (_map_carac[_pos[1]][_pos[0] + 1] != '1' && evt._evtType == Event::D)
    {
        _mov[0] = 1.0f;
        _mov[1] = 0.0f;
    }
    else if (_map_carac[_pos[1]][_pos[0] - 1] != '1' && evt._evtType == Event::Q)
    {
        _mov[0] = -1.0f;
        _mov[1] = 0.0f;
    }
    else if (_map_carac[_pos[1] + 1][_pos[0]] != '1' && evt._evtType == Event::S)
    {
        _mov[0] = 0.0f;
        _mov[1] = 1.0f;
    }
    else if (_map_carac[_pos[1] - 1][_pos[0]] != '1' && evt._evtType == Event::Z)
    {
        _mov[0] = 0.0f;
        _mov[1] = -1.0f;
    }
    if (_movClock.get_time() > 100.0)
    {
        if (_map_carac[_pos[1] + _mov[1]][_pos[0] + _mov[0]] != '1')
        {
            _pos[0] += _mov[0];
            _pos[1] += _mov[1];
        }
        _movClock.start();
    }
    check_bonus(bonus);
    return (_map_carac);
}

int Head::getScore() const
{
    return (_score);
}

void Head::destroy_sprite()
{
    sf::Sprite sp;
    _sprite_sfml = sp;
}
