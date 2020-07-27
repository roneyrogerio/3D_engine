/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 03:21:10 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/27 14:51:08 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_resize(t_ngn *ngn)
{
	if (ngn->mx_wd == 0 && ngn->mx_ht == 0)
		return ;
	ngn->player.radius = 0.15;
	ngn->player.move_speed = 0.0000003 * ngn->wd * ngn->ht;
	ngn->player.turn_speed = (0.000009 * ngn->wd * ngn->ht) * (M_PI / 180);
	ngn->map.sz = (ngn->ht < ngn->wd ? ngn->ht : ngn->wd) / 3;
	ngn->map.sz /= ngn->mx_ht > ngn->mx_wd ? ngn->mx_ht : ngn->mx_wd;
	ngn->map.mgn_x = ngn->wd / 20;
	ngn->map.mgn_y = ngn->ht / 16;
}
