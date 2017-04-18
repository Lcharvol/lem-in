/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:21:31 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/19 23:02:47 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_get_the_path(t_env **p, t_room **room)
{
	t_room	*r;

	r = *room;
	ft_go_to_start(&r);
	ft_init_path(r, p, r->id);
	while (r->state != 2)
	{
		ft_last_move(&r);
		ft_add_path(r, p, r->id);
	}
}

int			ft_verif_name_tube(t_room **r, char *str)
{
	t_room	*new;
	int		i;
	int		i2;

	i2 = 0;
	i = 0;
	new = *r;
	while (str[i] && str[i] != '-')
		i++;
	while (new->next != NULL)
	{
		if (ft_strncmp(str, new->name, i) == 0)
			i2++;
		if (ft_strncmp(str + i + 1, new->name, ft_strlen(str) - i - 1) == 0)
			i2++;
		new = new->next;
	}
	if (i2 != 2)
		return (1);
	return (0);
}

void		ft_add_path(t_room *r, t_env **p, int id)
{
	t_env	*new;
	t_path	*tmp;

	new = *p;
	if (!(tmp = (t_path *)malloc(sizeof(t_path))))
		ft_error("MALLOC ERROR");
	tmp->next = new->path;
	tmp->id = id;
	tmp->room = r;
	(*p)->path = tmp;
	*p = new;
}

void		ft_init_path(t_room *r, t_env **p, int id)
{
	t_env	*new;

	new = *p;
	new->path->id = id;
	new->path->room = r;
	new->path->next = NULL;
}
