#include "test.h"

// rotattat is in radian btw
int	rotattat_x(t_coordinates *current, float radian)
{
	float x;
	float y;
	float z;

	x =  current->trans_x;
	y = ( current->trans_y * cos(radian)) - (current->trans_z * sin(radian));
	z = ( current->trans_y * sin(radian)) + (current->trans_z * cos(radian));

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
}

int	rotattat_y(t_coordinates *current, float radian)
{
	float x;
	float y;
	float z;
	
	x = (current->trans_x * cos(radian)) + (current->trans_z * sin(radian));
	y = current->trans_y;
	z = (current->trans_z * cos(radian)) - (current->trans_x * sin(radian));

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
}

int	rotattat_z(t_coordinates *current, float radian)
{
	float x;
	float y;
	float z;

	x = (current->trans_x * cos(radian)) - (current->trans_y * sin(radian));
	y = (current->trans_x * sin(radian)) + (current->trans_y * cos(radian));
	z = current->trans_z;

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
}

// D = light source Distance btw (0, 0, D)
int	highest_x(t_coordinates *coordinates)
{
	t_coordinates *current;

	current = coordinates;
	while (current->beside)
	{
		current = current->beside;
	}
	return(current->x);
}

int	highest_y(t_coordinates *coordinates)
{
	t_coordinates *current;

	current = coordinates;
	while (current->below)
	{
		current = current->below;
	}
	return(current->y);
}

int	highest_z(t_coordinates *coordinates)
{
	t_coordinates *ret;
	t_coordinates *current;

	ret = coordinates;
	current = coordinates;
	while (current)
	{
		if (ret->z < current->z)
		{
			ret = current;
		}
		current = current->next;
	}
	return(ret->z);
}

int	lowest_z(t_coordinates *coordinates)
{
	t_coordinates *ret;
	t_coordinates *current;

	ret = coordinates;
	current = coordinates;
	while (current)
	{
		if (ret->z > current->z)
		{
			ret = current;
		}
		current = current->next;
	}
	return(ret->z);
}



void	perspective_projection(t_coordinates *current, int light_dis)
{
	// apparantly should work
	// assumme light source at (0,0,D)

	current->projected_x = ((light_dis * current->trans_x) / (light_dis - current->trans_z));
	current->projected_y = ((light_dis * current->trans_y) / (light_dis - current->trans_z));
}

double	min_light_distance(t_coordinates *coordinates)
{
	t_coordinates *ret;
	t_coordinates *current;

	ret = coordinates;
	current = coordinates;
	while (current)
	{
		if (ret->trans_z < current->trans_z)
		{
			ret = current;
		}
		current = current->next;
	}
	return(ret->trans_z);
}

void	project(t_coordinates *coordinate, int degree_x, int degree_y, int degree_z, int transl_x, int	transl_y, int	line_size, int	light_dis , char type)
{
	t_coordinates *current;

	float	midpoint_x = highest_x(coordinate) / 2;
	float	midpoint_y = highest_y(coordinate) / 2;
	float	midpoint_z = (highest_z(coordinate) + lowest_z(coordinate)) / 2;

	current = coordinate;
	while (current)
	{
		current->trans_x = ((current->x * line_size) - (midpoint_x * line_size));
		current->trans_y = ((current->y * line_size) - (midpoint_y * line_size));
		current->trans_z = ((current->z * line_size) - (midpoint_z * line_size)) * Z_MULTI;

		float radian_x = degree_x * (M_PI / 180);
		float radian_y = degree_y * (M_PI / 180);
		float radian_z = degree_z * (M_PI / 180);
	
		rotattat_x(current, radian_x);
		rotattat_y(current, radian_y);
		rotattat_z(current, radian_z);

		// orthographic
		if (type == 'o')
		{
			current->projected_x = current->trans_x;
			current->projected_y = current->trans_y;
		} // perspective
		else if (type == 'p')
			perspective_projection(current, light_dis);

		current->projected_x += transl_x;
		current->projected_y += transl_y;

		current = current->next;
	}

	// printf("Minimum Light Distance = %f\n", min_light_distance(coordinate));
}