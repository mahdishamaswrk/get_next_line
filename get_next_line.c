/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamas <mchamas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:07:03 by mchamas           #+#    #+#             */
/*   Updated: 2025/07/18 17:31:07 by mchamas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line_buffer(int fd, char *repo, char *buffer)
{
	int		saved;
	char	*tmp;

	saved = 1;
	while (saved > 0)
	{
		saved = read(fd, buffer, BUFFER_SIZE);
		if (saved == -1)
		{
			free(repo);
			return (NULL);
		}
		else if (saved == 0)
			break ;
		buffer[saved] = '\0';
		if (!repo)
			repo = ft_strdup("");
		tmp = repo;
		repo = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (repo);
}

char	*set_line(char *line_bfr)
{
	char	*repo;
	int		i;

	i = 0;
	while (line_bfr[i] != '\n' && line_bfr[i] != '\0')
		i++;
	if (line_bfr[i] == '\0')
		return (NULL);
	repo = ft_substr(line_bfr, i + 1, ft_strlen(line_bfr) - i - 1);
	if (*repo == '\0')
	{
		free(repo);
		repo = NULL;
	}
	line_bfr[i + 1] = '\0';
	return (repo);
}

char	*get_next_line(int fd)
{
	static char	*repo;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(repo);
		free(buffer);
		repo = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, repo, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	repo = set_line(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test1.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while (line = get_next_line(fd))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
