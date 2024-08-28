#include "push_swap.h"

size_t	my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*src && (i + 1) < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < dstsize)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

static int	safe_malloc(char **token_v, int position, size_t length)
{
	int	i;

	i = 0;
	token_v[position] = malloc(length);
	if (token_v[position] == NULL)
	{
		while (i < position)
		{
			free(token_v[i]);
			i++;
		}
		free(token_v);
		return (1);
	}
	return (0);
}

static int	fill(char **token_v, char const *s, char del)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
        if(i == 0)
		{
			if (safe_malloc(token_v, i, len + 1))
                    return (1);
            token_v[i][0] = '\0';
		}
        else
        {
            while (*s == del && *s)
                ++s;
            while (*s != del && *s)
            {
                ++len;
                ++s;
            }
            if (len)
            {
                if (safe_malloc(token_v, i, len + 1))
                    return (1);
                my_strlcpy(token_v[i], s - len, len + 1);
                token_v[i][len] = '\0';
            }
        }
		++i;
	}
	return (0);
}

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

char	**ft_splitver2(char const *s, char c)
{
	char	**token_v;
	int		token;

	if (s == NULL)
		return (NULL);
	token = 0;
	token = count_tokens(s, c);
	token_v = (char **)malloc(sizeof(char *) * (token + 1));
	if (token_v == NULL)
		return (NULL);
	token_v[token] = NULL;
	if (fill(token_v, s, c))
		return (NULL);
	return (token_v);
}

// int main()
// {
//     char *s = "Hello world Hi there man";
//     char **res = ft_splitver2(s,' ');
//     int i = 0;
//     while(res[i])
//     {
//         printf("%s\n",res[i++]);
//     }
//     i = 0;
//     while(i <= 5)
//         free(res[i++]);
//     free(res[i]);
// }