/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_program_header.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:32:57 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:18 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_PROGRAM_HEADER_H
# define PARSE_PROGRAM_HEADER_H

# include "struct.h"

int	parse_program_header(t_elfheader *elf, void *file);

#endif
