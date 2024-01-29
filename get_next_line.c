/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:02 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/22 23:54:08 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*here(char *string)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!string)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	ft_cpy(ptr, string, i);
	return (ptr);
}

static char	*new_l(char *string)
{
	int		i;
	char	*ptr;
	int		size;

	i = 0;
	if (!string)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	while (*(string + i) && *(string + i) != '\n')
		i++;
	if (*(string + i) == '\n')
		i++;
	size = ft_strlen(string);
	ptr = malloc(size - i + 1);
	if (!ptr)
		return (NULL);
	ft_cpy(ptr, string + i, size);
	free(string);
	string = NULL;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
		return (NULL);
	allocation_manager(fd, &string);
	if (!string)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	if (*string == '\0')
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	line = here(string);
	string = new_l(string);
	return (line);
}
