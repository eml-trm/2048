/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:13:15 by emtermea          #+#    #+#             */
/*   Updated: 2015/03/01 01:13:17 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_empty_down(t_tab *e, int x, int y, int t)
{
	if (e->grid[x][y] == 0)
	{
		while (y - t >= 0)
		{
			if (e->grid[x][y - t] != 0)
			{
				e->has_move = 1;
				e->grid[x][y] = e->grid[x][y - t];
				e->grid[x][y - t] = 0;
				break ;
			}
			t++;
		}
	}
}

static void	ft_full_down(t_tab *e, int x, int y, int t)
{
	if (e->grid[x][y] != 0)
	{
		while (y - t >= 0)
		{
			if (e->grid[x][y - t] == 0)
			{
				t++;
				continue ;
			}
			else if (e->grid[x][y - t] != 0)
			{
				if (e->grid[x][y] == e->grid[x][y - t])
				{
					e->grid[x][y] += e->grid[x][y - t];
					e->grid[x][y - t] = 0;
					e->has_move = 1;
				}
				break ;
			}
			t++;
		}
	}
}

void		move_down(t_tab *e)
{
	int	x;
	int	y;
	int	t;

	x = 0;
	e->has_move = 0;
	while (x <= 3)
	{
		y = 3;
		t = 1;
		while (y >= 0)
		{
			ft_empty_down(e, x, y, t);
			ft_full_down(e, x, y, t);
			y--;
		}
		x++;
	}
}
