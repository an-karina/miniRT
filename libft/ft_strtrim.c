/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:00:21 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/09 16:25:14 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	finish;
	char	*p;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	finish = ft_strlen(s1);
	while (finish && ft_strchr(set, s1[finish - 1]))
		finish--;
	p = malloc(sizeof(char) * (finish + 1));
	if (p)
	{
		ft_memcpy(p, s1, finish);
		p[finish] = '\0';
	}
	return (p);
}
