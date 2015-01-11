/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:45:41 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 03:29:27 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "Entity.hpp"

class   Player: public Entity
{
    public:
        Player(void);
        Player(Player const & e);
        Player(int const & x, int const & y);
        ~Player(void);

        void    move(wchar_t const & ch, int const & x);

        Player & operator=(Player const & rhs);
};

std::ostream & operator<<(std::ostream & o, Player const & i);

#endif // PLAYER_HPP
