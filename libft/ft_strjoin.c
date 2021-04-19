/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:50:03 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/09 15:15:42 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*p;

	if (!s1 && !s2)
		return (NULL);
	p = NULL;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (p)
	{
		ft_strlcpy(p, s1, len_s1 + 1);
		if (len_s2)
			ft_strlcat(p, s2, len_s2 + len_s1 + 1);
	}
	return (p);
}
