/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:31:28 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 11:43:17 by shthevak    ###    #+. /#+    ###.fr     */
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

char	**init_tableau_args(char **str, int a)
{
	char	**ret;
	int		i;

	if (a == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(ret) * (a))))
		return (NULL);
	i = 1;
	while (i < a)
	{
		ret[i - 1] = ft_strdup(str[i]);
		i++;
	}
	ret[i - 1] = NULL;
	return (ret);
}
