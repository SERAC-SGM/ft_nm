/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:21:36 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 17:32:59 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "elf.h"

# define SUCCESS (0)
# define FAILURE (-1)

# define HEADEROFFSET32	(52)
# define HEADEROFFSET64	(64)
# define EHSIZE32		(52)
# define EHSIZE64		(64)

typedef uint16_t	t_elf_half;
typedef uint32_t	t_elf_word;

/*
	Structure containing the header of the elf file

	- ei_class : ELFCLASS32 or ELFCLASS64
	- ei_data : ELFDATA2LSB or ELFDATA2MSB
*/
typedef struct s_elfheader
{
	char				ei_class;
	char				ei_data;
	unsigned long		file_size;

	union
	{
		Elf32_Ehdr	elf32;
		Elf64_Ehdr	elf64;
	}	u_ehdr;
	union
	{
		Elf32_Phdr	phdr32;
		Elf64_Phdr	phdr64;
	}	u_phdr;
	union
	{
		Elf32_Shdr	shdr32;
		Elf64_Shdr	shdr64;
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

enum e_phparam
{
	P_TYPE = 0,
	P_FLAGS64 = 4,
	P_OFFSET32 = 4,
	P_OFFSET64 = 8,
	P_VADDR32 = 8,
	P_VADDR64 = 16,
	P_PADDR32 = 12,
	P_PADDR64 = 24,
	P_FILESZ32 = 16,
	P_FILESZ64 = 32,
	P_MEMSZ32 = 20,
	P_MEMSZ64 = 40,
	P_FLAGS32 = 24,
	P_ALIGN32 = 28,
	P_ALIGN64 = 48,
};

enum e_shparam
{
	S_NAME = 0,
	S_TYPE = 4,
	S_FLAGS = 8,
	S_ADDR32 = 12,
	S_ADDR64 = 16,
	S_OFFSET32 = 16,
	S_OFFSET64 = 24,
	S_SIZE32 = 20,
	S_SIZE64 = 32,
	S_LINK32 = 24,
	S_LINK64 = 36,
	S_INFO32 = 28,
	S_INFO64 = 40,
	S_ALIGN32 = 32,
	S_ALIGN64 = 40,
	S_ENTSIZE32 = 36,
	S_ENTSIZE64 = 48,
};

enum e_memoryparam
{
	HEADER,
	PROGRAMHEADER,
	SECTIONHEADER,
};

#endif
