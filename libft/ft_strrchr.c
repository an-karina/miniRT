/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:36:05 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/05 17:19:09 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	sym;
	int				len;
	char			*p;

	sym = (unsigned char)c;
	p = (char *)s;
	len = 0;
	while (*p != '\0')
	{
		p++;
		len++;
	}
	while (len >= 0)
	{
		if (*p == sym)
			return (p);
		p--;
		len--;
	}
	return (NULL);
}
