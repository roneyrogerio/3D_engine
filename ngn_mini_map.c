/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 00:25:00 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/23 12:10:57 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int		rgb_map(int p)
{
	if (p == 1)
		return (0x3CFF8900);
	else if (p == 0 || p > 1)
		return (0x3CFFFFFF);
	else if (p < 0)
		return (0x00000000);
	return (0);
}

void	ngn_mini_map(t_ngn *ngn, void (*frame_draw)(int, int, int))
{
	ngn_map_draw(ngn, frame_draw);
	ngn_player_draw(ngn, frame_draw);
}

void	ngn_map_draw(t_ngn *ngn, void (*frame_draw)(int, int, int))
{
	int x;
	int y;
	int mx_x;
	int mx_y;

	x = ngn->wd - ngn->mx_wd * ngn->map.sz - ngn->map.mgn_x;
	y = ngn->ht - ngn->mx_ht * ngn->map.sz - ngn->map.mgn_y;
	while (x < ngn->wd - ngn->map.mgn_x && ngn->map.sz)
	{
		while (y < ngn->ht - ngn->map.mgn_y)
		{
			mx_x = ngn->mx_wd * ngn->map.sz;
			mx_x = mx_x - (ngn->wd - x - ngn->map.mgn_x);
			mx_x /= ngn->map.sz;
			mx_y = ngn->mx_ht * ngn->map.sz;
			mx_y = mx_y - (ngn->ht - y - ngn->map.mgn_y);
			mx_y /= ngn->map.sz;
			frame_draw(x, y, rgb_map(ngn->mx[mx_y][mx_x]));
			y++;
		}
		y -= ngn->mx_ht * ngn->map.sz;
		x++;
	}
}

void	ngn_player_draw(t_ngn *ngn, void (*frame_draw)(int, int, int))
{
	t_circle	circle;
	int			map_x;
	int			map_y;

	if (ngn->map.sz == 0)
		return ;
	map_x = ngn->wd - ngn->mx_wd * ngn->map.sz - ngn->map.mgn_x;
	map_y = ngn->ht - ngn->mx_ht * ngn->map.sz - ngn->map.mgn_y;
	circle.x = map_x + round(ngn->map.sz * ngn->player.x);
	circle.y = map_y + round(ngn->map.sz * ngn->player.y);
	circle.radius = ceil(ngn->map.sz * ngn->player.radius);
	circle.color = 0xffff0000;
	ngn_int_circle(&circle, frame_draw);
}
