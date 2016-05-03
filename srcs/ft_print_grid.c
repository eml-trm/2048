/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:32:56 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/28 03:15:47 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "game_2048.h"

static void color_cols(int x, int y)
{
	ft_init_color();
	attron(COLOR_PAIR(1));
	mvprintw(y, x, "-");
	attroff(COLOR_PAIR(1));
}

static void	color_line(int x, int y)
{
	ft_init_color();
	attron(COLOR_PAIR(1));
	mvprintw(y, x, "|");
	attroff(COLOR_PAIR(1));
}

static void	ft_print_line(int max_cols, int max_line, int x, int y)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (a <= 4)
	{
		while (i < 4)
		{
			while (y < max_line)
			{
				color_line(x, y);
				y++;
			}
			max_line += (LINES / 4);
			color_line(x, y++);
			i++;
		}
		i = 0;
		y = 0;
		x += max_cols;
		max_line = (LINES / 4);
		a++;
	}
}

static void	ft_print_cols(int max_cols, int max_line, int x, int y)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (a <= 4)
	{
		while (i < 4)
		{
			while (x < max_cols)
			{
				color_cols(x, y);
				x++;
			}
			max_cols += (COLS / 4);
			color_cols(x++, y);
			i++;
		}
		i = 0;
		x = 1;
		y += max_line;
		max_cols = (COLS / 4);
		a++;
	}
}

void		ft_print_grid(void)
{
	int	max_line;
	int	max_cols;

	max_line = (LINES / 4);
	max_cols = (COLS / 4);
	ft_print_cols(max_cols, max_line, 1, 0);
	ft_print_line(max_cols, max_line, 1, 0);
}
