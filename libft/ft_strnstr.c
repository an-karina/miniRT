/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:25:50 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/06 11:13:51 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	h = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return (h);
	if ((needle_len > ft_strlen(haystack)) || (len < needle_len))
		return (NULL);
	while (h[i] && (i <= len - needle_len))
	{
		j = 0;
		while (needle[j] && (needle[j] == h[i + j]))
			j++;
		if (j == needle_len)
			return (h + i);
		i++;
	}
	return (NULL);
}
