/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_set_start_angle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:39:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/23 20:55:02 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_set_start_angle(t_ngn *ngn, size_t pos)
{
	if (pos == 78)
		ngn_int_set_start_north(ngn);
	else if (pos == 83)
		ngn_int_set_start_south(ngn);
	else if (pos == 87)
		ngn_int_set_start_west(ngn);
	else if (pos == 69)
		ngn_int_set_start_east(ngn);
}

void	ngn_int_set_start_north(t_ngn *ngn)
{
	ngn->camera.dir_x = 0;
	ngn->camera.dir_y = -1;
	ngn->camera.plane_x = -0.66;
	ngn->camera.plane_y = 0;
}

void	ngn_int_set_start_south(t_ngn *ngn)
{
	ngn->camera.dir_x = 0;
	ngn->camera.dir_y = 1;
	ngn->camera.plane_x = 0.66;
	ngn->camera.plane_y = 0;
}

void	ngn_int_set_start_west(t_ngn *ngn)
{
	ngn->camera.dir_x = -1;
	ngn->camera.dir_y = 0;
	ngn->camera.plane_x = 0;
	ngn->camera.plane_y = 0.66;
}

void	ngn_int_set_start_east(t_ngn *ngn)
{
	ngn->camera.dir_x = 1;
	ngn->camera.dir_y = 0;
	ngn->camera.plane_x = 0;
	ngn->camera.plane_y = -0.66;
}
