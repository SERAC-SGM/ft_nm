/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:07:02 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 11:17:03 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

// static void	

// void	get_e_indent(t_elfheader *elf)
// {
// 	elf->e_indent[EI_MAG0] = elf->file_start[EI_MAG0];
// }
void	check_e_version(char *file)
{
	if (file[EI_VERSION] == EV_CURRENT)
		return ;
	ft_printf("Invalid object file version\n");
	exit(1);
}


