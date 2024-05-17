/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:46:01 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 11:32:37 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}
	if (argc == 2)
	{
		nm(argv[1]);
		return (0);
	}
	while (--argc > 0)
	{
		ft_printf("%s:\n", *++argv);
		nm(*argv);
	}
	return (0);
}
