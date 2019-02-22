/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_cursor.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 14:23:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:24:06 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_move_cursor_up(t_select *select)
{
	int i;

	if (SDNB == SNB - 1 || SLIN == 0)
		return ;
	i = SCOL;
	if (SCUR - SCOL < 0)
	{
		SCUR = SLDNB;
		i = ((SNB - SDNB) % SCOL == 0) ? SCOL : (SNB - SDNB) % SCOL - 1;
//		i == -1 ? i = SCOL: 0;
	}
	while (i)
	{
		if (SCUR >= 0 && SARGT[SCUR--] >= 0)
			i--;
	}
	if (i)
	{
		SCUR = SLDNB;
		while (i)
		{
			if (SCUR >= 0 && SARGT[SCUR--] >= 0)
				i--;
		}
	}
	SCUR < 0 ? SCUR = SLDNB : 0;
}
