/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_sprites_draw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:19:58 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/28 16:29:08 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_sprites_draw(t_ngn *ngn, void (*draw)(int, int, int))
{
	size_t		i;

	ngn_int_sprites_select(ngn);
	ngn_int_sprites_sort(&ngn->sprite);
	i = 0;
	while (i < ngn->sprite.num)
	{
		ngn_int_sprites_calc(&ngn->sprite, ngn, &ngn->camera, i);
		ngn->sprite.stripe = ngn->sprite.draw_start_x;
		ngn_int_sprites_vert(ngn, draw, 0);
		i++;
	}
}

void	ngn_int_sprites_vert(t_ngn *ngn, void (*draw)(int, int, int), int y)
{
	while (ngn->sprite.stripe < ngn->sprite.draw_end_x)
	{
		ngn->sprite.tex_x = (256 * (ngn->sprite.stripe
					- (-ngn->sprite.wd / 2 + ngn->sprite.screen_x))
					* lbmp_get_width(ngn->texture.s) / ngn->sprite.wd) / 256;
		if (ngn->sprite.transform_y > 0 && ngn->sprite.stripe > 0
				&& ngn->sprite.stripe < ngn->wd && ngn->sprite.transform_y <
				ngn->sprite.z_buffer[ngn->sprite.stripe])
		{
			y = ngn->sprite.draw_start_y;
			while (y < ngn->sprite.draw_end_y)
			{
				ngn->sprite.tex_y = ((((y - ngn->sprite.v_move_screen) * 256
					- ngn->ht * 128 + ngn->sprite.ht * 128)
					* lbmp_get_height(ngn->texture.s)) / ngn->sprite.ht) / 256;
				draw(ngn->wd - ngn->sprite.stripe - 1, y,
					lbmp_get_pixel_color(ngn->texture.s,
						ngn->sprite.tex_x, ngn->sprite.tex_y));
				y++;
			}
		}
		ngn->sprite.stripe++;
	}
}

void	ngn_int_sprites_calc(t_sprite *sp, t_ngn *ngn, t_camera *cam, int i)
{
	sp->x = sp->pos[sp->order[i]].x - ngn->player.x;
	sp->y = sp->pos[sp->order[i]].y - ngn->player.y;
	sp->inv_det = 1.0 / (cam->plane_x * cam->dir_y - cam->dir_x * cam->plane_y);
	sp->transform_x = sp->inv_det * (cam->dir_y * sp->x - cam->dir_x * sp->y);
	sp->transform_y = sp->inv_det
		* (-cam->plane_y * sp->x + cam->plane_x * sp->y);
	sp->screen_x = (ngn->wd / 2) * (1 + sp->transform_x / sp->transform_y);
	sp->v_move_screen = 0.0 / sp->transform_y;
	sp->ht = fabs(ngn->ht / (sp->transform_y));
	sp->draw_start_y = -sp->ht / 2 + ngn->ht / 2 + sp->v_move_screen;
	if (sp->draw_start_y < 0)
		sp->draw_start_y = 0;
	sp->draw_end_y = sp->ht / 2 + ngn->ht / 2 + sp->v_move_screen;
	if (sp->draw_end_y >= ngn->ht)
		sp->draw_end_y = ngn->ht - 1;
	sp->wd = fabs(ngn->ht / (sp->transform_y));
	sp->draw_start_x = -sp->wd / 2 + sp->screen_x;
	if (sp->draw_start_x < 0)
		sp->draw_start_x = 0;
	sp->draw_end_x = sp->wd / 2 + sp->screen_x;
	if (sp->draw_end_x >= ngn->wd)
		sp->draw_end_x = ngn->wd - 1;
}

void	ngn_int_sprites_select(t_ngn *ngn)
{
	size_t	i;

	i = 0;
	while (i < ngn->sprite.num)
	{
		ngn->sprite.order[i] = i;
		ngn->sprite.distance[i] = ((ngn->player.x - ngn->sprite.pos[i].x)
				* (ngn->player.x - ngn->sprite.pos[i].x) + (ngn->player.y
					- ngn->sprite.pos[i].y) * (ngn->player.y
						- ngn->sprite.pos[i].y));
		i++;
	}
}

void	ngn_int_sprites_sort(t_sprite *sprite)
{
	unsigned int	i;
	int				distance_tmp;
	int				tmp;

	i = 0;
	while (i < sprite->num)
	{
		if (i == sprite->num - 1)
			break ;
		if (sprite->distance[i] < sprite->distance[i + 1])
		{
			distance_tmp = sprite->distance[i];
			sprite->distance[i] = sprite->distance[i + 1];
			sprite->distance[i + 1] = distance_tmp;
			tmp = sprite->order[i];
			sprite->order[i] = sprite->order[i + 1];
			sprite->order[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}
