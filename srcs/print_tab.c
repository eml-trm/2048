/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:10:04 by emtermea          #+#    #+#             */
/*   Updated: 2015/03/01 00:10:06 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "game_2048.h"

static void	ft_color_4(t_tab *e, int j, int x, int y)
{
	int		i;

	i = CASE_Y / 2;
	if (e->grid[x][y] == 2048)
	{
		attron(COLOR_PAIR(11));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(11));
	}
}

static void	ft_color_3(t_tab *e, int j, int x, int y)
{
	int		i;

	i = CASE_Y / 2;
	if (e->grid[x][y] == 256)
	{
		attron(COLOR_PAIR(8));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(8));
	}
	if (e->grid[x][y] == 512)
	{
		attron(COLOR_PAIR(9));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(9));
	}
	if (e->grid[x][y] == 1024)
	{
		attron(COLOR_PAIR(10));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(10));
	}
	ft_color_4(e, j, x, y);
}

static void	ft_color_2(t_tab *e, int j, int x, int y)
{
	int		i;

	i = CASE_Y / 2;
	if (e->grid[x][y] == 32)
	{
		attron(COLOR_PAIR(6));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(6));
	}
	if (e->grid[x][y] == 64)
	{
		attron(COLOR_PAIR(5));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(5));
	}
	if (e->grid[x][y] == 128)
	{
		attron(COLOR_PAIR(7));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(7));
	}
	ft_color_3(e, j, x, y);
}

static void	ft_color(t_tab *e, int j, int x, int y)
{
	int		i;

	i = CASE_Y / 2;
	if (e->grid[x][y] == 2 || e->grid[x][y] > 2048)
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
	if (e->grid[x][y] == 4)
	{
		attron(COLOR_PAIR(2));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(2));
	}
	if (e->grid[x][y] == 8)
	{
		attron(COLOR_PAIR(3));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(3));
	}
	if (e->grid[x][y] == 16)
	{
		attron(COLOR_PAIR(4));
		mvprintw(i + y * CASE_Y, j + x * CASE_X, "%d", e->grid[x][y]);
		attroff(COLOR_PAIR(4));
	}
	ft_color_2(e, j, x, y);
}

void		print_tableau(t_tab *e)
{
	int		x;
	int		y;
	int		j;

	x = 0;
	j = CASE_X / 2;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (e->grid[x][y] != 0)
				ft_color(e, j, x, y);
			y++;
		}
		x++;
	}
}
