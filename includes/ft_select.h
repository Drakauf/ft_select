/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 21:02:23 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>

#include <curses.h>
#include <term.h>

/*
********************************************************************************
**                                                                  Structures *
********************************************************************************
*/

/*
** ft_select
*/

typedef	struct		s_select
{
	char			**args;
	int				*args_stat;
	int				nb_args;
	int				max_arg_len;
	int				cursor;
}					t_select;

/*
********************************************************************************
**                                                                   Fonction  *
********************************************************************************
*/

void			ft_putstr(char *str);
void			ft_putstr_select(char *str);
int				init_term(void);
int				ft_tab_len(char **tableau);
char			*ft_strdup(char *str);
void			ft_strdel(char **str);
t_select		*init_struct(int a, char **ac);
t_select		*get_struct(int a, char **ac);
void			ft_free_tab(char **tableau);
void			ft_free_struct(t_select *select);
char			**init_tableau_args(char **str);
int				*init_tableau_args_stat(int i);
int				ft_strlen(char *str);
#endif
