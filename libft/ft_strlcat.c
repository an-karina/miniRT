/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:52:39 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 17:37:16 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
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
