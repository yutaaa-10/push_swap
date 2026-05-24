/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:04:24 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/30 11:52:25 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *res, const char *str, size_t *index)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		res[*index] = str[i];
		i++;
		(*index)++;
	}
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!res)
		return (NULL);
	i = 0;
	ft_copy(res, s1, &i);
	ft_copy(res, s2, &i);
	res[i] = '\0';
	return (res);
}
