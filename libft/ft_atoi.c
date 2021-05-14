/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:04:25 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/14 19:00:40 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_sign(char str)
{
	if (str == '-')
		return (-1);
	if (str == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;
	int			sign;

	i = 0;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == '\n') || (str[i] == '\f'))
		i++;
	sign = num_sign(str[i]);
	while (str[i] <= '9' && str[i] >= '0')
	{
		if ((result > 2147483647) && (sign == 1))
			return (-1);
		if ((result > 2147483648) && (sign == -1))
			return (0);
		result = 10 * result + (str[i] - '0');
		i++;
	}
	if (sign)
		result = result * sign;
	return (result);
}
