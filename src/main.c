/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 13:45:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 16:25:52 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

#include <stdio.h>

int init_term()
{
	int			ret;
	char		*term;
	
	term = getenv("TERM");
	if (term == NULL)
	{
		ft_putstr("TERM must be set (see 'env').\n");
		return 0;
	}
	ret = tgetent(NULL, term);
	if (ret == -1)
	{
		ft_putstr("Could not access to the termcap database...\n");
		return 0;
	}
	else if (ret == 0)
	{
		ft_putstr("Terminal type '");
		ft_putstr(term);
		ft_putstr("%s' is not defined in termcap database");
		ft_putstr("(or have too few informations).\n");
		return 0;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		ft_putstr("usage : ./ft_select [agrs]\n");
		return (0);
	}
	if (init_term())
	{
		printf("to do\n");
		return (0);
	}
	return (0);
}
