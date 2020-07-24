/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:30:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/24 10:25:47 by rde-oliv         ###   ########.fr       */
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

typedef struct	s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		hit;
	int		side;
	void	*tex;
}				t_camera;

typedef struct	s_player
{
	double	x;
	double	y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		walk;
	int		turn;
	double	move_speed;
	double	turn_speed;
	double	radius;
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
	size_t		mx_wd;
	size_t		mx_ht;
	t_texture	texture;
	t_color		ceil;
	t_color		floor;
	t_map		map;
	t_player	player;
	t_camera	camera;
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

typedef struct	s_obj
{
	size_t	x;
	size_t	y;
}				t_obj;

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
int				ngn_int_config_map(int fd, t_ngn *ngn);
void			*ngn_int_config_map2lst(int fd, t_ngn *ngn);
void			ngn_int_config_lst2matrix(void *line, void *mx);
int				ngn_int_config_start_pos(t_ngn *ngn);
int				**ngn_int_matrix_creat(size_t x, size_t y);
int				ngn_int_matrix_validn(int **mx, size_t wd, size_t ht);
int				ngn_int_mx_left_check(int **mx, t_obj pos);
int				ngn_int_mx_right_check(int **mx, size_t wd, t_obj pos);
int				ngn_int_mx_top_check(int **mx, t_obj pos);
int				ngn_int_mx_bottom_check(int **mx, size_t ht, t_obj pos);
void			ngn_int_matrix_clear(int **matrix);
char			**ngn_int_splittedline(int fd);
void			ngn_int_resize(t_ngn *ngn);
void			ngn_set_window_size(t_ngn *ngn, int wd, int ht);
void			ngn_int_set_start_angle(t_ngn *ngn, size_t pos);
void			ngn_int_set_start_north(t_ngn *ngn);
void			ngn_int_set_start_south(t_ngn *ngn);
void			ngn_int_set_start_west(t_ngn *ngn);
void			ngn_int_set_start_east(t_ngn *ngn);
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
# define NGN_MAPERR 10
#endif
