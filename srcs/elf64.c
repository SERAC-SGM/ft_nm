/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:30:27 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 13:59:06 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

void	set_header64(t_elfheader *elf, void *file) // need big endian conversion
{
	memcpy(elf->u_ehdr.elf64.e_ident, file, EI_NIDENT);
	elf->u_ehdr.elf64.e_type = ((Elf64_Ehdr *)file)->e_type;
	elf->u_ehdr.elf64.e_machine = ((Elf64_Ehdr *)file)->e_machine;
	elf->u_ehdr.elf64.e_version = ((Elf64_Ehdr *)file)->e_version;
	elf->u_ehdr.elf64.e_entry = ((Elf64_Ehdr *)file)->e_entry;
	elf->u_ehdr.elf64.e_phoff = ((Elf64_Ehdr *)file)->e_phoff;
	elf->u_ehdr.elf64.e_shoff = ((Elf64_Ehdr *)file)->e_shoff;
	elf->u_ehdr.elf64.e_flags = ((Elf64_Ehdr *)file)->e_flags;
	elf->u_ehdr.elf64.e_ehsize = ((Elf64_Ehdr *)file)->e_ehsize;
	elf->u_ehdr.elf64.e_phentsize = ((Elf64_Ehdr *)file)->e_phentsize;
	elf->u_ehdr.elf64.e_phnum = ((Elf64_Ehdr *)file)->e_phnum;
	elf->u_ehdr.elf64.e_shentsize = ((Elf64_Ehdr *)file)->e_shentsize;
	elf->u_ehdr.elf64.e_shnum = ((Elf64_Ehdr *)file)->e_shnum;
	elf->u_ehdr.elf64.e_shstrndx = ((Elf64_Ehdr *)file)->e_shstrndx;
}

// void	set_program_header64(t_elfheader *elf, void *file)
// {
// 	elf->u_phdr.phdr64 = *(Elf64_Phdr *)(file + elf->u_ehdr.elf64.e_phoff);
// }
