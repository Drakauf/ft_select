/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 12:11:51 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 11:40:06 by shthevak    ###    #+. /#+    ###.fr     */
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
			return ;
		}
		i++;
	}
}

void	key_dir(t_select *select, long key)
{
	if (key == UP)
		ft_move_cursor_up(select);
	if (key == LEFT)
		ft_move_cursor_left(select);
	if (key == RIGHT)
		ft_move_cursor_right(select);
	if (key == DOWN)
		ft_move_cursor_down(select);
}

int		key_delete(t_select *select, long key)
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
		{
			if (SCUR == SFDNB)
			{
				next_cur(select);
				SFDNB = SCUR;
			}
			else
				next_cur(select);
		}
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
			if (key == RETURN)
				break ;
			key_dir(select, key);
			key == SPACE ? key_space(select) : 0;
			if (key_delete(select, key) || key == ECHAP)
			{
				SDNB = SNB;
				break ;
			}
			show_args(select);
		}
	}
}
