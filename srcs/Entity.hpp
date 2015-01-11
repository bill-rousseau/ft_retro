/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:41 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 20:24:11 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>

class   Entity
{
    public:
        Entity(void);
        Entity(Entity const & e);
        Entity(char icon, bool alive, int x, int y);
        ~Entity(void);

        char    getIcon(void) const;
        bool    isAlive(void) const;
        int     getX(void) const;
        int     getY(void) const;
        void    setAlive(bool b);

        Entity & operator=(Entity const & rhs);

    protected:
        void    setIcon(char c);
        void    setX(int n);
        void    setY(int n);

    private:
        char    _icon;
        bool    _alive;
        int     _x;
        int     _y;
};

std::ostream & operator<<(std::ostream & o, Entity const & i);

#endif // ENTITY_HPP
