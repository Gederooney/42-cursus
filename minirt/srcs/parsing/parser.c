/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:51:36 by jkasongo          #+#    #+#             */
/*   Updated: 2022/10/23 14:51:38 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

bool	parse_light(char **tokens, t_app *app)
{
	t_light		*light;
	t_v3		v_color;

	app->error_message = "Error during parsing, On a light";
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	ft_push(app->scene->lights, light);
	if (!tokens_has_valid_params_nbr(tokens, 4))
		return (false);
	if (!parse_a_vector(tokens[1], &light->o))
		return (false);
	if (!parse_double_from_str(tokens[2], &light->cd))
		return (false);
	if (!parse_a_vector(tokens[3], &v_color))
		return (false);
	if (!all_vector_coord_are_in_range(0, 255, &v_color))
		return (false);
	if (light->cd < 0 || light->cd > 1.0f)
		return (false);
	if (light->cd < 0.01)
		light->cd = 0.1;
	light->color = make_color_vector(v_color, 1);
	light->color = v4_multi(light->cd, light->color);
	return (true);
}

bool	parse_ambiant_light(char **tokens, t_app *app)
{
	t_ambiant	ambiant;
	t_v3		v_color;

	app->error_message = "Error during parsing, On ambiant light";
	if (!tokens_has_valid_params_nbr(tokens, 3))
		return (false);
	if (!parse_double_from_str(tokens[1], &ambiant.intensity))
		return (false);
	if (!parse_a_vector(tokens[2], &v_color))
		return (false);
	if (!all_vector_coord_are_in_range(0, 255, &v_color))
		return (false);
	if (ambiant.intensity < 0 || ambiant.intensity > 1.0f)
		return (false);
	ambiant.color = make_color_vector(v_color, 1);
	if (app->scene->ambiant.intensity != 0)
	{
		app->error_message = "Error during parsing, 2 ambiant light value";
		return (false);
	}
	if (ambiant.intensity == 0)
		ambiant.intensity = 0.1;
	ambiant.color = v4_multi(ambiant.intensity, ambiant.color);
	app->scene->ambiant = ambiant;
	return (true);
}

bool	parse_camera(char **tokens, t_app *app)
{
	t_cam		*camera;
	t_point		origin;
	t_point		orientation;
	double		angle;

	angle = 0;
	app->error_message = "Error during parsing, On a camera";
	if (!tokens_has_valid_params_nbr(tokens, 4))
		return (false);
	if (!parse_a_vector(tokens[1], &origin))
		return (false);
	if (!parse_a_vector(tokens[2], &orientation))
		return (false);
	if (!parse_double_from_str(tokens[3], &angle))
		return (false);
	if (!all_vector_coord_are_in_range(-1, 1, &orientation))
		return (false);
	if (angle < 0 || angle > 180)
		return (false);
	camera = build_camera(origin, orientation, angle);
	ft_push(app->scene->cameras, camera);
	return (true);
}

bool	parse_file_line(char *line, t_app *app)
{
	char	**tokens;
	bool	status;

	status = true;
	if (!ft_strlen(line))
		return (true);
	tokens = ft_split_v(line, " \t\n\r\v");
	if (ft_strncmp(tokens[0], "sp", 2) == 0)
		status = parse_sphere(tokens, app);
	else if (ft_strncmp(tokens[0], "bsp", 3) == 0)
		status = parse_sphere_bonus(tokens, app);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		status = parse_camera(tokens, app);
	else if (ft_strncmp(tokens[0], "pl", 2) == 0)
		status = parse_plan(tokens, app);
	else if (ft_strncmp(tokens[0], "tr", 2) == 0)
		status = parse_triangle(tokens, app);
	else if (ft_strncmp(tokens[0], "L", 1) == 0)
		status = parse_light(tokens, app);
	else if (ft_strncmp(tokens[0], "A", 1) == 0)
		status = parse_ambiant_light(tokens, app);
	else if (ft_strncmp(tokens[0], "cy", 2) == 0)
		status = parse_cylinder(tokens, app);
	ft_free_splitted(tokens);
	return (status);
}

bool	parse_rt_file(t_app *app)
{
	char	*line;
	int		res;

	line = NULL;
	app->scene = init_scene();
	app->error_message = "Error during parsing";
	app->error_code = 2;
	res = 1;
	while (res > 0)
	{
		res = get_next_line(app->in_fd, &line);
		if (!parse_file_line(line, app))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	app->error_message = NULL;
	printf("File parsing finished\n");
	return (check_config_file(app));
}
