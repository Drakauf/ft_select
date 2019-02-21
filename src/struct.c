/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:48:57 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 17:01:10 by shthevak    ###    #+. /#+    ###.fr     */
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

int			handle_termios(t_select *select)
{
	if (!(isatty(STDERR_FILENO)))
		return (0);
	if ((SFD = open(ttyname(STDERR_FILENO), O_RDWR)) == -1)
		return (0);
	if (tcgetattr(SFD, &(SOTERM)) == -1 || tcgetattr(SFD, &(SNTERM)) == -1)
		return (0);
	return (1);
}

t_select	*init_struct(int a, char **ac)
{
	t_select *select;

	if (!(select = malloc(sizeof(select))))
		return (NULL);
	if (!(SARGS = init_tableau_args(ac + 1)))
	{
		free(select);
		return (NULL);
	}
	if (!(SARGT = init_tableau_args_stat(ft_tab_len(SARGS))))
	{
		ft_free_struct(select);
		return (NULL);
	}
	if (!handle_termios(select))
	{
		ft_free_struct(select);
		return (NULL);
	}
	SNB = ft_tab_len(SARGS);
	SMLEN = ft_arg_len_max(SARGS);
	SCUR = 0;
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
