/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 21:52:03 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/20 21:01:12 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 32

typedef struct	s_fdline
{
	int				fd;
	char			*lines;
	struct s_fdline	*next;
}				t_fdline;

int				get_next_line(int const fd, char **line);
#endif
