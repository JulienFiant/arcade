/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacGumSpecial
*/

#include "../include/PacGumSpecial.hpp"

PacGumSpecial::PacGumSpecial()
{
    _name_sprite = "./assets/Pacman/pacgum_Special.png";
    _name = "PacGumSpecial";
    _sprite_ncurses = "@";
    _pos[0] = 0;
    _pos[1] = 0;
    _score = 100;
}

PacGumSpecial::~PacGumSpecial()
{
}

void PacGumSpecial::setSpriteSFML(sf::Sprite sprite)
{
    _sprite_sfml = sprite;
}

sf::Sprite PacGumSpecial::getSpriteSFML() const
{
    return (_sprite_sfml);
}

void PacGumSpecial::setSpriteNCURSES(std::string sprite)
{
    _sprite_ncurses = sprite;
}

std::string PacGumSpecial::getSpriteNCURSES() const
{
    return (_sprite_ncurses);
}

void PacGumSpecial::setNameSprite(std::string name_sprite)
{
    _name_sprite = name_sprite;
}

std::string PacGumSpecial::getNameSprite() const
{
    return (_name_sprite);
}

int PacGumSpecial::getColorChar() const
{
    return (4);
}

void PacGumSpecial::setName(std::string name)
{
    _name = name;
}

std::string PacGumSpecial::getName() const
{
    return (_name);
}

void PacGumSpecial::setPos(float *pos)
{
    _pos[0] = pos[0];
    _pos[1] = pos[1];
}

const float *PacGumSpecial::getPos() const
{
    return (_pos);
}

void PacGumSpecial::setScore(int score)
{
    _score = score;
}

int PacGumSpecial::getScore() const
{
    return (_score);
}
