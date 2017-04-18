/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 06:09:45 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 01:31:02 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room		*ft_init_tube(t_room *new_r)
{
	if (!(new_r->tube = (t_tube *)malloc(sizeof(t_tube))))
		ft_error("MALLOC ERROR");
	new_r->tube->next = NULL;
	new_r->tube->sortie = NULL;
	new_r->tube->index = 1;
	return (new_r);
}

void		ft_verif_pullret(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			ft_error("Error: - in room name");
		i++;
	}
}

void		ft_verif_add_room(t_room *new_r, char **s)
{
	if (new_r->name[0] == 'L')
		ft_error("Error: room name start with L");
	if ((ft_atoi_ll(s[1]) > 2147483647 || ft_strlen(s[1]) >= 11) ||
		(ft_atoi_ll(s[2]) > 2147483647 || ft_strlen(s[2]) >= 11))
		ft_error("Error: wrong coord");
}

void		free_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_strdel(&(s[i]));
		i++;
	}
	free(s);
}

t_room		*ft_add_room(t_room **r, char *str, t_env **p)
{
	t_room	*new_r;
	t_env	*new_p;
	char	**s;

	new_p = *p;
	(new_r = (t_room *)malloc(sizeof(t_room))) ? NULL : ft_error("Error");
	new_r->next = *r;
	s = ft_strsplit(str, ' ');
	ft_verif_pullret(s[0]);
	new_r->name = ft_strdup(s[0]);
	ft_verif_add_room(new_r, s);
	new_r->pos_x = ft_atoi(s[1]);
	new_r->pos_y = ft_atoi(s[2]);
	new_r->state = new_p->tmp_state;
	new_p->tmp_state = 0;
	new_r->weight = 0;
	new_r->nb_ant = 0;
	new_r->id = (*r)->id + 1;
	if (new_r->state == 1)
		new_r->nb_ant = new_p->nb_ants;
	ft_verif_name(r, new_r->name);
	new_r->tube = NULL;
	free_split(s);
	return (new_r);
}
