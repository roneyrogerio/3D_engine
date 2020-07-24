/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_config_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 06:45:51 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/24 10:43:42 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int		ngn_int_config_map(int fd, t_ngn *ngn)
{
	void	*lst;

	if (fd < 3 || ngn == NULL)
		return (EXIT_FAILURE);
	if ((lst = ngn_int_config_map2lst(fd, ngn)) == NULL)
		g_ngnerr = NGN_MAPERR;
	else if ((ngn->mx = ngn_int_matrix_creat(ngn->mx_wd, ngn->mx_ht)) == NULL)
		g_ngnerr = NGN_MAPERR;
	ft_lstitertw(lst, ngn->mx, &ngn_int_config_lst2matrix);
	ft_lstclear(&lst, &free);
	if (g_ngnerr == 0 &&
		ngn_int_matrix_validn(ngn->mx, ngn->mx_wd, ngn->mx_ht) == EXIT_FAILURE)
		g_ngnerr = NGN_MAPERR;
	if (g_ngnerr == 0 && ngn_int_config_start_pos(ngn) == EXIT_FAILURE)
		g_ngnerr = NGN_MAPERR;
	if (g_ngnerr)
		return (EXIT_FAILURE);
	ngn_int_resize(ngn);
	return (EXIT_SUCCESS);
}

void	*ngn_int_config_map2lst(int fd, t_ngn *ngn)
{
	void	*lst;
	void	*new;
	int		ret;
	char	*line;

	lst = NULL;
	while (fd > 2 && ngn != NULL && (ret = ngn_int_getline(fd, &line)) >= 0)
	{
		if ((ret == 0 && ngn->mx_ht) || (new = ft_lstnew(line)) == NULL)
		{
			ft_lstclear(&lst, &free);
			free(line);
			return (NULL);
		}
		else if (ret > 0)
		{
			ft_lstadd_back(&lst, new);
			ngn->mx_wd = ret > (int)ngn->mx_wd ? ret : ngn->mx_wd;
			ngn->mx_ht += 1;
			continue ;
		}
		free(line);
		free(new);
	}
	return (lst);
}

void	ngn_int_config_lst2matrix(void *line, void *mx)
{
	char			*line_ptr;
	int				**mx_ptr;
	static size_t	y;
	size_t			x;

	line_ptr = line;
	mx_ptr = mx;
	x = 0;
	while (line_ptr[x])
	{
		if (ft_isdigit(line_ptr[x]))
			mx_ptr[y][x] = line_ptr[x] - 48;
		else if (line_ptr[x] != 32)
			mx_ptr[y][x] = line_ptr[x];
		x++;
	}
	y++;
}

int		ngn_int_config_start_pos(t_ngn *ngn)
{
	t_obj	pos;
	int		found;

	pos.x = 0;
	pos.y = 0;
	found = 0;
	while (pos.y >= 0 && pos.y < ngn->mx_ht)
	{
		if (ngn_int_if_player(ngn->mx[pos.y][pos.x]) && found == 0)
		{
			ngn->player.x = pos.x + 0.5;
			ngn->player.y = pos.y + 0.5;
			ngn_int_set_start_angle(ngn, ngn->mx[pos.y][pos.x]);
			ngn->mx[pos.y][pos.x] = 0;
			found = 1;
		}
		else if (ngn_int_if_player(ngn->mx[pos.y][pos.x]) && found == 1)
			return (EXIT_FAILURE);
		pos.x++;
		if (pos.x == ngn->mx_wd && !(pos.x = 0))
			pos.y++;
	}
	if (found == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
