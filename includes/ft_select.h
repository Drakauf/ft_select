/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 18:35:34 by shthevak    ###    #+. /#+    ###.fr     */
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

#endif
