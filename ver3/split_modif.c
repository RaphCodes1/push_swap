/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:44:05 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:48:15 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_msg_main(char *s)
{
	write(2, "Error\n", 6);
	free(s);
	exit(1);
}

static int modif_strlen(char **s)
{
	int i;
	int f;
	int strlen;

	i = 1;
	f = 0;
	strlen = 0;
	while (s[i])
	{
		f = 0;
		while (s[i][f])
			f++;
		strlen += f;
		i++;
	}
	strlen += i;
	return(strlen);
}
char	*split_modif(char **s)
{
	char	*holder;
	int		strlen;
	int		f;
	int		i;
	int		x;

	strlen = modif_strlen(s);
	holder = malloc(sizeof(char) * (strlen + 1));
	i = 1;
	x = 0;
	while (s[i])
	{
		f = 0;
		while (s[i][f])
		{
			holder[x + f] = s[i][f];
			f++;
		}
		x += f;
		holder[x++] = ' ';
		i++;
	}
	holder[x - 1] = '\0';
	return (holder);
}

// int main()
// {
//     char *s = "Hello there world Hi threeeee wwgwgwgw 12114124";
//     char **res = ft_split(s,' ');
//     char *t = split_modif(res);
//     printf("%s\n",s);

//     int i = 0;
//     while(i <= 7)
//     {
//         free(res[i]);
//         i++;
//     }
//     free(res);
//     free(t);

// }
