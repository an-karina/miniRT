/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:07:46 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/05 16:35:04 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	sym;
	char			*p;

	sym = (unsigned char)c;
	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == sym)
			return (p);
		p++;
	}
	if (sym == '\0')
		return (p);
	return (NULL);
}
