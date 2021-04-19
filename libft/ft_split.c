/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:45:05 by jhleena           #+#    #+#             */
/*   Updated: 2020/11/11 21:09:57 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_c(char *s, char c)
{
	int		flag;
	int		count;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		if (*s != c && !flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_word_len(char *s, char c)
{
	int		len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char		**ft_free(char **p)
{
	char	**begin_p;

	begin_p = p;
	while (*p)
	{
		free(*p);
		p++;
	}
	free(begin_p);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		len;
	char	**p;
	char	**begin_p;
	int		i;

	if (!s || !(p = (char **)malloc(sizeof(char *) * (ft_c((char *)s, c) + 1))))
		return (NULL);
	begin_p = p;
	while (*s)
	{
		len = ft_word_len((char *)s, c);
		if (len == 0)
			break ;
		if (!(*p = (char *)malloc(len + 1)))
			return (ft_free(begin_p));
		while (*s == c)
			s++;
		i = 0;
		while (len-- > 0)
			(*p)[i++] = *s++;
		(*p)[i] = '\0';
		p++;
	}
	*p = NULL;
	return (begin_p);
}
