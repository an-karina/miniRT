/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:35:37 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/03 11:35:41 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;
	unsigned char sym;

	p = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*p == sym)
			return (p);
		p++;
	}
	return (NULL);
}
