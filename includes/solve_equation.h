/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@pashalove.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:07:28 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 15:14:46 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

typedef struct s_coeff
{
	double		a;
	double		b;
	double		c;
}				t_coeff;

typedef struct s_roots
{
	double		t_1;
	double		t_2;
}				t_roots;

#endif