/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_program_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:07:43 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 16:53:29 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

int	check_p_type(void *programheader)
{
	t_elf_word	p_type;

	p_type = ((Elf32_Phdr *)programheader)->p_type;
	if (p_type == PT_NULL
		|| p_type == PT_LOAD
		|| p_type == PT_DYNAMIC
		|| p_type == PT_INTERP
		|| p_type == PT_NOTE
		|| p_type == PT_SHLIB
		|| p_type == PT_PHDR
		|| p_type == PT_TLS
		|| p_type == PT_GNU_EH_FRAME
		|| p_type == PT_GNU_STACK
		|| p_type == PT_GNU_RELRO
		|| p_type == PT_SUNWBSS
		|| p_type == PT_SUNWSTACK
		|| p_type == PT_HIOS
		|| p_type == PT_LOPROC
		|| p_type == PT_HIPROC)
		return (SUCCESS);
	ft_printf("Unknown p_type\n");
	return (FAILURE);
}

int check_p_flags(void *programheader)
{
	t_elf_word	p_flags;

	p_flags = ((Elf64_Phdr *)programheader)->p_flags;
	if (p_flags == PF_X
		|| p_flags == PF_W
		|| p_flags == PF_R
		|| p_flags == PF_MASKOS
		|| p_flags == PF_MASKPROC)
		return (SUCCESS);
	ft_printf("Unknown p_flags\n");
	return (FAILURE);
}
