/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:27:59 by mel-mora          #+#    #+#             */
/*   Updated: 2025/01/26 09:53:09 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	join(char *newstr, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len_total;

	if (!s1 || !s2)
	{
		if (!s1 && s2)
			return ((char *)s2);
		if (!s2 && s1)
			return ((char *)s1);
		return (NULL);
	}
	len_total = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(len_total + 1);
	if (!newstr)
		return (NULL);
	join(newstr, s1, s2);
	return (newstr);
}

void	free_and_exit(char **split, t_stack_node **a)
{
	if (split)
		free_split(split);
	if (a)
		free_stack(a);
	exit_error();
}
