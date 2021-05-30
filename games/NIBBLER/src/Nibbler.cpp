/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include "../include/Nibbler.hpp"
#include <fstream>
#include <iostream>

Nibbler::Nibbler()
{
    _score = 0;
}

Nibbler::~Nibbler()
{
}

void Nibbler::init_all()
{
    std::fstream fd;
    std::string tmp;
    float pos[2] = {0.0, 0.0};

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLUE);
    init_pair(6, COLOR_WHITE, COLOR_RED);
    init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(8, COLOR_WHITE, COLOR_CYAN);
    init_pair(9, COLOR_WHITE, COLOR_YELLOW);

    fd.open("assets/Nibbler/map.txt");
    while (getline(fd, tmp))
    {
        _strMap.push_back(tmp);
        for (char c : tmp)
        {
            if (c == '1')
            {
                _map.push_back(new Wall);
                _map.back()->setPos(pos);
            }
            if (c == '3')
            {
                _bonus.push_back(new Fruit);
                _bonus.back()->setPos(pos);
            }
            if (c == '9')
            {
                _map.push_back(new Wall);
                _map.back()->setPos(pos);
            }
            pos[0] += 1.0;
        }
        pos[0] = 0.0;
        pos[1] += 1.0;
    }
    pos[0] = 13.0;
    pos[1] = 14.0;
    fd.close();
    _player.push_back(new Head);
    _player.back()->setPos(pos);
    pos[0] += 1;
    _player.push_back(new Tail);
    _player.back()->setPos(pos);
    pos[0] += 1;
    _player.push_back(new Tail);
    _player.back()->setPos(pos);
    pos[0] += 1;
    _player.push_back(new Tail);
    _player.back()->setPos(pos);
}

std::vector<IObject *> &Nibbler::getMap()
{
    return (_map);
}

void Nibbler::getevent(Event &evt)
{
    float lastpos[2] = {0.0f, 0.0f};
    float firstpos[2] = {0.0f, 0.0f};

    firstpos[0] = _player.front()->getPos()[0];
    firstpos[1] = _player.front()->getPos()[1];

    _player.front()->move(evt, _strMap, _bonus);

    if (firstpos[0] != _player.front()->getPos()[0] || firstpos[1] != _player.front()->getPos()[1])
        for (size_t i = 1; i < _player.size(); ++i)
        {
            lastpos[0] = _player[i]->getPos()[0];
            lastpos[1] = _player[i]->getPos()[1];
            _player[i]->setPos(firstpos);
            firstpos[0] = lastpos[0];
            firstpos[1] = lastpos[1];
        }
    if (_player.front()->getBonus() == 1)
    {
        _player.push_back(new Tail);
        _player.back()->setPos(firstpos);
        _player.front()->setBonus(0);
    }
}

void Nibbler::play()
{
}

bool Nibbler::game_over()
{
    for (size_t i = 1; i < _player.size(); ++i)
    {
        if (EQ_F(_player[0]->getPos()[0], _player[i]->getPos()[0], 0.001) &&
            EQ_F(_player[0]->getPos()[1], _player[i]->getPos()[1], 0.001))
        {
            std::cout << "u bite yourself and it hurts like hell" << std::endl;
            return (true);
        }
    }
    if (_strMap[_player[0]->getPos()[1]][_player[0]->getPos()[0]] == '9')
    {
        std::cout << "u NOOB u fell out'a the map" << std::endl;
        return (true);
    }
    if (_bonus.empty())
    {
        std::cout << "u ate the fruits" << std::endl;
        return (true);
    }
    return (false);
}

int Nibbler::getScore() const
{
    return (_score);
}

void Nibbler::setScore(int score)
{
    _score = score;
}

std::vector<IEntity *> &Nibbler::getPlayer()
{
    return (_player);
}

std::vector<IObject *> &Nibbler::getBonus()
{
    return (_bonus);
}

std::vector<IEntity *> &Nibbler::getEnemies()
{
    return (_enemies);
}

void Nibbler::destroy_sprite()
{
    for (IEntity *sp : _player)
    {
        if (sp->getSpriteSFML().getTexture())
            sp->destroy_sprite();
    }
    for (IEntity *sp : _enemies)
    {
        if (sp->getSpriteSFML().getTexture())
            sp->destroy_sprite();
    }
}

extern "C" IGameModule *create()
{
    return new Nibbler;
}
extern "C" void destroy(IGameModule *p)
{
    delete p;
}

__attribute__((constructor)) void init()
{
}

__attribute__((destructor)) void stop()
{
}
