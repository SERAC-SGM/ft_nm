/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:03 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 11:17:10 by lletourn         ###   ########.fr       */
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

#endif
