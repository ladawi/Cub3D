/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:31:08 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/08 17:20:05 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../MinilibX/includes/mlx.h"

# define X_EVENT_EXIT			17
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

// # define KEY_W			13
// # define KEY_A			0
// # define KEY_S			1
// # define KEY_D			2
// # define KEY_Q			12
// # define KEY_E			14
// # define KEY_J			38
// # define KEY_LEFT		123
// # define KEY_RIGHT		124
// # define KEY_FORWARD 	126
// # define KEY_BACKWARD	125

# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_Q					113
# define KEY_E					101
# define KEY_J					38
# define KEY_LEFT				65361
# define KEY_RIGHT				65363
# define KEY_FORWARD 			65362
# define KEY_BACKWARD			65364
# define KEY_ESC				65307

# define NBTEXTURES				6
# define M_2PI					6.28318530718

# define UDIV  					1
# define VDIV  					1
# define VMOVE  				1.0

# define SOUTH					0
# define NORTH					1
# define EAST					2
# define WEST					3

typedef struct	s_game
{
	float	fplayerx;
	float	fplayery;
	float	frotaleft;
	float	frotaright;
	float	fvforward;
	float	fvbackward;
	float	fstrafeleft;
	float	fstraferight;
	int		nmapwidth;
	int		nmapheight;
	double	ddirx;
	double	ddiry;
	double	dplanex;
	double	dplaney;
	char	prevpos;
}				t_game;

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_image
{
	void	*img;
	int		*str;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_tex
{
	char	*path;
	void	*tex;
	int		*str;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_tex;

typedef struct	s_textures
{
	t_tex		tex[NBTEXTURES];
	t_image		sprite;
	int			s_x;
	int			s_y;
}				t_texture;

typedef struct	s_sprit
{
	double		x;
	double		y;
	double		dist;
	int			order;
	int			texture;
}				t_sprit;

typedef struct	s_sprites
{
	t_sprit		*spritespos;
	int			numsprites;
	int			*spriteorder;
	double		*spritedistance;
}				t_sprites;

typedef struct	s_config
{
	int		l;
	int		y;
	int		indexsprite;
}				t_config;

typedef struct	s_map
{
	int		maxheight;
	int		maxwidth;
}				t_map;

typedef struct	s_minimap
{
	int		x;
	int		y;
	int		mapx;
	int		mapy;
	int		scalex;
	int		scaley;
}				t_minimap;

typedef struct	s_sdata
{
	int		*spriteorder;
	double	*spritedistance;
	int		fix;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		vmovescreen;
	int		spriteheight;
	int		drawstarty;
	int		drawstartx;
	int		drawendx;
	int		drawendy;
	int		spritewidth;
	int		stripe;
	int		texx;
	int		texy;
}				t_sdata;

typedef	struct	s_var
{
	int		x;
	int		y;
	int		z;
	int		i;
	int		u;
	int		h;
	int		d;
}				t_var;

typedef struct	s_ray
{
	int		hit;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		texy;
	int		side;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	camerax;
	double	raydirx;
	double	raydiry;
	float	time_elapsed;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texx;
	double	wallx;
	int		color;
}				t_ray;

typedef struct	s_header
{
	short		type;
	int			size;
	int			start;
	int			header_size;
	short		planes;
	short		bpp;
	int			raw_size;
	int			res;
}				t_header;

typedef struct	s_color
{
	unsigned int	tab[3];
}				t_color;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			fd;
	int			fd2;
	int			res_width;
	int			res_height;
	int			max_res_width;
	int			max_res_height;
	char		*idparsing;
	char		*error;
	int			f_color;
	int			c_color;
	char		*str;
	char		**map;
	int			*image;
	int			sizeline;
	char		*line2;
	t_sprites	sprites;
	t_config	config;
	t_map		mapcarac;
	t_game		game;
	t_texture	tex;
	t_image		simg;
	t_minimap	minimap;
	t_var		var;
	t_sdata		sdata;
	t_ray		ray;
	t_color		color;
}				t_data;

char			*initgame(t_data *data, t_texture *textures);
char			*initdata(t_data *data, t_texture *textures, char *pathconfig);
char			*parsing(t_data *data, t_texture *textures, char *line);
char			*get_resolution(t_data *data, char *line);
char			*get_texture_wall(t_data *data, char *line, int nb);
char			*get_sprite_texture(t_data *data, char *line);
char			*get_color(t_data *data, char *line);
char			*get_map_heart_2(t_data *data, char *line, int i);
void			ft_rotate_player(t_data *data, double angle);
char			*get_map_2(t_data *data);
char			*drawsprites(t_data *data, double *zbuffer);
char			*check_map2(t_data *data, int p, int u, int i);
char			*check_map3(t_data *data, int p, int u, int i);
char			*check_map(t_data *data);
char			*check_map_2(t_data *data);
char			*get_map(t_data *data, char *line);
char			*ft_screenshot(t_data *data);
int				gameloop(t_data *data);
int				ft_minimap(t_data *data);
char			*ft_spritesorting(t_data *data);
int				keypress(int keycode, t_data *data);
int				keyrelease(int keycode, t_data *data);
void			freeall(t_data *data);
int				exitwindow(t_data *data);
int				exit_game(t_data *data, int code);
void			update_window(t_data *data);
void			move_player_front(t_data *data, float time_elapsed);
void			move_player_back(t_data *data, float time_elapsed);
void			move_player_left(t_data *data, float time_elapsed);
void			move_player_right(t_data *data, float time_elapsed);
void			drawcursor(t_data *data);
void			ft_putpixel(t_data *data, int side, int x, int y);
void			gameloop2(t_data *data, int x);
void			gameloop3(t_data *data);
void			set_tex(t_data *data);
void			draw_column(t_data *data, int x);

#endif
