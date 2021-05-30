/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Clock
*/

#include <iostream>

#include "./include/Clock.hpp"

Clock::Clock()
{
    _time = 0;
    _start = std::chrono::high_resolution_clock::now();
    _paused ^= _paused;
}

Clock::~Clock()
{
}


void Clock::start()
{
    _time = 0;
    _paused ^= _paused;
    _start = std::chrono::high_resolution_clock::now();
}

double Clock::pause()
{
    _time += std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - _start).count();
    _paused = 1;
    return (_time);
}

void Clock::resume()
{
    _start = std::chrono::high_resolution_clock::now();;
    _paused ^= _paused;
}

double Clock::get_time()
{
    if (_paused != 0) {
        return (_time);
    }
    else {
        _time += std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - _start).count();
        _start = std::chrono::high_resolution_clock::now();
    }
    return (_time);
}