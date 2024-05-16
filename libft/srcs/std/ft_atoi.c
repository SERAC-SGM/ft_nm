/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:22 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:24:24 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi(const char *nstr)
{
	int		n;
	int		s;

	n = 0;
	s = 1;
	while (ft_isspace(*nstr))
		nstr++;
	if (*nstr == '+' || *nstr == '-')
	{
		if (*nstr == '-')
			s = -1;
		nstr++;
	}
	while (*nstr >= '0' && *nstr <= '9')
		n = n * 10 + s * (*nstr++ - '0');
	return (n);
}
