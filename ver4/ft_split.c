/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:58 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:36:02 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_tokens(char const *s, char del)
{
	size_t	tokens;
	int		inside;

	tokens = 0;
	while (*s)
	{
		inside = 0;
		while (*s == del && *s)
			++s;
		while (*s != del && *s)
		{
			if (!inside)
			{
				++tokens;
				inside = 1;
			}
			++s;
		}
	}
	return (tokens);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor;
	char		*next_word;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc(sizeof(char) * (size_t)len + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		i;
	int		word_count;

	if (s == NULL)
		return (NULL);
	i = 0;
	word_count = count_tokens(s, c);
	res = (char **)malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!res)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ;
		}
		res[i++] = get_next_word(s, c);
	}
	res[i] = NULL;
	return (res);
}
