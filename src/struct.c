/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:48:57 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 13:47:54 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			ft_arg_len_max(char **str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if ((j = ft_strlen(str[i])) > k)
			k = j;
		i++;
	}
	return (k);
}

t_select	*init_struct(int a, char **ac)
{
	t_select *select;

	if (!(select = malloc(sizeof(select))))
		return (NULL);
	if (!(select->args = init_tableau_args(ac + 1)))
	{
		free(select);
		return (NULL);
	}
	if (!(select->args_stat = init_tableau_args_stat(ft_tab_len(select->args))))
	{
		ft_free_struct(select);
		return (NULL);
	}
	select->nb_args = ft_tab_len(ac) - 1;
	select->max_arg_len = ft_arg_len_max(select->args);
	select->cursor = 0;
	return (select);
}

t_select	*get_struct(int a, char **ac)
{
	static t_select *select = NULL;

	if (!select)
	{
		select = init_struct(a, ac);
	}
	return (select);
}
