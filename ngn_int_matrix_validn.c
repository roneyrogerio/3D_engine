/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_matrix_validn.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:07:00 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/23 10:12:21 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int	ngn_int_matrix_validn(int **mx, size_t wd, size_t ht)
{
	t_obj	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y >= 0 && pos.y < ht)
	{
		if ((mx[pos.y][pos.x] == 0 || mx[pos.y][pos.x] == 2 ||
			mx[pos.y][pos.x] == 78 || mx[pos.y][pos.x] == 83 ||
			mx[pos.y][pos.x] == 69 || mx[pos.y][pos.x] == 87) && (
				ngn_int_mx_left_check(mx, pos) == EXIT_FAILURE ||
				ngn_int_mx_right_check(mx, wd, pos) == EXIT_FAILURE ||
				ngn_int_mx_top_check(mx, pos) == EXIT_FAILURE ||
				ngn_int_mx_bottom_check(mx, ht, pos) == EXIT_FAILURE))
			return (EXIT_FAILURE);
		else if (mx[pos.y][pos.x] != -1 && mx[pos.y][pos.x] != 0 &&
			mx[pos.y][pos.x] != 2 && mx[pos.y][pos.x] != 78 &&
			mx[pos.y][pos.x] != 83 && mx[pos.y][pos.x] != 69 &&
			mx[pos.y][pos.x] != 87 && mx[pos.y][pos.x] != 1)
			return (EXIT_FAILURE);
		pos.x++;
		if (pos.x == wd && !(pos.x = 0))
			pos.y++;
	}
	return (EXIT_SUCCESS);
}

int	ngn_int_mx_left_check(int **mx, t_obj pos)
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

int	ngn_int_mx_right_check(int **mx, size_t wd, t_obj pos)
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

int	ngn_int_mx_top_check(int **mx, t_obj pos)
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

int	ngn_int_mx_bottom_check(int **mx, size_t ht, t_obj pos)
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
