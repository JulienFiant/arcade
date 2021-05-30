/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Tail
*/

#include <iostream>
#include "../include/Tail.hpp"

Tail::Tail()
{
    _name_sprite = "./assets/Nibbler/Tail_neutral.png";
    _name = "Tail";
    _tileSize = 16;
    _mapStartX = 1;
    _mapStartY = 2;
    _score = 0;
    _bonus = 0;
    _sprite_ncurses = "o";
    _SFMLSetup = false;
    _movClock.start();
}

Tail::~Tail()
{
}

void Tail::setBonus(int bonus)
{
    _bonus = bonus;
}

int Tail::getBonus()
{
    return (_bonus);
}

void Tail::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
    _SFMLSetup = true;
}

sf::Sprite Tail::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void Tail::changePosSpriteSFML(float x, float y)
{
    _sprite_sfml.setPosition(x, y);
}

void Tail::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string Tail::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void Tail::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string Tail::getNameSprite() const
{
    return (_name_sprite);
}

int Tail::getColorChar() const
{
    return (3);
}

void Tail::setName(std::string name)
{
    _name = name;
}

std::string Tail::getName() const
{
    return (_name);
}

void Tail::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *Tail::getPos() const
{
    return (_pos);
}

void Tail::check_bonus(std::vector<IObject *> &bonus)
{
}

std::vector<std::string> Tail::move(Event &evt, std::vector<std::string> _map_carac, std::vector<IObject *> &bonus)
{
    return (_map_carac);
}

int Tail::getScore() const
{
    return (_score);
}

void Tail::destroy_sprite()
{
    sf::Sprite sp;
    _sprite_sfml = sp;
}
