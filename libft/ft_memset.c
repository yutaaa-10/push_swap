/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:41:29 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/29 15:20:41 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	uc;

	i = 0;
	buf = (unsigned char *)b;
	uc = (unsigned char)c;
	while (i < len)
	{
		buf[i] = uc;
		i++;
	}
	return (b);
}
