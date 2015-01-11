/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:41 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 03:03:12 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

#include <iostream>

#include "Entity.hpp"

class   Bullet: public Entity
{
    public:
        Bullet(void);
        Bullet(Bullet const & e);
        Bullet(int const & x, int const & y);
        ~Bullet(void);

        void    move(bool const & is_player, int const & y);

        Bullet & operator=(Bullet const & rhs);
};

std::ostream & operator<<(std::ostream & o, Bullet const & i);

#endif // BULLET_HPP
