/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:31 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 11:24:33 by lletourn         ###   ########.fr       */
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
void	set_header32(t_elfheader *elf, void *file);
void	set_header64(t_elfheader *elf, void *file);


#endif
