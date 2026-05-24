/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:16:15 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/30 12:45:39 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static char	*ft_make_word(const char *str, char c, int start)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[start + len] && !is_sep(str[start + len], c))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **result, int j)
{
	while (j > 0)
	{
		j--;
		free(result[j]);
	}
	free(result);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], c))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_sep(str[i], c))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
		{
			result[j] = ft_make_word(s, c, i);
			if (!result[j++])
				return (free_all(result, j - 1), NULL);
			while (s[i] && !is_sep(s[i], c))
				i++;
		}
	}
	return (result[j] = NULL, result);
}
