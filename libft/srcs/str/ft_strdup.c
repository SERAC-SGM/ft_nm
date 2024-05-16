/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:20 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:26:21 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	l_src;
	size_t	i;

	l_src = ft_strlen(src);
	i = 0;
	cpy = (char *)malloc((l_src + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (i < l_src)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
