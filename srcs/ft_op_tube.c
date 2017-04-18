/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_tube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 05:26:18 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/19 23:03:22 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room		*ft_cherch_room_entry(t_room **r, char *str)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = *r;
	while (str[i] && str[i] != '-')
		i++;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(str, tmp->name, i) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_room		*ft_cherch_room_exit(t_room **r, char *str)
{
	t_room	*tmp;
	int		i;
	int		i2;

	i = 0;
	tmp = *r;
	while (str[i] && str[i] != '-')
		i++;
	i2 = i;
	while (str[i2])
		i2++;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(str + i + 1, tmp->name, i2 - i - 1) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void		ft_put_tube_entry(t_room **r, char *str)
{
	t_room	*new_r;
	t_tube	*new_t;
	int		i;

	i = 1;
	new_r = ft_cherch_room_entry(r, str);
	if (new_r->tube == NULL)
	{
		if (!(new_r->tube = (t_tube *)malloc(sizeof(t_tube))))
			ft_error("MALLOC ERROR");
		new_r->tube->index = i;
		new_r->tube->next = NULL;
		new_r->tube->sortie = ft_cherch_room_exit(r, str);
		return ;
	}
	else
	{
		if (!(new_t = (t_tube *)malloc(sizeof(t_tube))))
			ft_error("MALLOC ERROR");
		new_t->index = new_r->tube->index + 1;
		new_t->next = new_r->tube;
		new_t->sortie = ft_cherch_room_exit(r, str);
		new_r->tube = new_t;
	}
}

void		ft_put_tube_exit(t_room **r, char *str)
{
	t_room	*new_r;
	t_tube	*new_t;
	int		i;

	i = 1;
	new_r = ft_cherch_room_exit(r, str);
	if (new_r->tube == NULL)
	{
		if (!(new_r->tube = (t_tube *)malloc(sizeof(t_tube))))
			ft_error("MALLOC ERROR");
		new_r->tube->index = i;
		new_r->tube->next = NULL;
		new_r->tube->sortie = ft_cherch_room_entry(r, str);
		return ;
	}
	else
	{
		if (!(new_t = (t_tube *)malloc(sizeof(t_tube))))
			ft_error("MALLOC ERROR");
		new_t->index = new_r->tube->index + 1;
		new_t->next = new_r->tube;
		new_t->sortie = ft_cherch_room_entry(r, str);
		new_r->tube = new_t;
	}
}

int			ft_add_tube(t_env **p, t_room **r, char *str)
{
	if (ft_verif_name_tube(r, str) == 1)
		return (1);
	ft_put_tube_entry(r, str);
	ft_put_tube_exit(r, str);
	return (0);
}
