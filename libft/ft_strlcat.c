/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:43:50 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/29 16:18:35 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	while (dstlen < dstsize && dst[dstlen])
		dstlen++;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && (dstlen + i) < (dstsize - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
