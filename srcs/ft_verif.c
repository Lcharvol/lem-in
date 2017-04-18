/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:45:09 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 22:30:59 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_verif_name(t_room **r, char *name)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = *r;
	while (tmp->next != NULL)
	{
		if (ft_strequ(tmp->name, name))
			i++;
		tmp = tmp->next;
	}
	if (i == 1)
		ft_error("Error: Same room name");
}

int			ft_is_a_room2(int i, char *str, t_env *p)
{
	int		tmp;

	tmp = i;
	while (str[i] && ft_is_number(str[i]) == 1)
		i++;
	if (i == tmp || str[i] != ' ')
		return (0);
	i++;
	tmp = i;
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && ft_is_number(str[i]) == 1)
		i++;
	if (i == tmp || str[i] != '\0')
		return (0);
	return (1);
}

int			ft_is_a_room(char *str, t_env *p)
{
	int		i;

	i = 0;
	if (ft_strequ(str, "##start"))
	{
		p->tmp_state = 1;
		return (0);
	}
	else if (ft_strequ(str, "##end"))
	{
		p->tmp_state = 2;
		return (0);
	}
	while (str[i] != ' ' && str[i])
		i++;
	if (i == 0 || str[i] != ' ')
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '-'))
		i++;
	return (ft_is_a_room2(i, str, p));
}

int			ft_is_a_ant(char *str, t_env **p)
{
	int		i;

	i = 0;
	while (str[i] == '+')
		i++;
	while (str[i] && ft_is_number(str[i]) == 1)
		i++;
	if (i == 0)
		return (0);
	if (str[i] == '\0')
	{
		if (ft_atoi_ll(str) > 2147483647 || ft_strlen(str) >= 11)
			ft_error("Error: too many ants!");
		(*p)->nb_ants = ft_atoi_ll(str);
		if ((*p)->nb_ants == 0)
			ft_error("Error: no ant!");
		return (1);
	}
	return (0);
}

int			ft_is_a_tube(char *line)
{
	int		i;
	int		tmp;

	i = 0;
	while (line[i] && ((ft_is_number(line[i]) == 1 || ft_isascii(line[i]) == 1)
		&& line[i] != '-' && line[i] != ' '))
		i++;
	if (i == 0 || line[i] != '-')
		return (0);
	tmp = i;
	i++;
	while (line[i] && ((ft_is_number(line[i]) == 1 || ft_isascii(line[i]) == 1)
		&& line[i] != '-' && line[i] != ' '))
		i++;
	if (i == tmp)
		return (0);
	if (line[i] == '\0')
		return (1);
	return (0);
}
