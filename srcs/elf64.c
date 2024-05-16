/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:30:27 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/16 17:18:24 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

void	set_elf64(t_elfheader *elf, void *file) // need big endian conversion
{
	memcpy(elf->u_ehdr.elf64->e_ident, file, EI_NIDENT);
	elf->u_ehdr.elf64->e_type = ((Elf64_Ehdr *)file)->e_type;
	elf->u_ehdr.elf64->e_machine = ((Elf64_Ehdr *)file)->e_machine;
	elf->u_ehdr.elf64->e_version = ((Elf64_Ehdr *)file)->e_version;
	elf->u_ehdr.elf64->e_entry = ((Elf64_Ehdr *)file)->e_entry;
	// ft_printf("e_entry: %x\n", ((Elf64_Ehdr *)file)->e_entry);
	elf->u_ehdr.elf64->e_phoff = ((Elf64_Ehdr *)file)->e_phoff;
	// ft_printf("e_phoff: %x\n", (Elf64_Off)file[0x20]);
	elf->u_ehdr.elf64->e_shoff = ((Elf64_Ehdr *)file)->e_shoff;
	ft_printf("e_shoff: %x\n", ((Elf64_Ehdr *)file)->e_shoff);
	elf->u_ehdr.elf64->e_flags = ((Elf64_Ehdr *)file)->e_flags;
	elf->u_ehdr.elf64->e_ehsize = ((Elf64_Ehdr *)file)->e_ehsize;
	elf->u_ehdr.elf64->e_phentsize = ((Elf64_Ehdr *)file)->e_phentsize;
	elf->u_ehdr.elf64->e_phnum = ((Elf64_Ehdr *)file)->e_phnum;
	elf->u_ehdr.elf64->e_shentsize = ((Elf64_Ehdr *)file)->e_shentsize;
	elf->u_ehdr.elf64->e_shnum = ((Elf64_Ehdr *)file)->e_shnum;
	elf->u_ehdr.elf64->e_shstrndx = ((Elf64_Ehdr *)file)->e_shstrndx;
}
