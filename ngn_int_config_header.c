/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_config_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 03:26:57 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/26 15:09:58 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"
#include <stdio.h>

int	ngn_int_config_header(int fd, t_ngn *ngn)
{
	int		configs;
	char	**splitted_line;
	int		err;

	configs = 8;
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
	else if (ft_strcmp(splitted_line[0], "F") == 0 ||
			ft_strcmp(splitted_line[0], "C") == 0)
		return (ngn_int_config_save_color(splitted_line, ngn));
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
	printf("%s", lbmp_strerror(g_lbmperr));
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

int	ngn_int_config_save_color(char **spline, t_ngn *ngn)
{
	char		**spcolor;
	t_argb		rgb;

	if (ft_splitlen(spline) != 2 && (g_ngnerr = NGN_COLERR))
		return (EXIT_FAILURE);
	if ((!(spcolor = ft_split(spline[1], ',')) || ft_splitlen(spcolor) != 3 ||
		!ft_isnumber(spcolor[0]) || !ft_isnumber(spcolor[1]) || !ft_isnumber(
		spcolor[2]) || ft_atoi(spcolor[0]) < 0 || ft_atoi(spcolor[0]) > 255 ||
		ft_atoi(spcolor[1]) < 0 || ft_atoi(spcolor[1]) > 255 || ft_atoi(spcolor
		[2]) < 0 || ft_atoi(spcolor[2]) > 255) && (g_ngnerr = NGN_COLERR))
	{
		ft_splitclear(spcolor);
		return (EXIT_FAILURE);
	}
	rgb.r = ft_atoi(spcolor[0]);
	rgb.g = ft_atoi(spcolor[1]);
	rgb.b = ft_atoi(spcolor[2]);
	ngn->ceil.argb.r = spline[0][0] == 'C' ? rgb.r : ngn->ceil.argb.r;
	ngn->ceil.argb.g = spline[0][0] == 'C' ? rgb.g : ngn->ceil.argb.g;
	ngn->ceil.argb.b = spline[0][0] == 'C' ? rgb.b : ngn->ceil.argb.b;
	ngn->floor.argb.r = spline[0][0] == 'F' ? rgb.r : ngn->floor.argb.r;
	ngn->floor.argb.g = spline[0][0] == 'F' ? rgb.g : ngn->floor.argb.g;
	ngn->floor.argb.b = spline[0][0] == 'F' ? rgb.b : ngn->floor.argb.b;
	ft_splitclear(spcolor);
	return (EXIT_SUCCESS);
}
