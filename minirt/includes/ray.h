/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:56:04 by jkasongo          #+#    #+#             */
/*   Updated: 2022/11/18 02:45:26 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"
# include "color.h"

typedef enum e_hittable_type
{
	e_hit_sphere,
	e_hit_sphere_spec,
	e_hit_plane,
	e_hit_triangle,
	e_hit_cylinder,
	e_hit_light,
}	t_hit_type;

typedef enum e_hittable_composition
{
	e_metallic,
	e_plastic,
	e_glass
}	t_composition;

typedef enum e_hittable_pattern
{
	e_normal_pattern,
	e_stripped_pattern,
	e_ring_pattern,
	e_ring_gradient,
	e_ring_image,
}	t_pattern;

typedef struct s_material
{
	double			shininess;
	t_composition	type;
	t_pattern		pattern;
	double			reflexive;
	double			diffuse;
	double			specular;
	t_color			main;
	t_color			second;
	t_color			third;
}	t_material;

typedef struct s_hittable
{
	t_hit_type	type;
	t_point		o;
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_m4		tr;
	t_m4		inv_tr;
	t_m4		inv_tr_trans;
	t_v3		trans;
	t_v3		scale;
	t_v3		angles;
	double		radius;
	double		h;
	t_v3		dir;
	char		*name;
	t_material	material;
}	t_hittable;

typedef struct s_ray
{
	t_point		o;
	t_v3		dir;
}	t_ray;

typedef struct s_camera
{
	double	fov;
	double	hsize;
	double	vsize;
	double	aspect;
	double	pixel_dx;
	double	pixel_dy;
	double	half_height;
	double	half_width;
	t_v3	rot_angles;
	t_point	eye;
	t_point	look_at;
	t_m4	transform;
	t_m4	inv_tr;
}	t_cam;

typedef struct s_hit_record
{
	bool		intersection;
	t_hit_type	type;
	t_hittable	*object;
	double		t;
	double		m;
	double		t_trace[2];
	t_ray		*ray;
	t_point		h_point;
	t_point		h_point_obj_coord;
	t_point		acne_p;
	t_v3		normal;
	t_v3		r;
	bool		inside;
}	t_hit;

/*
 * Build the ray with origin and direction vector
 * return a *t_ray to be freed
*/
static inline t_ray	*build_ray(t_point origin, t_v3 direction)
{
	t_ray	*ray;

	ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (ray)
	{
		ray->o = origin;
		ray->dir = direction;
	}
	return (ray);
}

t_ray	*ray_for_pixel(t_cam *cam, double px, double py);
t_ray	*get_transformed_ray(t_ray *ray, t_m4 transform, t_v3 sp_o);
t_v3	get_vector_tr(t_v3 v, t_m4 transform, t_v3 origin);

/*
 * Return a Point according to t with a ray, parametric equation.
 * equation is point = ray_origin + (t * ray_dir)
 * ray dir vector need to be normalized to be correct
*/
static inline t_point	get_point_on_ray_at(const double t, t_ray *ray)
{
	t_point	a;

	a.x = ray->o.x + (t * ray->dir.x);
	a.y = ray->o.y + (t * ray->dir.y);
	a.z = ray->o.z + (t * ray->dir.z);
	return (a);
}

#endif
