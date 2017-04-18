/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 00:44:20 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/18 23:43:25 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define RESET "\e[0m"

typedef struct		s_tube
{
	struct s_room	*sortie;
	struct s_tube	*next;
	int				index;
}					t_tube;

typedef struct		s_path
{
	struct s_room	*room;
	int				id;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	int				id;
	int				weight;
	struct s_tube	*tube;
	int				nb_ant;
	int				state;
	char			*name;
	int				pos_x;
	int				pos_y;
	struct s_room	*next;

}					t_room;

typedef struct		s_env
{
	int				flag_color;
	struct s_path	*path;
	int				tmp_state;
	int				nb_ants;
}					t_env;

t_room				*ft_add_room(t_room **r, char *str, t_env **p);
t_room				*ft_init_room(t_room **r);
t_room				*ft_add_room(t_room **r, char *str, t_env **p);
t_env				*ft_init_env(t_env **p);

long long int		ft_atoi_ll(const char *str);

int					ft_is_number(char c);
int					ft_is_a_room(char *str, t_env *p);
int					ft_is_a_comment(char *line);
int					ft_is_a_tube(char *line);
int					ft_is_a_ant(char *str, t_env **p);
int					ft_path_finder(t_env **p, t_room **room);

void				ft_go_to_start(t_room **r);
void				ft_last_move(t_room **r);
void				ft_get_the_path(t_env **p, t_room **room);
void				ft_verif_start_and_end(t_env **p, t_room **r);
void				ft_restart_solver(t_room **r);
int					ft_verif_name_tube(t_room **r, char *str);
void				ft_add_path(t_room *r, t_env **p, int id);
void				ft_init_path(t_room *r, t_env **p, int id);
void				ft_solve(t_env **p, t_room **r);
int					ft_add_tube(t_env **p, t_room **r, char *str);
void				ft_verif_coord(t_room **r, int x, int y);
void				ft_verif_name(t_room **r, char *name);
void				ft_parcing(t_env **p, t_room **r);
void				ft_error(char *str);

#endif
