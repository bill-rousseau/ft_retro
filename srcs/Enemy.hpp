/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:41 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 03:08:19 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

#include "Entity.hpp"

class   Enemy: public Entity
{
    public:
        Enemy(void);
        Enemy(Enemy const & e);
        Enemy(int const & x, int const & y);
        ~Enemy(void);

        void    move(int const & x);

        Enemy & operator=(Enemy const & rhs);
};

std::ostream & operator<<(std::ostream & o, Enemy const & i);

#endif // ENEMY_HPP
