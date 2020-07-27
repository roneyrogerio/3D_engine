/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 03:48:36 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/25 20:10:38 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_destroy(t_ngn *ngn)
{
	if (ngn == NULL)
		return ;
	lbmp_destroy(ngn->texture.no);
	lbmp_destroy(ngn->texture.so);
	lbmp_destroy(ngn->texture.we);
	lbmp_destroy(ngn->texture.ea);
	lbmp_destroy(ngn->texture.s);
	ngn_int_matrix_clear(ngn->mx);
	free(ngn->sprite.pos);
	free(ngn->sprite.z_buffer);
	free(ngn->sprite.distance);
	free(ngn->sprite.order);
	free(ngn);
}
