/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signaux.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 15:02:25 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 17:36:00 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	handle_signal_resize(int nb)
{
	t_select *select;

	select = get_struct(0, NULL);
	if (select)
		show_args(select);
}

void	handle_signal_suspen(int nb)
{
	t_select *select;

	if ((select = get_struct(0, NULL)))
	{
		if (nb == SIGTSTP)
		{
			tcsetattr(SFD, TCSAFLUSH, &(SOTERM));
			tputs(tgetstr("te", NULL), 1, ft_putchar_select);
			tputs(tgetstr("ve", NULL), 1, ft_putchar_select);
			signal(SIGTSTP, SIG_DFL);
			ioctl(0, TIOCSTI, "\x1a");
		}
		else if (nb == SIGCONT)
		{
			signal(SIGTSTP, handle_signal_suspen);
			if (tcsetattr(SFD, TCSANOW, &(SNTERM)))
			{
				ft_free_struct(&select);
				exit(0);
			}
			tputs(tgetstr("ti", NULL), 1, ft_putchar_select);
			tputs(tgetstr("vi", NULL), 1, ft_putchar_select);
			show_args(select);
		}
	}
}

void	handle_signal_close(int nb)
{
	t_select *select;

	select = get_struct(0, NULL);
	nb++;
	if (select)
	{
		tcsetattr(SFD, TCSAFLUSH, &(SOTERM));
		tputs(tgetstr("te", NULL), 1, ft_putchar_select);
		tputs(tgetstr("ve", NULL), 1, ft_putchar_select);
		ft_free_struct(&select);
		exit(0);
	}
}

void	launch_signal(void)
{
	signal(SIGHUP, handle_signal_close);
	signal(SIGINT, handle_signal_close);
	signal(SIGQUIT, handle_signal_close);
	signal(SIGFPE, handle_signal_close);
	signal(SIGKILL, handle_signal_close);
	signal(SIGSEGV, handle_signal_close);
	signal(SIGPIPE, handle_signal_close);
	signal(SIGABRT, handle_signal_close);
	signal(SIGUSR1, handle_signal_close);
	signal(SIGUSR2, handle_signal_close);
	signal(SIGTSTP, handle_signal_suspen);
	signal(SIGCONT, handle_signal_suspen);
	signal(SIGWINCH, handle_signal_resize);
}
