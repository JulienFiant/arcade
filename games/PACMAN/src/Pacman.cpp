/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#include "../include/Pacman.hpp"
#include <fstream>

Pacman::Pacman()
{
    _score = 0;
}

Pacman::~Pacman()
{
}

void Pacman::init_all()
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

    fd.open("assets/Pacman/map.txt");
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
                _bonus.push_back(new PacGumSmall);
                _bonus.back()->setPos(pos);
            }
            if (c == '4')
            {
                _bonus.push_back(new PacGumSpecial);
                _bonus.back()->setPos(pos);
            }
            pos[0] += 1.0;
        }
        pos[0] = 0.0;
        pos[1] += 1.0;
    }
    pos[0] = 13.0;
    pos[1] = 24.0;
    fd.close();
    _player.push_back(new pac);
    _player.back()->setPos(pos);
    pos[0] = 12.0;
    pos[1] = 14.0;
    _enemies.push_back(new blinky);
    _enemies.back()->setPos(pos);
    pos[1] += 1.0;
    _enemies.push_back(new clyde);
    _enemies.back()->setPos(pos);
    pos[0] += 2.0;
    _enemies.push_back(new inky);
    _enemies.back()->setPos(pos);
    pos[1] -= 1.0;
    _enemies.push_back(new pinky);
    _enemies.back()->setPos(pos);
}

std::vector<IObject *> &Pacman::getMap()
{
    return (_map);
}

void Pacman::getevent(Event &evt)
{
    for (IEntity *e : _player)
    {
        e->move(evt, _strMap, _bonus);
    }
    for (IEntity *e : _enemies)
    {
        int status = 0;

        for (IEntity *p : _player)
        {
            if (p->getBonus() == 1)
            {
                if ((int)e->getPos()[0] == (int)p->getPos()[0] &&
                    (int)e->getPos()[1] == (int)p->getPos()[1])
                    status = 2;
                status = (status != 2) ? 1 : status;
            }
        }
        e->setBonus(status);
        e->move(evt, _strMap, _bonus);
    }
}

void Pacman::play()
{
}

bool Pacman::game_over()
{

    for (IEntity *enemy : _enemies)
    {
        for (IEntity *player : _player)
        {
            if (EQ_F(enemy->getPos()[0], player->getPos()[0], 0.001) &&
                EQ_F(enemy->getPos()[1], player->getPos()[1], 0.001) && player->getBonus() != 1)
            {
                std::cout << "u got killed" << std::endl;
                return (true);
            }
        }
    }
    if (_bonus.empty())
    {
        std::cout << "u ate the gums" << std::endl;
        return (true);
    }
    return (false);
}

int Pacman::getScore() const
{
    return (_score);
}

void Pacman::setScore(int score)
{
    _score = score;
}

std::vector<IEntity *> &Pacman::getPlayer()
{
    return (_player);
}

std::vector<IObject *> &Pacman::getBonus()
{
    return (_bonus);
}

std::vector<IEntity *> &Pacman::getEnemies()
{
    return (_enemies);
}

void Pacman::destroy_sprite()
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
    return new Pacman;
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
