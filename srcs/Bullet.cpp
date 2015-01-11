/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 02:28:19 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 19:01:18 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(void) : Entity('|', false, 0, 0)
{
}

Bullet::Bullet(Bullet const & p) :
    Entity('|', p.isAlive(), p.getX(), p.getY())
{
}

Bullet::Bullet(int const & x, int const & y) : Entity('|', true, x, y)
{
}

Bullet::~Bullet(void)
{
}

Bullet & Bullet::operator=(Bullet const & rhs)
{
    this->setX(rhs.getX());
    this->setY(rhs.getY());
    this->setIcon(rhs.getIcon());
    this->setAlive(rhs.isAlive());
    return (*this);
}

void    Bullet::move(bool const & is_player, int const & y)
{
    is_player ? this->setY(this->getY() - 1) : this->setY(this->getY() + 1);
    if (this->getY() < 0 || this->getY() > y)
        this->setAlive(false);
}

