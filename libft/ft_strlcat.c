/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:52:39 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/09 12:14:31 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(dst);
	i = n + ft_strlen(src);
	if (n >= dstsize)
		return (dstsize + ft_strlen(src));
	while (*dst)
		dst++;
	while (*src != '\0' && (dstsize - n - 1))
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (i);
}
