/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:23 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:26:24 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rst;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	rst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rst)
		return (NULL);
	i = 0;
	while (*s1)
		rst[i++] = *s1++;
	while (*s2)
		rst[i++] = *s2++;
	rst[i] = '\0';
	return (rst);
}
