/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 21:06:39 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 19:09:44 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <ncurses.h>

Enemy::Enemy(void) : Entity('M', true, 0, 0)
{
}

Enemy::Enemy(Enemy const & e) : Entity('M', e.isAlive(), e.getX(), e.getY())
{
}

Enemy::Enemy(int const & x, int const & y) : Entity('M', true, x, y)
{
}

Enemy::~Enemy(void)
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
    this->setX(rhs.getX());
    this->setY(rhs.getY());
    this->setIcon(rhs.getIcon());
    this->setAlive(rhs.isAlive());
    return (*this);
}

void    Enemy::move(int const & x)
{
    if (this->getY() % 2)
        this->setX(this->getX() - 1);
    else
        this->setX(this->getX() + 1);
    if (this->getX() == -1)
    {
        this->setX(this->getX() + 1);
        this->setY(this->getY() + 1);
    }
    if (this->getX() == x)
    {
        this->setX(this->getX() - 1);
        this->setY(this->getY() + 1);
    }
}
