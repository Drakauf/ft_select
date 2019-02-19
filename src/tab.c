/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:31:28 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 20:50:07 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"


int		*init_tableau_args_stat(int i)
{
	int	*ret;
	int	j;

	if (!(ret = malloc(sizeof(ret) * i)))
		return (NULL);
	j = 0;
	while (j < i)
		ret[j++] = 0;
	return (ret);
}

char	**init_tableau_args(char **str)
{
	char **ret;
	int 	i;

	i = ft_tab_len(str);
	if (!(ret = malloc(sizeof(ret) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int		ft_tab_len(char **tableau)
{
	int i;

	i = 0;
	if (tableau == NULL)
		return (0);
	while (tableau[i])
		i++;
	return (i);
}
