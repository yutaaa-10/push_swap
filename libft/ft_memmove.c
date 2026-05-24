/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:40:36 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/29 13:05:16 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sr;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (dst == sr)
		return (dest);
	if (dst > sr)
	{
		i = n;
		while (i-- > 0)
			dst[i] = sr[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
