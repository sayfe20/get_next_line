/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:02 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/23 02:43:11 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	allocation_manager(int fd, char **save)
{
	int rd;
	char *buffer;
	rd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while(rd != 0)
	{
		rd = read(fd,buffer,BUFFER_SIZE);
		if(rd == -1 )
		{
			free(buffer);
			free(*save);
			*save = NULL;
			return ;
		}
		 if(rd == 0)
		{
			// free(buffer);
			// free(*save);
			// *save = NULL;
			// return;
			break;
		}
		buffer[rd] = '\0';
		*save = ft_strcat(*save,buffer);
		// printf("%s----", *save);
		if(!ft_newline_check(buffer))
			break;
	}
	free(buffer);	
}

int ft_newline_check(char *string)
{
	int i = 0 ;
	if(!string)
		return 0;
	while(string[i])
	{
		if(string[i] == '\n')
			return 0;
		i++;
	}
	return 1;
}

char    *ft_strcat(char *string1, char *string2)
{
	int s1;
	int s2;
	char *ptr;
	int i = 0;
	int j = 0;
	if(!string1)
	{
		string1 = malloc(1);
		string1[0] = '\0';
		s1 = 0;
	}
	else
		s1 = ft_strlen(string1);
	if(!string2)
		return NULL;
	s2 = ft_strlen(string2);
	ptr = malloc(s1  + s2 + 1);
	if(!ptr)
		return NULL;
	while(string1[i])
	{
		ptr[i] = string1[i];
		i++;
	}
	while(string2[j])
	{
		ptr[i + j] = string2[j];
		j++;
	}
	ptr[i+j] = '\0';
	free(string1);
	return ptr;
}

int  ft_strlen(char *string)
{
    int i;
    i = 0;
	if(!string)
		return 0;
    while (string[i])
		i++;
    return (i);
}
