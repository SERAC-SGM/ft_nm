/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:46:01 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 16:42:32 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int ret;

	ret = 0;
	if (argc < 2)
	{
		ret += nm("a.out");
		return (0);
	}
	else if (argc == 2)
	{
		ret += nm(argv[1]);
		return (0);
	}
	while (--argc > 0)
	{
		ft_printf("%s: ", *++argv);
		ret += nm(*argv);
	}
	return (ret);
}
