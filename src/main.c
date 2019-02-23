/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 13:45:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 11:47:57 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <stdio.h>

int		init_term(void)
{
	int			ret;
	char		*term;

	term = getenv("TERM");
	if (term == NULL)
	{
		ft_putstr("TERM must be set (see 'env').\n");
		return (0);
	}
	ret = tgetent(NULL, term);
	if (ret == -1)
	{
		ft_putstr("Could not access to the termcap database...\n");
		return (0);
	}
	else if (ret == 0)
	{
		ft_putstr("Terminal type '");
		ft_putstr(term);
		ft_putstr("%s' is not defined in termcap database");
		ft_putstr("(or have too few informations).\n");
		return (0);
	}
	return (1);
}

void	print_selected(t_select *select)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SNB)
	{
		if (SARGT[i])
		{
			if (j != 0)
				write(1, " ", 1);
			ft_putstr(SARGS[i]);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_select *select;

	if (ac <= 1)
	{
		ft_putstr("usage : ./ft_select [agrs]\n");
		return (0);
	}
	if (!init_term())
		return (0);
	if (!(select = get_struct(ac, av)))
		return (0);
	//launch_signal();
	if (select)
	{
		show_args(select);
		key_hook(select);
		tcsetattr(SFD, TCSAFLUSH, &(SOTERM));
		tputs(tgetstr("te", NULL), 1, ft_putchar_select);
		tputs(tgetstr("ve", NULL), 1, ft_putchar_select);
		if (SNB != SDNB)
			print_selected(select);
		ft_free_struct(&select);
	}
	return (0);
}
