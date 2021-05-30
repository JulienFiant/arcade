/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ncurses
*/

#include "../include/Ncurses.hpp"
#include <unistd.h>

Ncurses::Ncurses()
{
    _pac = "O";
    _score = 0;
}

Ncurses::~Ncurses()
{
    endwin();
}

std::string Ncurses::menu(std::vector<std::string> list_games)
{
    int idx = 0;
    int ch = 0;

    if (list_games.empty())
        return ("");

    InitWindow();

    while (42)
    {
        ch = getch();
        usleep(8000);

        switch (ch)
        {
        case 27:
            return ("");
        case 10:
            return (list_games[idx]);
        case KEY_UP:
        {
            idx -= 1;
            if (idx < 0)
                idx = list_games.size() - 1;
            break;
        }
        case KEY_DOWN:
        {
            idx += 1;
            if (idx > (int)list_games.size() - 1)
                idx = 0;
            break;
        }
        }
        erase();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
        init_pair(2, COLOR_WHITE, COLOR_CYAN);
        attron(COLOR_PAIR(2));
        if (idx - 1 < 0)
            mvprintw(2, 2, "");
        else
            mvprintw(2, 2, list_games[idx - 1].c_str());
        if (idx + 1 >= (int)list_games.size())
            mvprintw(6, 2, "");
        else
            mvprintw(6, 2, list_games[idx + 1].c_str());
        attron(COLOR_PAIR(1));
        mvprintw(4, 3, list_games[idx].c_str());
        refresh();
    }
    return (list_games[idx]);
}

void Ncurses::InitWindow()
{
    initscr();
    start_color();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    timeout(0);
    curs_set(0);
}

void Ncurses::getevent(Event &evt)
{
    int ch;

    evt._evtType = Event::NONE;
    ch = getch();
    usleep(80);
    switch (ch)
    {
    case 113: //KEY_LEFT:
        evt._evtType = Event::Q;
        break;
    case 100: //KEY_RIGHT:
        evt._evtType = Event::D;
        break;
    case 122: //KEY_UP:
        evt._evtType = Event::Z;
        break;
    case 115: //KEY_DOWN:
        evt._evtType = Event::S;
        break;
    case 107:
        evt._evtType = Event::K;
        break;
    case 108:
        evt._evtType = Event::L;
        break;
    case 109:
        evt._evtType = Event::M;
        break;
    case 112:
        evt._evtType = Event::O;
        break;
    case 114:
        evt._evtType = Event::R;
        break;
    case 27:
        evt._evtType = Event::EXIT;
        break;
    case 10:
        evt._evtType = Event::ENTER;
        break;
    case 32:
        evt._evtType = Event::SPACE;
    default:
        evt._evtType = evt._evtType;
    }
}

void Ncurses::display_all()
{
    std::string score = std::to_string(_player.front()->getScore());
    erase();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvprintw(0, 60, "SCORE : ");
    mvprintw(0, 68, score.c_str()); //score
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    for (IObject *sp : _obj_map)
    {
        mvprintw(sp->getPos()[1], sp->getPos()[0], sp->getSpriteNCURSES().c_str());
    }
    init_pair(100, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(100));
    for (IObject *sp : _bonus)
    {
        mvprintw(sp->getPos()[1], sp->getPos()[0], sp->getSpriteNCURSES().c_str());
    }
    init_pair(5, COLOR_WHITE, COLOR_RED);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_WHITE, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_YELLOW);

    size_t i = 5;
    for (IEntity *sp : _enemies)
    {
        attron(COLOR_PAIR(i));
        i++;
        mvprintw(sp->getPos()[1], sp->getPos()[0], sp->getSpriteNCURSES().c_str());
    }
    attron(COLOR_PAIR(2));
    for (IEntity *sp : _player)
    {
        mvprintw(sp->getPos()[1], sp->getPos()[0], sp->getSpriteNCURSES().c_str());
    }
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvprintw(_player.back()->getPos()[1], _player.back()->getPos()[0], _pac.c_str()); //pacman
    attroff(COLOR_PAIR(2));
    refresh();
}

int Ncurses::getScore() const
{
    return (0);
}

int Ncurses::game_over()
{
    return (0);
}

void Ncurses::init_map()
{
}

void Ncurses::set_player(std::vector<IEntity *> &player)
{
    _player = player;
}

void Ncurses::set_enemy(std::vector<IEntity *> &enemies)
{
    _enemies = enemies;
}

void Ncurses::set_bonus(std::vector<IObject *> &bonus)
{
    _bonus = bonus;
}

std::vector<std::string> Ncurses::getMapN()
{
    return (_map);
}

sf::Sprite set_sprite(int x, int y, std::string src_path)
{
    sf::Sprite sp;
    return (sp);
}

void Ncurses::set_map(std::vector<IObject *> &map)
{
    size_t i = 0;

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (size_t y = 0; y != _map.size(); y++)
    {
        for (size_t x = 0; _map[y][x]; x++)
        {
            if (_map[y][x] == '.')
            {
                init_pair(9, COLOR_WHITE, COLOR_BLACK);
                attron(COLOR_PAIR(9));
                mvprintw(y, x, &_map[y][x]);
            }
            else
            {
                init_pair(1, COLOR_BLUE, COLOR_BLACK);
                attron(COLOR_PAIR(1));
                mvprintw(y, x, &_map[y][x]);
            }
            i++;
        }
    }
    attroff(COLOR_PAIR(1));
    _obj_map = map;
}

void Ncurses::create_map(std::vector<std::string> src_map)
{
    std::vector<std::string> tmp = src_map;

    for (size_t y = 0; y != tmp.size(); y++)
        for (size_t x = 0; tmp[y][x]; x++)
        {
            if (tmp[y][x] == '1')
            {
                tmp[y][x] = '#';
            }
            else if (tmp[y][x] == '2')
            {
                tmp[y][x] = 'o';
            }
            else if (tmp[y][x] == '9')
            {
                tmp[y][x] = ' ';
            }
        }
    _map = tmp;
    _map_raw = src_map;
}

extern "C" IDisplayModule *create()
{
    return new Ncurses;
}
extern "C" void destroy(IDisplayModule *p)
{
    delete p;
}

__attribute__((constructor)) void init()
{
}

__attribute__((destructor)) void stop()
{
}