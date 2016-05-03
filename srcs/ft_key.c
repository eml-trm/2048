/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:52:58 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/01 16:53:02 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "game_2048.h"

static void	check_key(t_tab *e, int key)
{
	e->has_move = 0;
	if (key == KEY_UP)
		move_up(e);
	if (key == KEY_DOWN)
		move_down(e);
	if (key == KEY_LEFT)
		move_left(e);
	if (key == KEY_RIGHT)
		move_right(e);
	if (e->has_move == 1)
		new_rand(e);
	print_tableau(e);
}

int			key_win(t_tab *e)
{
	e->has_move = 0;
	e->wait = 1;
	clear();
	ft_print_grid();
	check_key(e, e->key);
	if (ft_game_over(e) == 1)
		return (1);
	if (ft_game_over(e) == 2)
	{
		attron(COLOR_PAIR(2));
		mvprintw(CASE_Y_2, CASE_X_2 - 2, "You Win");
		attroff(COLOR_PAIR(2));
	}
	refresh();
	return (0);
}
