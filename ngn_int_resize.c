/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 03:21:10 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/20 11:46:52 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_resize(t_ngn *ngn)
{
	if (ngn->mx_wd == 0 && ngn->mx_ht == 0)
		return ;
	ngn->player.radius = 0.15;
	ngn->player.dir_x = 0;
	ngn->player.dir_y = -1;
	ngn->player.plane_x = 0;
	ngn->player.plane_y = 0.66;
	ngn->player.move_speed = 0.00000004 * ngn->wd * ngn->ht;
	ngn->player.turn_speed = 2 * (M_PI / 180);
	ngn->map.sz = (ngn->ht < ngn->wd ? ngn->ht : ngn->wd) / 2;
	ngn->map.sz /= ngn->mx_ht > ngn->mx_wd ? ngn->mx_ht : ngn->mx_wd;
	ngn->map.mgn_x = ngn->wd / 20;
	ngn->map.mgn_y = ngn->ht / 16;
}
