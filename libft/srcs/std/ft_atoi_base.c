/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:18 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:30:49 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi_base(const char *nstr, char *base)
{
	int		n;
	int		s;
	size_t	b_size;
	ssize_t	idx;

	n = 0;
	s = 1;
	b_size = 0;
	while (base[b_size])
		b_size++;
	while (ft_isspace(*nstr))
		nstr++;
	if (*nstr == '+' || *nstr == '-')
	{
		if (*nstr == '-')
			s = -1;
		nstr++;
	}
	idx = 0;
	while (idx >= 0 && *nstr)
	{
		idx = ft_index(base, *nstr++);
		n = n * b_size + idx;
	}
	return (s * n);
}
