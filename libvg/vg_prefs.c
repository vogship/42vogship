/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vg_prefs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:35:19 by coffee            #+#    #+#             */
/*   Updated: 2022/08/31 20:58:29 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vogship.h"
#include <fcntl.h>

/** Checks if the key provided is a valid key.
 * 
 *  Only allows:
 * 	Alpha-numeric characters;
 * 	Hyphen '-'; &
 *  Underscore '_';
 */
int		is_valid_preference_key(char *key)
{
	int	i;

	i = 0;
	if (!key)
		return (0);
	while (key[i] != '\0')
	{
		if (ft_isalnum(key[i]) || key[i] == '-' || key[i] == '_')
			i++;
		else
		{
			ft_printf("vg_err: invalid character \e[91m'%c'\e[0m in key \e[94m\"%s\"\e[0m\n", key[i], key);
			return (0);
		}
	}
	return (1);
}

/** Removes the known vogship preference */
char	*vg_get_pref(char *preference_name, char *default_value)
{
	t_str	pref_file;
	char	c;
	int		fd;
	t_str	read_line;
	size_t	i;
	t_str	pref_check;

	if (!is_valid_preference_key(preference_name))
		return (default_value);

	pref_file = vg_run(ft_strjoin("printf ", VG_PREFERENCE_FILE));
	if (!pref_file)
		return (default_value);
	
	fd = open(pref_file, O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		return (default_value);
	free(pref_file);

	pref_check = ft_strjoin(preference_name, "=");
	if (!pref_check)
		return (default_value);

	lseek(fd, 0, SEEK_SET);

	read_line = (t_str) ft_calloc(1025, sizeof(char));
	if (!read_line)
		return (default_value);
	i = 0;

	while (1)
	{
		if (!read(fd, &c, sizeof(char)) || c == '\n')
		{
			if (!ft_strncmp(read_line, pref_check, ft_strlen(pref_check)))
			{
				close(fd);
				i = ft_strlen(pref_check);
				free(pref_check);
				pref_check = ft_strdup(read_line+i);
				free(read_line);
				return (pref_check);
			}
			i = 0;
			ft_bzero(read_line, 1024 * sizeof(char));
			if (c != '\n')
				break;
		}
		else
			read_line[i++] = c;
	}
	free(pref_check);
	free(read_line);
	close(fd);
	return (default_value);
}

/** Sets the known preference of vogship to a certain value */
int	vg_set_pref(t_str preference_name, t_str value)
{
	t_str	pref_file;
	t_str	tmp_file;
	char	c;
	int		fd;
	int		tfd;
	t_str	read_line;
	size_t	i = 0;
	t_str	pref_check;
	t_str	valid_line;

	if (!is_valid_preference_key(preference_name) || !value)
		return (0);

	pref_file = vg_run(ft_strjoin("printf ", VG_PREFERENCE_FILE));
	if (!pref_file)
		return (0);
		
	tmp_file = vg_run(ft_strjoin("printf ", VG_TMP_PREF_FILE));
	if (!tmp_file)
		return (0);
	
	fd = open(pref_file, O_RDWR|O_CREAT, 0777);
	tfd = open(tmp_file, O_RDWR|O_CREAT, 0777);
	free(pref_file);
	if (fd == -1 || tfd == -1)
		return (0);

	pref_check = ft_strjoin(preference_name, "=");
	if (!pref_check)
		return (0);

	valid_line = ft_strjoin(pref_check, value);
	if (!valid_line)
		return (0);

	while (read(fd, &c, sizeof(char)))
		i += write(tfd, &c, sizeof(char));
	ftruncate(tfd, i);

	lseek(fd, 0, SEEK_SET);
	lseek(tfd, 0, SEEK_SET);

	read_line = (t_str) ft_calloc(1025, sizeof(char));
	if (!read_line)
		return (0);
	i = 0;

	while (1)
	{
		if (!read(tfd, &c, sizeof(char)) || c == '\n')
		{
			if (!ft_strncmp(read_line, pref_check, ft_strlen(pref_check)))
			{
				free(read_line);
				free(pref_check);
				write(fd, valid_line, ft_strlen(valid_line));
				write(fd, "\n", sizeof(char));
				free(valid_line);
				while (1)
				{
					if (!read(tfd, &c, sizeof(char)))
						break;
					else
						write(fd, &c, sizeof(char));
				}
				ftruncate(fd, lseek(fd, 0, SEEK_CUR));
				close(fd);
				close(tfd);
				remove(tmp_file);
				free(tmp_file);
				return (1);
			}
			lseek(fd, lseek(tfd, 0, SEEK_CUR), SEEK_SET);
			i = 0;
			ft_bzero(read_line, 1024 * sizeof(char));
			if (c != '\n')
			{
				if (lseek(tfd, 0, SEEK_CUR))
					write(fd, "\n", 1);
				break;
			}
		}
		else
			read_line[i++] = c;
	}
	free(read_line);
	free(pref_check);
	close(tfd);
	write(fd, valid_line, ft_strlen(valid_line));
	ftruncate(fd, lseek(fd, 0, SEEK_CUR));
	free(valid_line);
	close(fd);
	remove(tmp_file);
	free(tmp_file);
	return (1);
}

/** Removes the known vogship preference */
int	vg_del_pref(t_str preference_name)
{
	t_str	pref_file;
	t_str	tmp_file;
	char	c;
	int		fd;
	int		tfd;
	t_str	read_line;
	size_t	i = 0;
	t_str	pref_check;

	if (!is_valid_preference_key(preference_name))
		return (0);

	pref_file = vg_run(ft_strjoin("printf ", VG_PREFERENCE_FILE));
	if (!pref_file)
		return (0);
	
	tmp_file = vg_run(ft_strjoin("printf ", VG_TMP_PREF_FILE));
	if (!tmp_file)
		return (0);
	
	fd = open(pref_file, O_RDWR|O_CREAT, 0777);
	tfd = open(tmp_file, O_RDWR|O_CREAT, 0777);
	free(pref_file);
	if (fd == -1 || tfd == -1)
		return (0);

	pref_check = ft_strjoin(preference_name, "=");
	if (!pref_check)
		return (0);

	while (read(fd, &c, sizeof(char)))
		i += write(tfd, &c, sizeof(char));
	ftruncate(tfd, i);

	lseek(fd, 0, SEEK_SET);
	lseek(tfd, 0, SEEK_SET);

	read_line = (t_str) ft_calloc(1025, sizeof(char));
	if (!read_line)
		return (0);
	i = 0;

	while (1)
	{
		if (!read(tfd, &c, sizeof(char)) || c == '\n')
		{
			if (!ft_strncmp(read_line, pref_check, ft_strlen(pref_check)))
			{
				free(pref_check);
				free(read_line);
				while (1)
				{
					if (!read(tfd, &c, sizeof(char)))
						break;
					else
						write(fd, &c, sizeof(char));
				}
				ftruncate(fd, lseek(fd, 0, SEEK_CUR));
				close(tfd);
				close(fd);
				remove(tmp_file);
				free(tmp_file);
				return (1);
			}
			lseek(fd, lseek(tfd, 0, SEEK_CUR), SEEK_SET);
			i = 0;
			ft_bzero(read_line, 1024 * sizeof(char));
			if (c != '\n')
			{
				if (lseek(tfd, 0, SEEK_CUR))
					write(fd, "\n", 1);
				break;
			}
		}
		else
			read_line[i++] = c;
	}
	free(pref_check);
	free(read_line);
	close(tfd);
	close(fd);
	remove(tmp_file);
	free(tmp_file);
	return (1);
}