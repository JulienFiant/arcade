/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Wall
*/

#include "./include/Wall.hpp"

Wall::Wall()
{
    _name_sprite = "./assets/wall.png";
    _sprite_ncurses = "#";
    _name = "Wall";
    _pos[0] = 0;
    _pos[1] = 0;
    _score = 10;
}

Wall::~Wall()
{
}

void Wall::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
}

sf::Sprite Wall::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void Wall::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string Wall::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void Wall::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string Wall::getNameSprite() const
{
    return (_name_sprite);
}

int Wall::getColorChar() const
{
    return (1);
}

void Wall::setName(std::string name)
{
    _name = name;
}

std::string Wall::getName() const
{
    return (_name);
}

void Wall::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *Wall::getPos() const
{
    return (_pos);
}

void Wall::setScore(int score)
{
    _score = score;
}

int Wall::getScore() const
{
    return (_score);
}
