/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:30:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/03 03:06:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NGN_H
# define NGN_H

extern int	g_ngnerr;
void		ngn_camera(void *core, void (*draw)(int, int, int));
void		ngn_mini_map(void *ngn, void (*draw)(int, int, int));
void		*ngn_init(char *path);
void		ngn_get_window_size(void *ngn, int *wd, int *ht);
void		ngn_set_window_size(void *ngn, int wd, int ht);
void		ngn_set_walk(void *ngn, int value);
void		ngn_set_turn(void *ngn, int value);
void		ngn_set_side(void *ngn, int value);
void		ngn_movement_update(void *ngn);
const char	*ngn_strerror(int code);
void		ngn_destroy(void *ngn);

#endif
