/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <ctime>
#include <chrono>

class Clock
{
  public:
    Clock();
    ~Clock();

    void start();
    double pause();
    void resume();
    double get_time();
  protected:
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
    int _paused;
    double _time;

};

#endif /* !CLOCK_HPP_ */
