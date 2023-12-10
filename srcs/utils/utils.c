/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:43 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 17:01:07 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strdup(char *str1)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(str1);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len + (size_t)(start) < ft_strlen(s))
		str = malloc(sizeof(*s) * (len + 1));
	if (len + (size_t)(start) >= ft_strlen(s))
		str = malloc(sizeof(*s) * (ft_strlen(s) - (size_t)(start) + 1));
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

int	ft_atoi(char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long long	total;
	void				*ptr;
	int					i;

	if (count == 0 || size == 0)
		total = 1;
	total = count * size;
	if (total > 21747483647)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (int)total)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
