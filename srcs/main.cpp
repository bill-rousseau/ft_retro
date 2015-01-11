/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:27:00 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/10 23:40:36 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameState.hpp"

#include <ncurses.h>
#include <curses.h>

int     main(void)
{
    GameState   g;
    
     //std::cout << g.getX() << std::endl;

     while (g.refresh())
     {
     	//printw("TEST");
     }
    return (0);
}
