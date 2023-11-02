/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:35:45 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/31 13:01:45 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef FD_SET_MAX
#  define FD_SET_MAX 1024
# endif

char	*get_next_line(int fd);
void	*ft_realloc(void *ptr, size_t size);
void	ft_trunc(char *str, int n);

#endif
