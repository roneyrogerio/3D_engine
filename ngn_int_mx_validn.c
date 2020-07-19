/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_mx_validn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:07:00 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/19 08:41:49 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int	ngn_int_mx_validn(int **mx, size_t wd, size_t ht)
{
	t_obj	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y >= 0)
	{
		if ((mx[pos.y][pos.x] == 0 || mx[pos.y][pos.x] == 2) && (
				ngn_int_mx_left(mx, pos) == EXIT_FAILURE ||
				ngn_int_mx_right(mx, wd, pos) == EXIT_FAILURE ||
				ngn_int_mx_top(mx, pos) == EXIT_FAILURE ||
				ngn_int_mx_bottom(mx, ht, pos) == EXIT_FAILURE))
			return (EXIT_FAILURE);
		pos.x++;
		if (pos.x == wd && !(pos.x = 0))
			pos.y++;
		if (pos.y == ht)
			break ;
	}
	return (EXIT_SUCCESS);
}

int	ngn_int_mx_left(int **mx, t_obj pos)
{
	int	x;

	x = pos.x;
	while (x >= 0)
	{
		if (mx[pos.y][x] == 1)
			break ;
		if (mx[pos.y][x] == -1 || x == 0)
			return (EXIT_FAILURE);
		x -= 1;
	}
	return (EXIT_SUCCESS);
}

int	ngn_int_mx_right(int **mx, size_t wd, t_obj pos)
{
	size_t	x;

	x = pos.x;
	while (x < wd)
	{
		if (mx[pos.y][x] == 1)
			break ;
		if (mx[pos.y][x] == -1 || x == wd - 1)
			return (EXIT_FAILURE);
		x += 1;
	}
	return (EXIT_SUCCESS);
}

int	ngn_int_mx_top(int **mx, t_obj pos)
{
	int	y;

	y = pos.y;
	while (y >= 0)
	{
		if (mx[y][pos.x] == 1)
			break ;
		if (mx[y][pos.x] == -1 || y == 0)
			return (EXIT_FAILURE);
		y -= 1;
	}
	return (EXIT_SUCCESS);
}

int	ngn_int_mx_bottom(int **mx, size_t ht, t_obj pos)
{
	size_t	y;

	y = pos.y;
	while (y < ht)
	{
		if (mx[y][pos.x] == 1)
			break ;
		if (mx[y][pos.x] == -1 || y == ht - 1)
			return (EXIT_FAILURE);
		y += 1;
	}
	return (EXIT_SUCCESS);
}
