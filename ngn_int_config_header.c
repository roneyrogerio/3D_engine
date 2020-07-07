/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_config_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 03:26:57 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/07 08:50:48 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int	ngn_int_config_header(int fd, t_ngn *ngn)
{
	int		configs;
	char	**splitted_line;
	int		err;

	configs = 6;
	while (configs && (splitted_line = ngn_int_splittedline(fd)) != NULL)
	{
		err = ngn_int_config_save_header(splitted_line, ngn);
		ft_splitclear(splitted_line);
		if (err)
			break ;
		configs--;
	}
	if (configs != 0 || err)
	{
		if (g_ngnerr == 0)
			g_ngnerr = NGN_FILERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ngn_int_config_save_header(char **splitted_line, t_ngn *ngn)
{
	if (ft_strcmp(splitted_line[0], "R") == 0)
		return (ngn_int_config_save_resolution(splitted_line, ngn));
	else if (ft_strcmp(splitted_line[0], "NO") == 0 ||
			ft_strcmp(splitted_line[0], "SO") == 0 ||
			ft_strcmp(splitted_line[0], "WE") == 0 ||
			ft_strcmp(splitted_line[0], "EA") == 0 ||
			ft_strcmp(splitted_line[0], "S") == 0)
		return (ngn_int_config_save_texture(splitted_line, ngn));
	return (EXIT_FAILURE);
}

int	ngn_int_config_save_resolution(char **splitted_line, t_ngn *ngn)
{
	int	wd;
	int	ht;

	if (ft_splitlen(splitted_line) == 3 && ft_isnumber(splitted_line[1])
			&& ft_isnumber(splitted_line[2]))
	{
		wd = ft_atoi(splitted_line[1]);
		ht = ft_atoi(splitted_line[2]);
		if (wd > 0 && ht > 0)
		{
			ngn_set_window_size(ngn, wd, ht);
			return (EXIT_SUCCESS);
		}
	}
	g_ngnerr = NGN_RESERR;
	return (EXIT_FAILURE);
}

int	ngn_int_config_save_texture(char **splitted_line, t_ngn *ngn)
{
	void	*bmp;

	if (ft_splitlen(splitted_line) != 2 && (g_ngnerr = NGN_TEXERR))
		return (EXIT_FAILURE);
	if (!ft_strchr(splitted_line[1], '.') ||
			ft_strcmp(ft_strrchr(splitted_line[1], '.'), ".bmp"))
	{
		g_ngnerr = NGN_TEXFILERR;
		return (EXIT_FAILURE);
	}
	bmp = lbmp_load(splitted_line[1]);
	if (bmp == NULL && (g_ngnerr = NGN_TEXNFERR))
		return (EXIT_FAILURE);
	if (ft_strcmp(splitted_line[0], "NO") == 0)
		ngn->texture.no = bmp;
	if (ft_strcmp(splitted_line[0], "SO") == 0)
		ngn->texture.so = bmp;
	if (ft_strcmp(splitted_line[0], "WE") == 0)
		ngn->texture.we = bmp;
	if (ft_strcmp(splitted_line[0], "EA") == 0)
		ngn->texture.ea = bmp;
	if (ft_strcmp(splitted_line[0], "S") == 0)
		ngn->texture.s = bmp;
	return (EXIT_SUCCESS);
}
