/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 00:43:48 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 00:04:29 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			ft_is_a_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

void		ft_get_flag(int argc, char **argv, t_env **p, t_room **r)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-c"))
			(*p)->flag_color = 1;
		else if (ft_strequ(argv[i], "-p"))
			;
		else
			ft_error("Error: Arg");
		i++;
	}
}

void		ft_secu(t_env **p, t_room **r)
{
	if ((*r)->name == NULL)
		ft_error("Error: no room");
	if (!(r))
		ft_error("Error: no room");
	if (!(r))
		ft_error("Error: no room");
}

int			main(int argc, char **argv)
{
	t_room	*r;
	t_env	*p;

	r = ft_init_room(&r);
	p = ft_init_env(&p);
	ft_get_flag(argc, argv, &p, &r);
	ft_parcing(&p, &r);
	ft_secu(&p, &r);
	ft_solve(&p, &r);
	return (0);
}
