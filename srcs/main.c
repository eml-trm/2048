/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:00:09 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/28 03:15:24 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include "game_2048.h"

int			main(void)
{
	t_tab	e;

	if (WIN_VALUE < 2 || (WIN_VALUE % 2))
	{
		ft_putstr_fd("INCORRECT WIN_VALUE\n", 2);
		exit(0);
	}
	init_game(&e);
	exec_menu(&e);
	endwin();
	if (e.over == 1)
		ft_print_magenta("You lose!");
	return (0);
}
