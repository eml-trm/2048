/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:36:03 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/01 13:36:05 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "game_2048.h"

int		check_win(t_tab *env)
{
	int x;
	int y;

	x = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			if (env->grid[x][y] == WIN_VALUE)
			{
				return (1);
			}
			else
				y++;
		}
		x++;
	}
	return (0);
}

int		check_full_tab(t_tab *env)
{
	int x;
	int y;

	x = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			if (env->grid[x][y] == 0)
				return (1);
			else
				y++;
		}
		x++;
	}
	return (0);
}

int		ft_game_over(t_tab *env)
{
	int	full;
	int	end;

	end = check_win(env);
	full = check_full_tab(env);
	if (full == 0 && env->has_move == 0)
		return (1);
	if (end == 1)
		return (2);
	return (0);
}
