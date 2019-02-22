/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 13:27:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:24:10 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_put_args(t_select *select, int *i, int *j, int *k)
{
	int n;

	n = *i;
	tputs(tgoto(tgetstr("cm", NULL), (n * SMLEN), (*j)), 1, ft_putchar_select);
	if (SCUR == *k)
		tputs(tgetstr("us", NULL), 1, ft_putchar_select);
	if (SARGT[*k] == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putchar_select);
	ft_putstr_select(SARGS[(*k)]);
	if (SCUR == *k || SARGT[*k] == 1)
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
	(*i)++;
	if ((*i) >= SCOL)
	{
		(*j)++;
		(*i) = 0;
	}
}

void	print_args(t_select *select)
{
	int i;
	int j;
	int k;

	if (!SCOL || SLIN > STLIN)
		return (ft_putstr_select("RESIZE TERMINAL PLEASE ...\n"));
	i = 0;
	j = 0;
	k = 0;
	while (k < SNB)
	{
		if (SARGT[k] >= 0)
		{
			ft_put_args(select, &i, &j, &k);
		}
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
		SMLEN = ft_arg_len_max(select) + 1;
		STLIN = w.ws_row;
		STCOL = w.ws_col;
		SCOL = STCOL / SMLEN;
		if (SCOL)
			SLIN = (SNB - SDNB) / SCOL;
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
