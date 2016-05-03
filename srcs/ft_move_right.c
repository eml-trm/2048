/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:01:24 by emtermea          #+#    #+#             */
/*   Updated: 2015/02/28 12:01:26 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_empty_right(t_tab *e, int x, int y, int t)
{
	if (e->grid[x][y] == 0)
	{
		while (x - t >= 0)
		{
			if (e->grid[x - t][y] != 0)
			{
				e->has_move = 1;
				e->grid[x][y] = e->grid[x - t][y];
				e->grid[x - t][y] = 0;
				break ;
			}
			t++;
		}
	}
}

static void	ft_full_right(t_tab *e, int x, int y, int t)
{
	if (e->grid[x][y] != 0)
	{
		while (x - t >= 0)
		{
			if (e->grid[x - t][y] == 0)
			{
				t++;
				continue ;
			}
			else if (e->grid[x - t][y] != 0)
			{
				if (e->grid[x][y] == e->grid[x - t][y])
				{
					e->grid[x][y] += e->grid[x - t][y];
					e->grid[x - t][y] = 0;
					e->has_move = 1;
				}
				break ;
			}
			t++;
		}
	}
}

void		move_right(t_tab *e)
{
	int	x;
	int	y;
	int	t;

	y = 0;
	e->has_move = 0;
	while (y <= 3)
	{
		x = 3;
		t = 1;
		while (x >= 0)
		{
			ft_empty_right(e, x, y, t);
			ft_full_right(e, x, y, t);
			x--;
		}
		y++;
	}
}
