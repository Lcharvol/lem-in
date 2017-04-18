/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 02:26:20 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 00:11:44 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

long long int		ft_atoi_ll(const char *str)
{
	int				i;
	long long int	nb;
	long long int	neg;

	nb = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = neg * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	return (neg * nb);
}

t_room				*ft_init_room(t_room **r)
{
	t_room			*r_tmp;

	r_tmp = *r;
	if (!(r_tmp = (t_room *)malloc(sizeof(t_room))))
		ft_error("MALLOC ERROR");
	r_tmp->pos_x = 0;
	r_tmp->pos_y = 0;
	r_tmp->id = 0;
	r_tmp->state = 0;
	r_tmp->weight = 0;
	r_tmp->nb_ant = 0;
	r_tmp->next = NULL;
	r_tmp->name = NULL;
	return (r_tmp);
}

t_env				*ft_init_env(t_env **p)
{
	t_env			*p_tmp;

	p_tmp->flag_color = 0;
	p_tmp = *p;
	if (!(p_tmp = (t_env *)malloc(sizeof(t_env))))
		ft_error("MALLOC ERROR");
	p_tmp->tmp_state = 0;
	if (!(p_tmp->path = (t_path *)malloc(sizeof(t_path))))
		ft_error("MALLOC ERROR");
	p_tmp->path->next = NULL;
	p_tmp->nb_ants = 0;
	return (p_tmp);
}

void				ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	exit(1);
}

int					ft_is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
