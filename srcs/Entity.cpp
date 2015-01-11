/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:26 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 03:42:15 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"


Entity::Entity(void) :
    _icon('x'), _alive(true), _x(0), _y(0)
{
}

Entity::Entity(Entity const & e) :
    _icon(e.getIcon()), _alive(e.isAlive()), _x(e.getX()), _y(e.getY())
{
}

Entity::Entity(char icon, bool alive, int x, int y) :
    _icon(icon), _alive(alive), _x(x), _y(y)
{
}

Entity::~Entity(void)
{
}

char    Entity::getIcon(void) const
{
    return (this->_icon);
}

bool    Entity::isAlive(void) const
{
    return (this->_alive);
}

int     Entity::getX(void) const
{
    return (this->_x);
}

int     Entity::getY(void) const
{
    return (this->_y);
}

void    Entity::setIcon(char c)
{
    this->_icon = c;
}

void    Entity::setX(int n)
{
    this->_x = n;
}

void    Entity::setY(int n)
{
    this->_y = n;
}

void    Entity::setAlive(bool b)
{
    this->_alive = b;
}
