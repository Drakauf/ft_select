/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 17:10:49 by shthevak    ###    #+. /#+    ###.fr     */
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
	char			**args; 				/* tableau d'arguments */
	int				*args_stat;				/* tableau d'etat des arguments */
	int				nb_args;				/* nombre total d'arguments */
	int				nb_del_args;				/* nombre d'arguments supprime*/
	int				nb_ldel_args;				/* dernier argument de la liste supprime*/
	int				max_arg_len;			/* longueur maximums des arguments */
	int				cursor_position;		/* position du curseur dans les arguments */
	struct termios	nterm;					/* termios a set */
	struct termios	oterm;					/* termios du shell actif avant select */
	int				fd;						/* fd d'ecriture */
	int				term_columns;			/* nombre de colums du terminal */
	int				term_lines;				/* nombre de lignes du terminal */
	int				nb_columns;				/* nombre de colones affichables */
	int				nb_lines;				/* nombre de ligne necessaire pour tout afficher */
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

#endif
