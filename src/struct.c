/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:48:57 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 17:26:10 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			ft_arg_len_max(t_select *select)
{
	int i;
	int j;
	int k;

	k = 0;
	if (select)
	{
		i = 0;
		j = 0;
		while (SARGS[i])
		{
			if (SARGT[i] >= 0 && (j = ft_strlen(SARGS[i])) > k)
				k = j;
			i++;
		}
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
	SNTERM.c_lflag &= ~(ICANON);
	SNTERM.c_lflag &= ~(ECHO);
	SNTERM.c_cc[VMIN] = 0;
	SNTERM.c_cc[VTIME] = 0;
	if (tcsetattr(SFD, TCSANOW, &(SNTERM)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_select);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_select);
	return (1);
}

t_select	*init_struct(int a, char **ac)
{
	t_select *select;

	if (!(select = malloc(sizeof(t_select))))
		return (NULL);
	SNB = a - 1;
	SDNB = 0;
	SLDNB = SNB - 1;
	SFD = -1;
	if (!(SARGS = init_tableau_args(ac, a)))
	{
		free(select);
		return (NULL);
	}
	if (!(select->args_stat = init_tableau_args_stat(SNB)))
	{
		ft_free_struct(&select);
		return (NULL);
	}
	if (!handle_termios(select))
	{
		ft_free_struct(&select);
		return (NULL);
	}
	return (select);
}

t_select	*get_struct(int a, char **ac)
{
	static t_select *select = NULL;

	if (!select)
	{
		select = init_struct(a, ac);
		SCUR = 0;
		SFDNB = 0;
	}
	return (select);
}
