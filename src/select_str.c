/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_str.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:42:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 13:08:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_putstr_select(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &(str[i]), 1);
		i++;
	}
}

int		ft_putchar_select(int c)
{
	write(2, &c, 1);
	return (1);
}
