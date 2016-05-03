/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:12:37 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/28 04:12:38 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include "game_2048.h"

static int	two_or_four(void)
{
	return ((rand() % 8 == 0) ? 4 : 2);
}

static int	rand_pos(int pos)
{
	pos = (rand() % 4);
	return (pos);
}

void		new_rand(t_tab *e)
{
	int x;
	int y;

	x = 1;
	y = 1;
	x = rand_pos(x);
	y = rand_pos(y);
	if (e->grid[x][y] == 0)
	{
		e->grid[x][y] = two_or_four();
		return ;
	}
	while (e->grid[x][y] != 0)
	{
		x = rand_pos(x);
		y = rand_pos(y);
	}
	e->grid[x][y] = two_or_four();
}
