/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:51:00 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 19:57:20 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_go_to_start(t_room **r)
{
	while ((*r)->next)
	{
		if ((*r)->state == 1)
			return ;
		(*r) = (*r)->next;
	}
}

void		ft_last_move(t_room **r)
{
	while ((*r)->tube)
	{
		if ((*r)->tube->sortie->weight == 1)
		{
			(*r) = (*r)->tube->sortie;
			return ;
		}
		(*r)->tube = (*r)->tube->next;
	}
	return ;
}

int			ft_move(t_room **r)
{
	while ((*r)->tube)
	{
		if ((*r)->tube->sortie->weight == 0)
		{
			(*r) = (*r)->tube->sortie;
			return (0);
		}
		(*r)->tube = (*r)->tube->next;
	}
	(*r)->weight = 2;
	return (1);
}

int			ft_path_finder(t_env **p, t_room **room)
{
	t_room	*r;
	t_room	*tmp;

	r = *room;
	ft_go_to_start(&r);
	r->weight = 1;
	if (r->tube == NULL)
		ft_error("Error: invalid path (no tubes)");
	while (1)
	{
		tmp = r;
		if (ft_move(&r) == 1)
			return (1);
		if (r->state == 2)
			r->weight = 1;
		if (r->state == 2)
			return (0);
		if (r->weight == 1)
			tmp->weight = 2;
		if (r->weight == 1)
			return (1);
		r->weight = 1;
	}
	return (1);
}

void		ft_restart_solver(t_room **r)
{
	t_room	*new;

	new = *r;
	while (new)
	{
		if (new->weight == 1)
			new->weight = 0;
		new = new->next;
	}
}
