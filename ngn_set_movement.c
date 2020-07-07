/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_set_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:43:28 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/14 04:44:05 by rde-oliv         ###   ########.fr       */
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

void	ngn_set_side(t_ngn *ngn, int value)
{
	ngn->player.side = value;
}

void	ngn_movement_update(t_ngn *ngn)
{
	double	move_step;
	double	side_step;
	double	side_angle;

	ngn->player.angle += ngn->player.turn * ngn->player.turn_speed;
	move_step = ngn->player.walk * ngn->player.move_speed;
	side_step = ngn->player.side * ngn->player.move_speed;
	side_angle = ngn->player.angle - (90 * (M_PI / 180));
	ngn->player.x += cos(ngn->player.angle) * move_step;
	ngn->player.y += sin(ngn->player.angle) * move_step;
	ngn->player.x += cos(side_angle) * side_step;
	ngn->player.y += sin(side_angle) * side_step;
}
