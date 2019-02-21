/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 13:27:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 17:43:17 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"


void	print_args(t_select *select)
{
	int i;
	int j;
	int k;

	if (!SNB || !SCOL || SLIN > STLIN)
		return (ft_putstr_select("RESIZE TERMINAL PLEASE ...\n"));
	i = 0;
	j = 0;
	k = 0;
	while (k < SNB)
	{
		ft_putstr_select(SARGS[k]);
		k++;
	}
	
}

void	terminal_size(void)
{
	struct winsize	w;
	t_select		*select;

	if ((select = get_struct(0, NULL)))
	{
		ioctl(SFD, TIOCGWINSZ, &w);
		STLIN = w.ws_row;
		STCOL = w.ws_col;
		SCOL = STCOL / (SMLEN + 1);
		if (SCOL)
			SLIN = SNB / SCOL;
	}
}

void	clean_terminal(void)
{
	t_select		*select;
	int				i;

	i = 0;
	if ((select = get_struct(0, NULL)))
	{
		while (i < STLIN)
		{
			tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, ft_putchar_select);
			tputs(tgetstr("ce", NULL), 1, ft_putchar_select);
			i++;
		}
		if (!STLIN)
			tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar_select);
	}
}

void	show_args(t_select *select)
{
	terminal_size();
	clean_terminal();
	print_args(select);
}
