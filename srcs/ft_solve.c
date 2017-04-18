/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:27:53 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 22:58:01 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			ft_check_end_solve(t_env **p, t_room **r)
{
	t_room	*tmp;

	tmp = *r;
	while (tmp->next)
	{
		if (tmp->state == 2 && tmp->nb_ant == (*p)->nb_ants)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_print_move(int i, t_env **p)
{
	int		i2;

	i2 = i;
	while (i2 > 231)
		i2 /= 9;
	if (i2 == 16)
		i2 = 2;
	if ((*p)->flag_color == 1)
	{
		ft_putstr("\e[38;5;");
		ft_putnbr(i2);
		ft_putstr("m");
	}
	ft_putstr("L");
	ft_putnbr(i);
	ft_putstr("-");
	ft_putstr((*p)->path->room->name);
	ft_putstr(RESET);
	ft_putchar(' ');
}

int			ft_send_ants2(t_env **p, t_room **r, int i)
{
	if ((*p)->path->room->state == 2 &&
		(*p)->path->next->room->nb_ant != 0)
	{
		ft_print_move(i, p);
		(*p)->path->room->nb_ant += 1;
		(*p)->path->next->room->nb_ant -= 1;
		i++;
	}
	else if ((*p)->path->room->nb_ant == 0 &&
		(*p)->path->next->room->nb_ant != 0)
	{
		ft_print_move(i, p);
		(*p)->path->room->nb_ant += 1;
		(*p)->path->next->room->nb_ant -= 1;
		i++;
	}
	return (i);
}

void		ft_send_ants(t_env **p, t_room **r)
{
	int		i;
	t_room	*new;
	t_room	*tmp;
	t_path	*path;

	path = (*p)->path;
	new = *r;
	ft_putchar('\n');
	while (ft_check_end_solve(p, r) != 0)
	{
		i = (*p)->path->room->nb_ant + 1;
		while ((*p)->path->next != NULL)
		{
			i = ft_send_ants2(p, r, i);
			(*p)->path = (*p)->path->next;
		}
		ft_putchar('\n');
		(*p)->path = path;
	}
}

void		ft_solve(t_env **p, t_room **r)
{
	while (ft_path_finder(p, r) != 0)
		ft_restart_solver(r);
	ft_get_the_path(p, r);
	ft_send_ants(p, r);
}
