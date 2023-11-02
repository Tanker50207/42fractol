/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:35:34 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/31 12:36:33 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	ret = malloc(size + 1);
	if (!ret)
	{
		if (ptr)
			free(ptr);
		return (0);
	}
	if (!ptr)
	{
		((unsigned char *)ret)[0] = '\0';
		return (ret);
	}
	while (((unsigned char *)ptr)[i] && i < size)
	{
		((unsigned char *)ret)[i] = ((unsigned char *)ptr)[i];
		i++;
	}
	free(ptr);
	((unsigned char *)ret)[i] = '\0';
	return (ret);
}
//ATTENTION! The pointer passed is freed if the malloc failed!

void	ft_trunc(char *str, int n)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i + n])
	{
		str[i] = str[i + n];
		i++;
	}
	str[i] = '\0';
}

int	update_buffer_gnl(char *buf, int fd)
{
	ssize_t	err;

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!ft_strchr(buf, '\n'))
	{
		err = read(fd, buf, BUFFER_SIZE);
		if (err > 0)
			buf[err] = '\0';
		return (err);
	}
	return (ft_strlen(buf));
}

char	*get_next_line(int fd)
{
	static char	buf[FD_SET_MAX][BUFFER_SIZE + 1];
	char		*ret;
	ssize_t		err;

	ret = 0;
	while (!ft_strchr(ret, '\n') && fd >= 0 && fd < FD_SET_MAX)
	{
		ret = ft_realloc(ret, ft_strlen(ret) + ft_strlen(buf[fd]));
		if (!ret)
			return (0);
		ft_strcat(ret, buf[fd]);
		err = update_buffer_gnl(buf[fd], fd);
		if (err <= 0)
		{
			buf[fd][0] = '\0';
			if (err == 0 && ret[0])
				return (ret);
			free(ret);
			return (0);
		}
	}
	if (fd >= 0 && fd < FD_SET_MAX)
		ft_trunc(buf[fd], ft_strchr(buf[fd], '\n') - buf[fd] + 1);
	return (ret);
}
