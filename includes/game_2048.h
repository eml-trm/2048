/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:22:41 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/01 17:51:22 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft.h"
# define CASE_Y (LINES / 4)
# define CASE_X (COLS / 4)
# define CASE_Y_2 (LINES / 2)
# define CASE_X_2 (COLS / 2)

enum			e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_tab
{
	int			grid[4][4];
	int			has_move;
	int			over;
	int			wait;
	int			key;
}				t_tab;

int				exec_menu(t_tab *env);
void			ft_print_retry(void);
void			ft_print_enter(void);
void			ft_print_quit(void);
void			ft_init_color(void);
int				check_full_tab(t_tab *env);
int				ft_game_over(t_tab *env);
int				check_win(t_tab *env);
int				key_win(t_tab *e);
void			init_game(t_tab *e);
void			ft_print_grid(void);
void			print_tableau(t_tab *e);
void			new_rand(t_tab *e);
void			move_right(t_tab *e);
void			move_left(t_tab *e);
void			move_up(t_tab *e);
void			move_down(t_tab *e);

#endif
