/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:30:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/08 07:53:31 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NGN_INT_H
# define NGN_INT_H
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "lbmp.h"

typedef struct	s_map
{
	int	sz;
	int	mgn_x;
	int	mgn_y;
}				t_map;

typedef struct	s_texture
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*s;
}				t_texture;

typedef struct	s_player
{
	double	x;
	double	y;
	double	radius;
	int		turn;
	int		walk;
	int		side;
	double	angle;
	double	move_speed;
	double	turn_speed;
}				t_player;

typedef struct	s_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_argb;

typedef union	u_color
{
	t_argb		argb;
	uint32_t	hex;
}				t_color;

typedef struct	s_ngn
{
	int			wd;
	int			ht;
	int			**mx;
	int			mx_wd;
	int			mx_ht;
	t_texture	texture;
	t_color		ceil;
	t_color		floor;
	t_map		map;
	t_player	player;
}				t_ngn;

typedef struct	s_circle
{
	int	x;
	int	y;
	int	radius;
	int	color;
}				t_circle;

typedef struct	s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef	struct	s_pseudo_fd
{
	char	buf[100];
	int		size;
	int		offset;
	t_list	*line_liststart;
	t_list	*line_listlast;
	int		list_hasline;
	int		list_linelen;
	int		i;
}				t_pseudo_fd;

int				g_ngnerr;
int				rgb_map(int p);
void			ngn_int_circle(t_circle *circle, void (*draw)(int, int, int));
int				list2line(t_pseudo_fd *pfd, char **line);
int				markup(t_pseudo_fd *pfd);
t_list			*lst_new(t_pseudo_fd *pfd);
int				ngn_int_getline(int fd, char **line);
void			ngn_player_draw(t_ngn *ngn, void (*frame_draw)(int, int, int));
void			ngn_map_draw(t_ngn *ngn, void (*frame_draw)(int, int, int));
int				ngn_int_config_header(int fd, t_ngn *ngn);
int				ngn_int_config_save_header(char **spline, t_ngn *ngn);
int				ngn_int_config_save_resolution(char **spline, t_ngn *ngn);
int				ngn_int_config_save_texture(char **spline, t_ngn *ngn);
int				ngn_int_config_save_color(char **spline, t_ngn *ngn);
char			**ngn_int_splittedline(int fd);
void			ngn_int_resize(t_ngn *ngn);
void			ngn_set_window_size(t_ngn *ngn, int wd, int ht);
void			ngn_destroy(t_ngn *ngn);

# define NGN_MEMERR 1
# define NGN_OPENERR 2
# define NGN_FILERR 3
# define NGN_FDERR 4
# define NGN_RESERR 5
# define NGN_TEXERR 6
# define NGN_TEXFILERR 7
# define NGN_TEXNFERR 8
# define NGN_COLERR 9
#endif
