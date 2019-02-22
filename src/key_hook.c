/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 12:11:51 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:24:08 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	prev_cur(t_select *select)
{
	int i;

	i = SCUR;
	while (i >= 0)
	{
		if (SARGT[i] >= 0)
		{
			SCUR = i;
			dprintf(2, "prev 1 : %d\n", i);
			return ;
		}
		i--;
	}
	i = SNB - 1;
	while (i > SCUR)
	{
		if (SARGT[i] >= 0)
		{
			SCUR = i;
			dprintf(2, "prev 2 : %d\n", i);
			return ;
		}
		i--;
	}
}


void	next_cur(t_select *select)
{
	int i;

	i = SCUR;
	while (i < SNB)
	{
		if (SARGT[i] >= 0)
		{
			SCUR = i;
			dprintf(2, "next 1 : %d\n", i);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < SCUR)
	{
		if (SARGT[i] >= 0)
		{
			SCUR = i;
			dprintf(2, "next 2 : %d\n", i);
			return ;
		}
		i++;
	}
}

void	key_dir(t_select *select, long key)
{

	if (key == UP)
	{
		ft_move_cursor_up(select);
	}
}

int		key_other(t_select *select, long key)
{
	if (key == DELETE || key == BACKSPACE)
	{
		SARGT[SCUR] = -1;
		SDNB++;
		if (SNB == SDNB)
			return (1);
		if (SCUR == SLDNB)
		{
			prev_cur(select);
			SLDNB = SCUR;
		}
		else
			next_cur(select);
	}
	return (0);
}

void	key_hook(t_select *select)
{
	long	key;

	while (1)
	{
		key = 0;
		if (read(0, &key, 8))
		{
			key_dir(select, key);
			if (key_other(select, key) || key == ECHAP)
			{
				SDNB = SNB;
				break ;
			}
			show_args(select);
			dprintf(1, "\nSCUR = %d SNB = %d SDNB = %D SLDNB= %d SCOL = %d SLIN = %d nb = %d\n", SCUR, SNB, SDNB, SLDNB, SCOL ,SLIN ,(SNB - SDNB) % SCOL );
		}
	}
}
