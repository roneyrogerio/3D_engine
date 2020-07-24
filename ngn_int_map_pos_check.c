/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_map_pos_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:41:16 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/23 16:27:35 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int	ngn_int_if_wall(int pos)
{
	if (pos != 1)
		return (0);
	return (1);
}

int	ngn_int_if_player(int pos)
{
	if (pos == 78 ||
		pos == 83 ||
		pos == 69 ||
		pos == 87)
		return (1);
	return (0);
}
