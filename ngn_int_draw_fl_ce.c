/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_draw_fl_ce.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 20:33:35 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/23 21:05:41 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_draw_fl_ce(t_ngn *ngn, size_t x, void (*draw)(int, int, int))
{
	int	i;

	i = 0;
	while (i < ngn->ht)
	{
		if (i <= ngn->camera.draw_start)
			draw(x, i, ngn->ceil.hex + 0xFF000000);
		else if (i > ngn->camera.draw_start && i < ngn->camera.draw_end)
			i += ngn->camera.line_height - 2;
		else if (i >= ngn->camera.draw_end)
			draw(x, i, ngn->floor.hex + 0xFF000000);
		i++;
	}
}
