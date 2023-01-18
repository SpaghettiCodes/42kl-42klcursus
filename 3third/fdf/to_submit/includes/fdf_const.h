/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:13:53 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:13:56 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONST_H
# define FDF_CONST_H

# include <limits.h>

// default values
# define LINE_SIZE 25
# define TRANS_X 800
# define TRANS_Y 384
# define COL_MULTIPLIER 5
# define SENS 0.05
# define LIGHT_DIS 800
# define Z_MULTI 1
# define LENGTH 1980
# define WIDTH 980

// array indexing
# define X 0
# define Y 1
# define Z 2

// array indexing
# define L_MSE 0
# define R_MSE 1

// array indexing
# define W_KEY 0
# define A_KEY 1
# define S_KEY 2
# define D_KEY 3

// button status
# define PRESSED 1
# define RELEASED 0

// key codes
enum {
	W_CODE = 1,
	A_CODE = 0,
	S_CODE = 13,
	D_CODE = 2,
	O_CODE = 31,
	P_CODE = 35,
	C_CODE = 8,
	LEFT_CODE = 123,
	RIGHT_CODE = 124,
	R_CODE = 15,
	ESC_CODE = 53,
	UP_CODE = 126,
	DOWN_CODE = 125
};

// x_event numbers
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// color codes
enum {
	NO = 0,
	RG = 1,
	BG = 2,
	RB = 3,
	GR = 4,
	YB = 5
};

#endif