/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohee <sohee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:52:42 by sohelee           #+#    #+#             */
/*   Updated: 2021/03/22 18:51:34 by sohee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == 0)
		return (0);
	i = 0;
	while (s[i] && (s[i] != c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_buff(char **arr, size_t cnt)
{
	while (cnt-- > 0)
	{
		free(arr[cnt]);
		arr[cnt] = 0;
	}
	free(arr);
	arr = 0;
	return (0);
}

static char	**check_error(char const *s, char c)
{
	char		**arr;

	if (!s)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (arr == 0)
		return (0);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		wordcnt;
	char		**arr;

	arr = check_error(s, c);
	i = 0;
	wordcnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			arr[wordcnt] = malloc_word(&s[i], c);
			if (!(arr[wordcnt]))
				return (free_buff(arr, wordcnt));
			wordcnt++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	arr[wordcnt] = 0;
	return (arr);
}
