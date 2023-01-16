#include <stdio.h>
#include <math.h>

#define MATRIX_LEN 4
typedef	double matrix_init_list[MATRIX_LEN * MATRIX_LEN];
typedef double matrix[MATRIX_LEN][MATRIX_LEN];
typedef double matrix_type;

void	set_row(matrix set, int row, matrix_type one, matrix_type two, matrix_type three, matrix_type four)
{
	set[row][0] = one;
	set[row][1] = two;
	set[row][2] = three;
	set[row][3] = four;
}

void	set_col(matrix set, int col, matrix_type one, matrix_type two, matrix_type three, matrix_type four)
{
	set[0][col] = one;
	set[1][col] = two;
	set[2][col] = three;
	set[3][col] = four;
}


void	matrix_set(matrix set, matrix_type val)
{
	int	i;

	i = -1;
	while (++i < MATRIX_LEN)
		set_row(set, i, val, val, val, val);
}

void	matrix_dup(matrix to, matrix from)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MATRIX_LEN)
	{
		j = -1;
		while (++j < MATRIX_LEN)
			to[i][j] = from[i][j];
	}
}

// expect first and second to be a int[MATRIX_LEN][MATRIX_LEN]
void	matrix_multiply(matrix first, matrix second, matrix save)
{
	matrix	result;
	int	i;
	int	j;
	int	k;

	matrix_set(result, 0);
	i = -1;
	while (++i < MATRIX_LEN)
	{
		j = -1;
		while (++j < MATRIX_LEN)
		{
			k = -1;
			while (++k < MATRIX_LEN)
				result[i][j] += (first[i][k] * second[k][j]);
		}
	}
	matrix_dup(save, result);
}

void	matrix_print(matrix print)
{
	int	i;

	i = -1;
	while (++i < MATRIX_LEN)
		printf("%f   %f   %f   %f\n", print[i][0], print[i][1], print[i][2], print[i][3]);
	printf("\n");
}

// int main()
// {
// 	matrix one;
// 	matrix two;
// 	matrix three;
// 	matrix save;

// 	set_row(one, 0, 2, 3, 4, 5);
// 	set_row(one, 1, 5, 1, 4, 0);
// 	set_row(one, 2, 2, 6, 2, 6);
// 	set_row(one, 3, 1, 4, 2, 8);

// 	set_row(two, 0, 2, 3, 7, 1);
// 	set_row(two, 1, 5, 5, 4, 0);
// 	set_row(two, 2, 1, 8, 6, 5);
// 	set_row(two, 3, 4, 8, 5, 5);


// 	set_row(three, 0, 1, 0, 0, 0);
// 	set_row(three, 1, 2, 0, 0, 0);
// 	set_row(three, 2, 3, 0, 0, 0);
// 	set_row(three, 3, 1, 0, 0, 0);

// 	print_matrix(one);
// 	print_matrix(three);
// 	matrix_multiply(one, three, save);
// 	print_matrix(save);
// }

#define X 0
#define Y 1
#define Z 2

void	set_rotation_matrix(matrix rotation, double *rotate)
{
	matrix	ret;
	matrix	x_coord;
	matrix	y_coord;
	matrix	z_coord;

	printf("%f   %f   %f\n\n", rotate[X], rotate[Y], rotate[Z]);

	set_row(x_coord, 0, 1, 0, 0, 0);
	set_row(x_coord, 1, 0, cos(rotate[X]), -sin(rotate[X]), 0);
	set_row(x_coord, 2, 0, sin(rotate[X]), cos(rotate[X]), 0);
	set_row(x_coord, 3, 0, 0, 0, 1);

	printf("x rotational matrix: \n");
	matrix_print(x_coord);

	set_row(y_coord, 0, cos(rotate[Y]), 0, sin(rotate[Y]), 0);
	set_row(y_coord, 1, 0, 1, 0, 0);
	set_row(y_coord, 2, -sin(rotate[Y]), 0, cos(rotate[Y]), 0);
	set_row(y_coord, 3, 0, 0, 0, 1);

	printf("y rotational matrix: \n");
	matrix_print(y_coord);

	set_row(z_coord, 0, cos(rotate[Z]), -sin(rotate[Z]), 0, 0);
	set_row(z_coord, 1, sin(rotate[Z]), cos(rotate[Z]), 0, 0);
	set_row(z_coord, 2, 0, 0, 1, 0);
	set_row(z_coord, 3, 0, 0, 0, 1);

	printf("z rotational matrix: \n");
	matrix_print(z_coord);

	// matrix_multiply(x_coord, y_coord, ret);
	// // matrix_multiply(y_coord, x_coord, ret);
	// matrix_multiply(ret, z_coord, ret);

	// wiki said the rotation is like this sooo
	matrix_multiply(z_coord, y_coord, ret);
	matrix_multiply(ret, x_coord, ret);
	matrix_dup(rotation, ret);

	printf("rotational matrix: \n");
	matrix_print(rotation);
}

void set_translation_matrix(matrix transform, double transform_val[3])
{
	set_col(transform, 3, transform_val[X], transform_val[Y], transform_val[Z], 1);
	printf("transfomation matrix: \n");
	matrix_print(transform);
}

int main()
{
	matrix coordinate;
	int x_rot = 30;
	int y_rot = 30;
	int z_rot = 0;
	double rotate[3];
	double transformation[3];
	matrix transform;

	// coordinate (2, 3, 1)
	set_col(coordinate, 0, 2, 1, 0, 1);

	rotate[X] = (double) x_rot * (M_PI / 180);
	rotate[Y] = (double) y_rot * (M_PI / 180);
	rotate[Z] = (double) z_rot * (M_PI / 180);

	transformation[X] = 0;
	transformation[Y] = 0;
	transformation[Z] = 0;

	set_rotation_matrix(transform, rotate);
	set_translation_matrix(transform, transformation);
	matrix_multiply(transform, coordinate, coordinate);
	matrix_print(coordinate);
}