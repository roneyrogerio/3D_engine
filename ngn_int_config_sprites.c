/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_config_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:50:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/27 14:24:57 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_config_sprites(t_ngn *ngn)
{
	size_t	n;
	size_t	x;
	size_t	y;

	ngn->sprite.num = ngn_int_count_sprites(ngn->mx, ngn->mx_wd, ngn->mx_ht);
	ngn->sprite.pos = (t_pos *)malloc(ngn->sprite.num * sizeof(t_pos));
	n = 0;
	x = 0;
	y = 0;
	while (y < ngn->mx_ht && !(x = 0))
	{
		while (x < ngn->mx_wd)
		{
			if (ngn->mx[y][x] == 2)
			{
				ngn->sprite.pos[n].x = x + 0.5;
				ngn->sprite.pos[n].y = y + 0.5;
				n++;
			}
			x++;
		}
		y++;
	}
}

size_t	ngn_int_count_sprites(int **mx, size_t x, size_t y)
{
	size_t	x_buff;
	size_t	n;

	n = 0;
	x_buff = x;
	while (y--)
	{
		x = x_buff;
		while (x--)
		{
			if (mx[y][x] == 2)
				n++;
		}
	}
	return (n);
}
