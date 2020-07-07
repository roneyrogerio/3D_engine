/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 03:48:36 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/01 08:47:01 by rde-oliv         ###   ########.fr       */
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
	free(ngn);
}
