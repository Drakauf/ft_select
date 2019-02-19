/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 20:37:19 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 20:54:35 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_free_tab(char **tableau)
{
	int i;

	i = 0;
	if (tableau != NULL)
	{
		while (tableau[i])
		{
			free(tableau[i]);
			tableau[i] = NULL;
			i++;
		}
		free(tableau[i]);
		free(tableau);
		tableau = NULL;
	}
}

void	ft_free_struct(t_select *select)
{
	if (select)
	{
		if (select->args)
			ft_free_tab(select->args);
		if (select->args_stat)
			free(select->args_stat);
		free(select);
	}
}
