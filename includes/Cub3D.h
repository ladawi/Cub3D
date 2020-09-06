/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:31:08 by ladawi            #+#    #+#             */
/*   Updated: 2020/09/06 16:39:43 by ladawi           ###   ########.fr       */
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

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_Q			113
# define KEY_E			101
# define KEY_J			38
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_FORWARD 	65362
# define KEY_BACKWARD	65364
# define KEY_ESC		65307


# define NBTEXTURES		9
# define M_2PI			6.28318530718

# define UDIV  1
# define VDIV  1
# define VMOVE  1.0

# define SOUTH	0
# define NORTH	1
# define EAST	2
# define WEST	3

typedef struct	game_s
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
	double	dDirX;
	double	dDirY;
	double	dPlaneX;
	double	dPlaneY;
	char	PrevPos;
}				game_t;

typedef struct	pos_s
{
	double	x;
	double	y;
}				pos_t;

typedef struct	image_s
{
	void	*img;
	int		*str;
	int		bpp;
	int		size_line;
	int		endian;
}				image_t;

typedef struct tex_s
{
	char	*path;
	void	*tex;
	int		*str;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				tex_t;


typedef struct	textures_s
{
	tex_t		TEX[NBTEXTURES];
	
	image_t		Sprite;
	int			S_x;
	int			S_y;
}				texture_t;

typedef struct Sprit_s
{
	double		x;
	double		y;
	double		dist;
	int			order;
	int			texture;
}				Sprit_t;

typedef struct	Sprites_s
{
	Sprit_t		*SpritesPos;
	double		*ZBuffer;
	int			numSprites;
	int 		*spriteOrder;
	double		*spriteDistance;
}				Sprites_t;

typedef struct	Config_s
{
	int		l;
	int		y;
	int		indexSprite;
}				Config_t;

typedef struct	Map_s
{
	int		MaxHeight;
	int		MaxWidth;
}				Map_t;

typedef struct Minimap_s
{
	int		x;
	int		y;
	int		mapx;
	int		mapy;
	int		scalex;
	int		scaley;
}				Minimap_t;

typedef struct Sdata_s
{
	int		*spriteOrder;
	double	*spriteDistance;
	int		fix;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		SpriteHeight;
	int		drawStartY;
	int		drawStartX;
	int		drawEndX;
	int		drawEndY;
	int		spriteWidth;
	int		stripe;
	int		texX;
	int		texY;
}				Sdata_t;

typedef	struct Var_s
{
	int		x;
	int		y;
	int		z;
	int		i;
	int		u;
	int		h;
	int		d;
}				Var_t;

typedef struct ray_s
{
	int hit;
	int mapx;
   	int mapy;
	int stepx;
	int stepy;
	int texy;
	int side;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	double camerax;
	double raydirx;
	double raydiry;
	float time_elapsed;

	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texx;
	double	wallx;
	int		color;
}				ray_t;

typedef struct header_s
{
	short		type;
	int			size;
	int			start;
	int			header_size;
	short		planes;
	short		bpp;
	int			raw_size;
	int			res;
}				header_t;

typedef struct	Color_s
{
	unsigned int tab[3];
}				Color_t;


typedef struct	data_s
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
	char		*Error;
	int			F_color;
	int			C_color;
	char		*test;
	char		**map;
	int			*image;
	int			sizeline;
	char		*line2;
	Sprites_t	Sprites;
	Config_t	Config;
	Map_t		Map;
	/* Game loop data */
	game_t		game;
	texture_t	tex;
	/* Window */
	image_t		sImg;
	Minimap_t	Minimap;
	Var_t		Var;
	Sdata_t		Sdata;
	ray_t		ray;
	Color_t		color;
}                 data_t;

char		*initgame(data_t *data, texture_t *textures);
char		*initdata(data_t *data, texture_t *textures, char *pathconfig);
char		*parsing(data_t *data, texture_t *textures, char *line);
char		*get_resolution(data_t *data, char *line);
char		*get_texture_wall(data_t *data, char *line, int nb);
char		*get_sprite_texture(data_t *data, char *line);
char		*get_color(data_t *data, char *line);
char		*get_map_heart_2(data_t *data, char *line, int i);
void		ft_rotate_player(data_t *data, double angle);
char		*get_map_2(data_t *data);
char		*drawsprites(data_t *data, double *ZBuffer);
char		*check_map2(data_t *data, int p, int u, int i);
char		*check_map3(data_t *data, int p, int u, int i);
char		*check_map(data_t *data);
char		*check_map_2(data_t *data);
char		*get_map(data_t *data, char *line);
char		*ft_screenshot(data_t *data);
int			gameloop(data_t *data);
int			ft_minimap(data_t *data);
char		*ft_spritesorting(data_t *data);
int			keypress(int keycode, data_t *data);
int			keyrelease(int keycode, data_t *data);
void		freeall(data_t *data);
int			exitwindow(data_t *data);
int			exit_game(data_t *data, int code);
void		update_window(data_t *data);
void		move_player_front(data_t *data, float time_elapsed);
void		move_player_back(data_t *data, float time_elapsed);
void		move_player_left(data_t *data, float time_elapsed);
void		move_player_right(data_t *data, float time_elapsed);
void		drawcursor(data_t *data);
void		ft_putpixel(data_t *data, int side, int x, int y);
void		gameloop2(data_t *data, int x);
void		gameloop3(data_t *data);
void		set_tex(data_t *data);
void		draw_column(data_t *data, int x);

#endif
