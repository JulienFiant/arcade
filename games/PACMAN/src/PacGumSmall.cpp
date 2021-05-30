/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacGumSmall
*/

#include "../include/PacGumSmall.hpp"

PacGumSmall::PacGumSmall()
{
    _name_sprite = "./assets/Pacman/pacgum_Small.png";
    _name = "PacGumSmall";
    _sprite_ncurses = ".";
    _pos[0] = 0;
    _pos[1] = 0;
    _score = 10;
}

PacGumSmall::~PacGumSmall()
{
}

void PacGumSmall::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
}

sf::Sprite PacGumSmall::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void PacGumSmall::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string PacGumSmall::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void PacGumSmall::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string PacGumSmall::getNameSprite() const
{
    return (_name_sprite);
}

int PacGumSmall::getColorChar() const
{
    return (4);
}

void PacGumSmall::setName(std::string name)
{
    _name = name;
}

std::string PacGumSmall::getName() const
{
    return (_name);
}

void PacGumSmall::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *PacGumSmall::getPos() const
{
    return (_pos);
}

void PacGumSmall::setScore(int score)
{
    _score = score;
}

int PacGumSmall::getScore() const
{
    return (_score);
}
