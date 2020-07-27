/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:38:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/26 20:23:34 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_texture(t_ngn *ngn, int x, void (*draw)(int, int, int))
{
	t_player	*ply;
	t_camera	*cam;
	int			y;
	uint32_t	color;

	ply = &ngn->player;
	cam = &ngn->camera;
	ngn_int_select_texture(ngn);
	ngn_int_tex_calc(ply, cam);
	cam->step = 1.0 * lbmp_get_height(cam->tex) / cam->line_height;
	cam->tex_pos = (cam->draw_start - ngn->ht / 2 + cam->line_height / 2)
		* cam->step;
	y = cam->draw_start;
	while (y < cam->draw_end)
	{
		cam->tex_pos += cam->step;
		color = lbmp_get_pixel_color(cam->tex, cam->tex_x, cam->tex_pos);
		if (cam->side == 1)
			color = (color >> 1) & 8355711;
		draw(ngn->wd - x - 1, y, color + 0xFF000000);
		y++;
	}
}

void	ngn_int_select_texture(t_ngn *ngn)
{
	if (ngn->camera.side == 1 && ngn->camera.ray_dir_y > 0)
		ngn->camera.tex = ngn->texture.so;
	else if (ngn->camera.side == 1 && ngn->camera.ray_dir_y < 0)
		ngn->camera.tex = ngn->texture.no;
	else if (ngn->camera.side == 0 && ngn->camera.ray_dir_x < 0)
		ngn->camera.tex = ngn->texture.ea;
	else
		ngn->camera.tex = ngn->texture.we;
}

void	ngn_int_tex_calc(t_player *ply, t_camera *cam)
{
	if (cam->side == 0)
		cam->wall_x = ply->y + cam->perp_wall_dist * cam->ray_dir_y;
	else
		cam->wall_x = ply->x + cam->perp_wall_dist * cam->ray_dir_x;
	cam->wall_x -= floor((cam->wall_x));
	cam->tex_x = cam->wall_x * lbmp_get_height(cam->tex);
	if (cam->side == 0 && cam->ray_dir_x > 0)
		cam->tex_x = lbmp_get_height(cam->tex) - cam->tex_x - 1;
	if (cam->side == 1 && cam->ray_dir_y < 0)
		cam->tex_x = lbmp_get_height(cam->tex) - cam->tex_x - 1;
}
