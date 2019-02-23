/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_cursor.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 14:23:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 11:44:11 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_move_cursor_up(t_select *select)
{
	int i;

	if (SLIN == 0)
		return ;
	i = SCOL;
	while (i && SCUR >= SFDNB)
	{
		if (SCUR >= 0 && SARGT[SCUR--] >= 0)
			i--;
	}
	if (SCUR < SFDNB)
		SCUR = SLDNB;
	if (SARGT[SCUR] == -1)
		prev_cur(select);
}

void	ft_move_cursor_left(t_select *select)
{
	if (SCUR == SFDNB)
	{
		SCUR = SLDNB;
		return ;
	}
	SCUR--;
	prev_cur(select);
}

void	ft_move_cursor_right(t_select *select)
{
	if (SCUR == SLDNB)
	{
		SCUR = SFDNB;
		return ;
	}
	SCUR++;
	next_cur(select);
}

void	ft_move_cursor_down(t_select *select)
{
	int i;

	if (SLIN == 0)
		return ;
	i = SCOL;
	while (i && SCUR <= SLDNB)
	{
		if (SCUR <= SLDNB && SARGT[SCUR++] >= 0)
			i--;
	}
	if (SCUR > SLDNB)
		SCUR = SFDNB;
	if (SARGT[SCUR] == -1)
		prev_cur(select);
}

void	key_space(t_select *select)
{
	SARGT[SCUR] = !SARGT[SCUR];
	if (SARGT[SCUR])
	{
		SCUR++;
		next_cur(select);
	}
}
