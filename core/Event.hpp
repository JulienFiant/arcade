/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

class Event
{
  public:
    enum EventType
    {
        NONE,
        EXIT,
        Z,
        Q,
        S,
        D,
        O,
        K,
        L,
        M,
        R,
        SPACE,
        ESC,
        ENTER
    };
    Event();
    ~Event();
    EventType _evtType;
};

#endif /* !EVENT_HPP_ */
