/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:41:56 by vsydorch          #+#    #+#             */
/*   Updated: 2017/03/05 12:09:44 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_remalloc_it(char **line, char **tmp, char *buff, int flag)
{
	char	*cache;
	int		j;

	j = ft_strlen(*line);
	cache = ft_strnew(j);
	if (flag == 0)
	{
		ft_strcpy(cache, *line);
		free(*line);
		while (buff[flag] && buff[flag] != '\n')
			flag++;
		*line = ft_strnew(j + flag);
		ft_strcpy(*line, cache);
	}
	else
	{
		j = ft_strlen(*tmp);
		free(*tmp);
		while (buff[flag - 1])
			flag++;
		*tmp = ft_strnew(j + flag - 1);
		ft_strcpy(*tmp, cache);
	}
	free(cache);
}

int		fill_line_read(char **line, char **tmp, char *buff)
{
	int		j;
	int		k;

	k = 0;
	j = ft_strlen(*line);
	ft_remalloc_it(&(*line), &(*tmp), buff, 0);
	while (buff[k] && buff[k] != '\n')
		(*line)[j++] = buff[k++];
	(*line)[j] = '\0';
	if (buff[k])
	{
		j = ft_strlen(*tmp);
		ft_remalloc_it(&(*line), &(*tmp), buff, 1);
		while (buff[k])
			(*tmp)[j++] = buff[k++];
		(*tmp)[j] = '\0';
		return (1);
	}
	return (2);
}

int		fill_line_tmp(char **line, char **tmp)
{
	int		i;
	int		j;
	char	*cache;

	i = 0;
	j = ft_strlen(*line);
	if ((*tmp)[i] == '\n')
		i++;
	while ((*tmp)[i] && (*tmp)[i] != '\n')
		(*line)[j++] = (*tmp)[i++];
	(*line)[j] = '\0';
	if ((*tmp)[i])
	{
		j = 0;
		cache = ft_strnew(ft_strlen(*tmp) - i);
		while ((*tmp)[i])
			cache[j++] = (*tmp)[i++];
		cache[j] = '\0';
		free(*tmp);
		*tmp = ft_strnew(ft_strlen(cache));
		ft_strcpy(*tmp, cache);
		free(cache);
		return (1);
	}
	return (2);
}

void	ft_more(char **line, char **tmp, int *flag, int *flag2)
{
	if (ft_strlen(*tmp) != 0)
	{
		*flag2 = 1;
		*flag = fill_line_tmp(&(*line), &(*tmp));
		if (*flag == 2)
		{
			free(*tmp);
			*tmp = ft_strnew(BUFF_SIZE);
		}
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*tmp[7000];
	char		buff[BUFF_SIZE + 1];
	int			flag;
	int			flag2;
	int			i;

	flag = 2;
	flag2 = 0;
	if (fd < 0 || fd > 7000 || BUFF_SIZE < 1 || BUFF_SIZE > 8380000 || !line)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	ft_more(&(*line), &tmp[fd], &flag, &flag2);
	while (flag == 2 && (i = read(fd, buff, BUFF_SIZE)))
	{
		flag2 = 1;
		buff[i] = '\0';
		if (i == -1)
			return (-1);
		flag = fill_line_read(&(*line), &tmp[fd], buff);
	}
	if (i == 0 && ft_strlen(tmp[fd]) == 0 && ft_strlen(*line) == 0)
		flag2 = 0;
	return (flag2);
}
