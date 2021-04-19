/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:14:51 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/09 20:53:31 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	num;
	int		sign;
	int		len;
	char	*p;

	num = (n < 0) ? ((long)n * -1) : (n);
	len = num_len(num);
	sign = (n < 0) ? (1) : (0);
	p = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (p)
	{
		if (sign)
			p[0] = '-';
		p[len + sign] = '\0';
		while (len > 0)
		{
			p[len + sign - 1] = (num % 10) + '0';
			num = num / 10;
			len--;
		}
	}
	return (p);
}
