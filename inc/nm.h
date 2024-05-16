/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:31 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/16 17:03:06 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <elf.h>
# include <stdlib.h>

# include "../libft/inc/libft.h"
# include "struct.h"
# include "parse_header.h"
# include "utils.h"

int		nm(char *files);
void	set_elf32(t_elfheader *elf, char *file);
void	set_elf64(t_elfheader *elf, void *file);


#endif
