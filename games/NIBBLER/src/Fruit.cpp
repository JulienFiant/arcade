/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Fruit
*/

#include "../include/Fruit.hpp"

Fruit::Fruit()
{
    _name_sprite = "./assets/Nibbler/cherry.png";
    _name = "Fruit";
    _sprite_ncurses = "F";
    _pos[0] = 0;
    _pos[1] = 0;
    _score = 50;
}

Fruit::~Fruit()
{
}

void Fruit::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
}

sf::Sprite Fruit::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void Fruit::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string Fruit::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void Fruit::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string Fruit::getNameSprite() const
{
    return (_name_sprite);
}

int Fruit::getColorChar() const
{
    return (4);
}

void Fruit::setName(std::string name)
{
    _name = name;
}

std::string Fruit::getName() const
{
    return (_name);
}

void Fruit::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *Fruit::getPos() const
{
    return (_pos);
}

void Fruit::setScore(int score)
{
    _score = score;
}

int Fruit::getScore() const
{
    return (_score);
}
