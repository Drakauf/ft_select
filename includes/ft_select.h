/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 11:54:11 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <curses.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>

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
	int				nb_del_args;
	int				nb_ldel_args;
	int				nb_fdel_args;
	int				max_arg_len;
	int				cursor_position;
	struct termios	nterm;
	struct termios	oterm;
	int				fd;
	int				term_columns;
	int				term_lines;
	int				nb_columns;
	int				nb_lines;
}					t_select;

# define SFD		select->fd
# define SNTERM		select->nterm
# define SOTERM		select->oterm
# define SARGS		select->args
# define SARGT		select->args_stat
# define SMLEN		select->max_arg_len
# define SNB		select->nb_args
# define SDNB		select->nb_del_args
# define SLDNB		select->nb_ldel_args
# define SFDNB		select->nb_fdel_args
# define SCUR		select->cursor_position
# define SCOL		select->nb_columns
# define SLIN		select->nb_lines
# define STCOL		select->term_columns
# define STLIN		select->term_lines

/*
** Key Hook
*/

# define UP			0x415b1b
# define DOWN		0x425b1b
# define LEFT		0x445b1b
# define RIGHT		0x435b1b
# define BACKSPACE	0x7f
# define SPACE		0x20
# define ECHAP		0x1b
# define DELETE		0x7e335b1b
# define RETURN		0xa

/*
********************************************************************************
**                                                                   Fonction  *
********************************************************************************
*/

void				ft_putstr(char *str);
void				ft_putstr_select(char *str);
int					init_term(void);
int					ft_tab_len(char **tableau);
char				*ft_strdup(char *str);
void				ft_strdel(char **str);
t_select			*init_struct(int a, char **ac);
t_select			*get_struct(int a, char **ac);
void				ft_free_tab(char **tableau);
void				ft_free_struct(t_select **select);
char				**init_tableau_args(char **str, int a);
int					*init_tableau_args_stat(int i);
int					ft_strlen(char *str);
int					handle_termios(t_select *select);
int					ft_putchar_select(int c);
void				show_args(t_select *select);
void				terminal_size(void);
void				clean_terminal(void);
void				print_args(t_select *select);
void				ft_put_args(t_select *select, int *i, int *j, int *k);
void				key_hook(t_select *select);
int					ft_arg_len_max(t_select *select);
void				key_dir(t_select *select, long key);
void				ft_move_cursor_up(t_select *select);
void				next_cur(t_select *select);
void				prev_cur(t_select *select);
void				ft_move_cursor_left(t_select *select);
void				ft_move_cursor_right(t_select *select);
void				ft_move_cursor_down(t_select *select);
int					key_delete(t_select *select, long key);
void				key_space(t_select *select);
#endif
