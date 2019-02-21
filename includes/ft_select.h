/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 17:01:13 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <term.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

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
	int				nb_columns;
	int				cursor_position;
	struct	termios	nterm;
	struct	termios	oterm;
	int				fd;
}					t_select;

# define	SFD		select->fd
# define	SNTERM	select->nterm
# define	SOTERM	select->oterm
# define	SARGS	select->args
# define	SARGT	select->args_stat
# define	SMLEN	select->max_arg_len
# define	SNB		select->nb_args
# define	SCUR	select->cursor_position
# define	SCOL	select->columns

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
