/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapata <mzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:52:59 by mzapata           #+#    #+#             */
/*   Updated: 2015/01/11 20:53:40 by mzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#define ENEMY_NUMBER 40

#include <iostream>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

class   GameState
{
    public:
        GameState(void);
        ~GameState();

        Player const &  getPlayer(void) const;
        Enemy const &   getEnemy(int const & n) const;
        Bullet const &  getBullet(void) const;
        int             getX(void) const;
        int             getY(void) const;
        bool            refresh();

        GameState &     operator=(GameState const & rhs);

    protected:

    private:
        bool    haswon(void) const;
        void    printGame(void);
        void    resetEnemies(void);
        void    resetPlayer(void);
        void    refreshGame(wchar_t c);
        void    refreshPause(wchar_t c);
        void    refreshEnd(wchar_t c);
        int     _state; // 0 = game, 1 = win, 2 = lose (,3 = pause ?)
        Enemy   *_enemies;
        Player  _player;
        Bullet  _bullet;
        int     _x;
        int     _y;
};

std::ostream & operator<<(std::ostream & o, GameState const & i);

#endif //  GAMESTATE_HPP
