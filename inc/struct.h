/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:21:36 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/16 17:04:44 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "elf.h"

// # define HEADEROFFSET32	(52)
// # define HEADEROFFSET64	(64)

// typedef uint16_t	t_elf_half;
// typedef uint32_t	t_elf_word;

/*
	Structure containing the header of the elf file

	- ei_class : ELFCLASS32 or ELFCLASS64
	- ei_data : ELFDATA2LSB or ELFDATA2MSB
*/
typedef struct s_elfheader
{
	char	ei_class;
	char	ei_data;

	union
	{
		Elf32_Ehdr	*elf32;
		Elf64_Ehdr	*elf64;
	}	u_ehdr;
	union
	{
		Elf32_Phdr	*phdr32;
		Elf64_Phdr	*phdr64;
	}	u_phdr;
	union
	{
		Elf32_Shdr	*shdr32;
		Elf64_Shdr	*shdr64;
	}	u_shdr;
}	t_elfheader;

/*
	Location of the different parameters in the header
*/
// typedef enum e_headerparam32
// {
// 	E_INDENT = 0,
// 	E_TYPE = 16,
// 	E_MACHINE = 18,
// 	E_VERSION = 20,
// 	E_ENTRY = 24,
// 	E_PHOFF32 = 28,
// 	E_PHOFF64 = 32,
// 	E_SHOFF32 = 32,
// 	E_SHOFF64 = 40,
// 	E_FLAGS32 = 36,
// 	E_FLAGS64 = 44,
// 	E_EHSIZE32 = 40,
// 	E_EHSIZE64 = 52,
// 	E_PHENTSIZE32 = 42,
// 	E_PHNUM32 = 44,
// 	E_SHENTSIZE32 = 46,
// 	E_SHNUM32 = 48,
// 	E_SHSTRNDX32 = 50,
// 	E_PHNUM64 = 56,
// 	E_PHENTSIZE64 = 54,
// 	E_SHENTSIZE64 = 58,
// 	E_SHNUM64 = 60,
// 	E_SHSTRNDX64 = 62
// }	t_headerparam;

#endif
