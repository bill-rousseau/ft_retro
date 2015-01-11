/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:35:35 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 21:04:18 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameState.hpp"
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <iostream>
#include <ctime>

GameState::GameState(void) : _state(0), _x(20), _y(20)
{
    initscr();
    clear();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    this->resetEnemies();
    this->resetPlayer();
    this->_bullet = Bullet();
}

GameState::~GameState()
{
    delete [] this->_enemies;
    endwin();
}

Player const &  GameState::getPlayer(void) const
{
    return (this->_player);
}

Bullet const &  GameState::getBullet(void) const
{
    return (this->_bullet);
}

int             GameState::getX() const
{
    return (this->_x);
}

int             GameState::getY() const
{
    return (this->_y);
}

bool            GameState::refresh(void)
{
    int i = 0;
    wchar_t    c = getch();
    while (i++ < 200)
    {
    if (c == 113 || c == 81) //q or Q
        return (false);
        clear();
        if (this->_state == 0)
            this->printGame();
        usleep(15);
    }
    if (this->_state == 0)
        this->refreshGame(c);
    else if (this->_state == 1 || this->_state == 2)
        this->refreshEnd(c);
    else
        this->refreshPause(c);
    refresh();
    return (true);
}

void    GameState::printGame(void)
{
    mvaddch(this->_player.getY(), this->_player.getX(), this->_player.getIcon());
    if (this->_bullet.isAlive())
        mvaddch(this->_bullet.getY(), this->_bullet.getX(),
                this->_bullet.getIcon());
    for (int i = 0; i < ENEMY_NUMBER; i++)
    {
        if (this->_enemies[i].isAlive())
            mvaddch(this->_enemies[i].getY(), this->_enemies[i].getX(),
                    this->_enemies[i].getIcon());
    }
}

void    GameState::refreshGame(wchar_t c)
{
    static int  enemy_delay = 0;

    if (c == 112 || c == 80) // p or P
    {
        this->_state = 3;
        return;
    }
    this->_player.move(c, this->getX());
    if (c == ' ' && !this->_bullet.isAlive())
        this->_bullet = Bullet(this->_player.getX(), this->_player.getY() - 1);
    for (int i = 0; i < ENEMY_NUMBER; i++)
    {
        if (this->_bullet.getX() == this->_enemies[i].getX()
                && this->_bullet.getY() == this->_enemies[i].getY()
                && this->_enemies[i].isAlive())
        {
            this->_enemies[i].setAlive(false);
            this->_bullet.setAlive(false);
        }
    }
    if (this->_bullet.isAlive())
        this->_bullet.move(true, this->getY());
    enemy_delay++;
    if (enemy_delay > 60)
        for (int i = 0; i < ENEMY_NUMBER; i++)
        {
            this->_enemies[i].move(this->getX());
            if (this->_enemies[i].getY() > this->getY() - 3)
                this->_state = 2;
            enemy_delay = 0;
        }
    if (this->haswon())
        this->_state = 1;
}

bool    GameState::haswon(void) const
{
    int cnt = 0;
    for (int i = 0; i < ENEMY_NUMBER; i++)
        if (!this->_enemies[i].isAlive())
            cnt++;
    if (cnt == ENEMY_NUMBER)
        return true;
    return false;
}

void    GameState::refreshPause(wchar_t c)
{
    if (c == 112 || c == 80)
    {
        this->_state = 0;
        this->refreshGame(0);
        return;
    }
    else
        printw(" GAME PAUSED ");
}

void    GameState::refreshEnd(wchar_t c)
{
    if (c == 114 || c == 82) // R or r
    {
        delete [] this->_enemies;
        this->resetEnemies();
        this->resetPlayer();
        this->_state = 0;
    }
    if (this->_state == 1)
        printw(" YOU WON. PRESS R TO RESTART. ");
    if (this->_state == 2)
        printw(" YOU LOST. PRESS R TO RESTART. ");
}

void    GameState::resetEnemies(void)
{
    int     count = 0;
    int     x = 0;
    int     y = 0;
    this->_enemies = new Enemy[ENEMY_NUMBER];
    while (count < ENEMY_NUMBER && y < this->_y - 3)
    {
        if (y % 2 == 0 && count < ENEMY_NUMBER)
        {
            while (x + 1 <= this->_x)
            {
                this->_enemies[count] = Enemy(x, y);
                count++;
                x += 2;
            }
        }
        else
        {
            while (x - 1 >= 0 && count < ENEMY_NUMBER)
            {
                this->_enemies[count] = Enemy(x, y);
                count++;
                x -= 2;
            }
        }
        if (count < ENEMY_NUMBER)
            this->_enemies[count] = Enemy(x, y);
        y++;
    }
}

void    GameState::resetPlayer(void)
{
    this->_player = Player(this->getX() / 2, this->getY() - 1);
}
