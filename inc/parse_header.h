/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:03 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 12:21:50 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HEADER_H
# define PARSE_HEADER_H

# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "struct.h"

// elfheader *get_elf_header(char *file);
void	parse_header(t_elfheader *elf, void *file);

void	check_e_version(char *file);
void	check_offset_size(char *file, unsigned long size);
// void	check_e_ehsize(char *file, unsigned long size);
void	check_file_size(char c, unsigned long size);
void	check_e_type(t_elf_half e_type);


#endif
