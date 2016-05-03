/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:49:49 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/01 16:49:51 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <locale.h>
#include <ncurses.h>
#include <curses.h>
#include "game_2048.h"

void		ft_init_color(void)
{
	init_pair(1, COLOR_BLUE, COLOR_BLUE);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_RED);
	init_pair(8, COLOR_GREEN, COLOR_BLUE);
	init_pair(9, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(10, COLOR_RED, COLOR_CYAN);
	init_pair(11, COLOR_GREEN, COLOR_RED);
	init_pair(12, COLOR_GREEN, COLOR_BLACK);
	init_pair(13, COLOR_RED, COLOR_BLACK);
	init_pair(14, COLOR_YELLOW, COLOR_BLACK);
}

static void	init_struct(t_tab *e)
{
	ft_memset(&e->grid, 0, 16 * (sizeof(int)));
	e->wait = 0;
}

static void	init_ncurse(void)
{
	setlocale(LC_ALL, "");
	ft_init_color();
	initscr();
	curs_set(0);
	noecho();
	getmaxyx(stdscr, LINES, COLS);
	keypad(stdscr, TRUE);
}

void		init_game(t_tab *e)
{
	init_ncurse();
	start_color();
	srand(time(NULL));
	init_struct(e);
	ft_print_enter();
	ft_print_retry();
	ft_print_quit();
	new_rand(e);
	new_rand(e);
}
