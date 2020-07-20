/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_set_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:43:28 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/20 11:44:49 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_set_walk(t_ngn *ngn, int value)
{
	ngn->player.walk = value;
}

void	ngn_set_turn(t_ngn *ngn, int value)
{
	ngn->player.turn = value;
}

void	ngn_movement_update(t_ngn *ngn)
{
	t_player	*p;
	int			**mx;
	double		old_dir_x;
	double		old_plane_x;

	p = &ngn->player;
	mx = ngn->mx;
	if (!mx[(int)(p->y)][(int)(p->x - (p->walk * p->dir_x) * p->move_speed)])
		p->x -= p->walk * (p->dir_x * p->move_speed);
	if (!mx[(int)(p->y - (p->walk * p->dir_y) * p->move_speed)][(int)(p->x)])
		p->y -= p->walk * (p->dir_y * p->move_speed);
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(p->turn * p->turn_speed)
		- p->dir_y * sin(p->turn * p->turn_speed);
	p->dir_y = old_dir_x * sin(p->turn * p->turn_speed)
		+ p->dir_y * cos(p->turn * p->turn_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(p->turn * p->turn_speed)
		- p->plane_y * sin(p->turn * p->turn_speed);
	p->plane_y = old_plane_x * sin(p->turn * p->turn_speed)
		+ p->plane_y * cos(p->turn * p->turn_speed);
}
