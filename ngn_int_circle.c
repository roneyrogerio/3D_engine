/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 00:01:59 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/24 00:09:24 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_int_circle(t_circle *circle, void (*draw)(int, int, int))
{
	int	x;
	int	y;

	y = -circle->radius;
	while (y <= circle->radius)
	{
		x = -circle->radius;
		while (x <= circle->radius)
		{
			if (x * x + y * y <= circle->radius * circle->radius + 1)
				draw(x + circle->x, y + circle->y, circle->color);
			x++;
		}
		y++;
	}
}
