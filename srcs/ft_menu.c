/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:12:06 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/01 19:12:07 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <curses.h>
#include "game_2048.h"

void	ft_print_quit(void)
{
	ft_init_color();
	attron(COLOR_PAIR(13));
	mvprintw((CASE_Y_2 + 1), (CASE_X_2 - 9), "***************");
	mvprintw((CASE_Y_2 + 2), (CASE_X_2 - 9), "* ESC to Quit *");
	mvprintw((CASE_Y_2 + 3), (CASE_X_2 - 9), "***************");
	attroff(COLOR_PAIR(13));
}

void	ft_print_enter(void)
{
	ft_init_color();
	attron(COLOR_PAIR(12));
	mvprintw((CASE_Y_2 - 5), (CASE_X_2 - 10), "*****************");
	mvprintw((CASE_Y_2 - 4), (CASE_X_2 - 10), "* ENTER to Play *");
	mvprintw((CASE_Y_2 - 3), (CASE_X_2 - 10), "*****************");
	attroff(COLOR_PAIR(12));
}

void	ft_print_retry(void)
{
	ft_init_color();
	attron(COLOR_PAIR(14));
	mvprintw((CASE_Y_2 - 2), (CASE_X_2 - 11), "*******************");
	mvprintw((CASE_Y_2 - 1), (CASE_X_2 - 11), "* DELETE to Retry *");
	mvprintw((CASE_Y_2), (CASE_X_2 - 11), "*******************");
	attroff(COLOR_PAIR(14));
}

int		exec_menu(t_tab *e)
{
	while ((e->key = getch()))
	{
		if ((!(e->key == 10 || e->key == KEY_DC
			|| e->key == 27)) && e->wait == 0)
			continue ;
		if (e->key == KEY_DC)
			init_game(e);
		else if (e->key == 27)
		{
			endwin();
			return (0);
		}
		else
			e->over = key_win(e);
	}
	clear();
	ft_print_enter();
	ft_print_retry();
	ft_print_quit();
	refresh();
	return (e->key);
}
