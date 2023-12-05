/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:43 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 16:38:50 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t  ft_strlength(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char	*ft_strdup(const char *str1)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlength(str1);
	new = malloc(sizeof(char) * (size + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlength(s))
		return (ft_strdup(""));
	if (len + (size_t)(start) < ft_strlength(s))
		str = malloc(sizeof(*s) * (len + 1));
	if (len + (size_t)(start) >= ft_strlength(s))
		str = malloc(sizeof(*s) * (ft_strlength(s) - (size_t)(start) + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = *(s + start + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
