/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:55:52 by emtermea          #+#    #+#             */
/*   Updated: 2015/03/01 00:55:54 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_empty_up(t_tab *e, int x, int y, int t)
{
	if (e->grid[x][y] == 0)
	{
		while (y + t <= 3)
		{
			if (e->grid[x][y + t] != 0)
			{
				e->has_move = 1;
				e->grid[x][y] = e->grid[x][y + t];
				e->grid[x][y + t] = 0;
				break ;
			}
			t++;
		}
	}
}

static void	ft_full_up(t_tab *e, int x, int y, int t)
{
	if (e->grid[x][y] != 0)
	{
		while (y + t <= 3)
		{
			if (e->grid[x][y + t] == 0)
			{
				t++;
				continue ;
			}
			else if (e->grid[x][y + t] != 0)
			{
				if (e->grid[x][y] == e->grid[x][y + t])
				{
					e->grid[x][y] += e->grid[x][y + t];
					e->grid[x][y + t] = 0;
					e->has_move = 1;
				}
				break ;
			}
			t++;
		}
	}
}

void		move_up(t_tab *e)
{
	int	x;
	int	y;
	int	t;

	x = 0;
	e->has_move = 0;
	while (x <= 3)
	{
		y = 0;
		t = 1;
		while (y <= 3)
		{
			ft_empty_up(e, x, y, t);
			ft_full_up(e, x, y, t);
			y++;
		}
		x++;
	}
}
