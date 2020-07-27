/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_sprites_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:05:17 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/25 20:02:31 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int	ngn_int_sprites_init(t_ngn *ngn)
{
	if (!(ngn->sprite.z_buffer = (double *)malloc(ngn->wd * sizeof(double))))
	{
		g_ngnerr = NGN_MEMERR;
		return (EXIT_FAILURE);
	}
	if (!(ngn->sprite.distance =
				(double *)malloc(ngn->sprite.num * sizeof(double))))
	{
		g_ngnerr = NGN_MEMERR;
		return (EXIT_FAILURE);
	}
	if (!(ngn->sprite.order = (int *)malloc(ngn->sprite.num * sizeof(int))))
	{
		g_ngnerr = NGN_MEMERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
