/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:44:13 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/29 16:01:10 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	strlen;

	strlen = 0;
	while (src[strlen] != '\0')
		strlen++;
	if (dstsize == 0)
		return (strlen);
	i = 0;
	while ((i < dstsize - 1) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen);
}
