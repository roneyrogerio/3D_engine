/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_set_window_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 03:04:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/03 03:25:00 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

void	ngn_set_window_size(t_ngn *ngn, int wd, int ht)
{
	ngn->wd = wd;
	ngn->ht = ht;
	ngn_int_resize(ngn);
}
