/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:07:02 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 12:30:03 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

void	check_e_version(char *file)
{
	if (file[EI_VERSION] == EV_CURRENT)
		return ;
	ft_printf("Invalid object file version\n");
	exit(1);
}

void	check_file_size(char class, unsigned long size)
{
	if (class == ELFCLASS32 && size < HEADEROFFSET32)
	{
		ft_printf("Invalid or corrupted file\n");
		exit(1);
	}
	if (class == ELFCLASS64 && size < HEADEROFFSET64)
	{
		ft_printf("Invalid or corrupted file\n");
		exit(1);
	}
}

void	check_e_type(t_elf_half e_type)
{
	if (e_type == ET_NONE || e_type == ET_REL || e_type == ET_EXEC
		|| e_type == ET_DYN || e_type == ET_CORE)
		return ;
	ft_printf("Invalid object file type\n");
	exit(1);
}
