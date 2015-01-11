/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:59:42 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 17:38:37 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <ncurses.h>
#include <curses.h>
#include <iostream>

Player::Player(void) : Entity('@', true, 0, 0)
{
}

Player::Player(Player const & p) :
    Entity(p.getIcon(), p.isAlive(), p.getX(), p.getY())
{
}

Player::Player(int const & x, int const & y) : Entity('@', true, x, y)
{
}

Player &    Player::operator=(Player const & rhs)
{
    this->setX(rhs.getX());
    this->setY(rhs.getY());
    this->setIcon(rhs.getIcon());
    this->setAlive(rhs.isAlive());
    return (*this);
}

Player::~Player(void)
{
}

void    Player::move(wchar_t const & ch, int const & x)
{
    switch (ch)
    {
        case 68: //left
            this->setX(this->getX() - 1);
            break;
        case 67: //right
            this->setX(this->getX() + 1);
            break;
    }
    if (this->getX() == x)
        this->setX(x - 1);
    else if (this->getX() == -1)
        this->setX(0);
}
