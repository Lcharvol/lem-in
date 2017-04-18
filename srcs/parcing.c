/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 02:30:39 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/19 23:17:19 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_verif_start_and_end(t_env **p, t_room **r)
{
	t_room	*new;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	new = *r;
	while (new->next != NULL)
	{
		if (new->state == 1)
			i = 1;
		if (new->state == 2)
			i2 = 2;
		new = new->next;
	}
	if (new->state == 1)
		i = 1;
	if (new->state == 2)
		i2 = 2;
	if (i == 0 && i2 == 0)
		ft_error("No start and no end rooms");
	if (i2 == 0)
		ft_error("No end room");
	if (i == 0)
		ft_error("No start room");
}

int			ft_is_a_command(char *line)
{
	if (line[0] == '#' && line[1] == '#')
		return (1);
	return (0);
}

int			ft_read_input2(int i, char *line, t_env **p, t_room **r)
{
	if (ft_is_a_room(line, *p) == 1)
		*r = ft_add_room(r, line, p);
	else if (ft_is_a_ant(line, p) == 1)
	{
		if (i != 1)
			ft_error("Error: number of ants already taken in");
	}
	else if (ft_is_a_tube(line) == 1)
	{
		ft_verif_start_and_end(p, r);
		if (ft_add_tube(p, r, line) == 1)
			return (2);
	}
	else if (!ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
		return (2);
	return (0);
}

int			ftn(int i)
{
	if (i != 1)
		ft_error("Error: no ants!");
	i++;
	return (i);
}

void		ft_parcing(t_env **p, t_room **r)
{
	int		i;
	char	*line;
	int		ret;

	i = 1;
	while (get_next_line(0, &line) != 0)
	{
		if (ft_is_a_ant(line, p))
			i = ftn(i);
		else if ((ft_is_a_comment(line) == 1 || ft_is_a_command(line) == 1)
			&& !ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
			;
		else
		{
			ret = ft_read_input2(i, line, p, r);
			if (ret == 1)
				ft_error("Input incorrect");
			if (ret == 2)
				return ;
			i++;
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
}
