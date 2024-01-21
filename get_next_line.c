/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:02 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/21 23:56:05 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *here(char *string)
{
	char *ptr;
	int i;

	i = 0;
	while(string[i] && string[i] != '\n')
		i++;
	ptr = malloc(i + 1);
	if(!ptr)
		return NULL;
	i = 0;
	while(string[i] && string[i] != '\n')
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return ptr;
}

char	*get_next_line(int fd)
{
	static char *string;
	char *line;
	if(fd < 0 || write(fd ,"" ,0) == -1 || BUFFER_SIZE < 0)
		return NULL;
	string = allocation_manager(fd);
	if(!string)
		return NULL;
	line = here(string);
    return (line);
}
