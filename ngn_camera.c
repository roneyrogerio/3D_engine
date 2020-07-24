/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 19:56:58 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/24 10:17:12 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_camera(t_ngn *ngn, void (*draw)(int, int, int))
{
	int			x;

	x = 0;
	while (x < ngn->wd)
	{
		ngn->camera.camera_x = 2 * x / (double)ngn->wd - 1;
		ngn_int_ray_calc(&ngn->player, &ngn->camera);
		ngn_int_dda(&ngn->player, &ngn->camera, ngn->mx);
		ngn_int_line_calc(&ngn->player, &ngn->camera, ngn->ht);
		ngn_int_texture(ngn, x, draw);
		ngn_int_draw_fl_ce(ngn, ngn->wd - x - 1, draw);
		x++;
	}
}

void	ngn_int_ray_calc(t_player *ply, t_camera *cam)
{
	cam->ray_dir_x = cam->dir_x + cam->plane_x * cam->camera_x;
	cam->ray_dir_y = cam->dir_y + cam->plane_y * cam->camera_x;
	ply->map_x = ply->x;
	ply->map_y = ply->y;
	cam->delta_dist_x = fabs(1 / cam->ray_dir_x);
	cam->delta_dist_y = fabs(1 / cam->ray_dir_y);
	cam->hit = 0;
	if (cam->ray_dir_x < 0 && (ply->step_x = -1))
		cam->side_dist_x = (ply->x - ply->map_x) * cam->delta_dist_x;
	else if ((ply->step_x = 1))
		cam->side_dist_x = (ply->map_x + 1.0 - ply->x) * cam->delta_dist_x;
	if (cam->ray_dir_y < 0 && (ply->step_y = -1))
		cam->side_dist_y = (ply->y - ply->map_y) * cam->delta_dist_y;
	else if ((ply->step_y = 1))
		cam->side_dist_y = (ply->map_y + 1.0 - ply->y) * cam->delta_dist_y;
}

void	ngn_int_dda(t_player *ply, t_camera *cam, int **mx)
{
	while (cam->hit == 0)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			ply->map_x += ply->step_x;
			cam->side = 0;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			ply->map_y += ply->step_y;
			cam->side = 1;
		}
		if (mx[ply->map_y][ply->map_x] == 1)
			cam->hit = 1;
	}
}

void	ngn_int_line_calc(t_player *ply, t_camera *cam, int ht)
{
	if (cam->side == 0)
		cam->perp_wall_dist = (ply->map_x - ply->x + (1 - ply->step_x) / 2) /
			cam->ray_dir_x;
	else
		cam->perp_wall_dist = (ply->map_y - ply->y + (1 - ply->step_y) / 2) /
			cam->ray_dir_y;
	cam->line_height = ht / cam->perp_wall_dist;
	cam->draw_start = -cam->line_height / 2 + ht / 2;
	if (cam->draw_start < 0)
		cam->draw_start = 0;
	cam->draw_end = cam->line_height / 2 + ht / 2;
	if (cam->draw_end >= ht)
		cam->draw_end = ht - 1;
}
