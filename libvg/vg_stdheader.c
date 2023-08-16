/* ========================================================================== */
/*                                                                            */
/*                                                             /   /   \      */
/*   Made By IsCoffeeTho (Aaron Menadue)                     /    |      \    */
/*                                                          |     |       |   */
/*   vg_stdheader.c                                         |      \      |   */
/*                                                          |       |     |   */
/*   Last Edited: 08:22AM 17/08/2023                         \      |    /    */
/*                                                             \   /   /      */
/*                                                                            */
/* ========================================================================== */

#include "vogship.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#ifndef STDHEADER_LENGTH
# define STDHEADER_LENGTH 80
#endif

#ifndef STDHEADER_MARGIN
# define STDHEADER_MARGIN 5
#endif

t_str ascii_art[7] = {
"        :::      ::::::::",
"      :+:      :+:    :+:",
"    +:+ +:+         +:+  ",
"  +#+  +:+       +#+     ",
"+#+#+#+#+#+   +#+        ",
"     #+#    #+#          ",
"    ###   #########.fr   "
};

t_str start = "/*";
t_str end = "*/";
char fill = '*';

t_str	stdhd_tformat()
{
	t_str timefmt;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	timefmt = (t_str) ft_calloc(20, sizeof(char));
	if (timefmt == NULL)
		return (NULL);
	sprintf(timefmt, "%04d/%02d/%02d %02d:%02d:%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	return ((t_str) timefmt);
}

t_str crepeat(char c, int n)
{
	t_str	tmp;
	int 	i;

	tmp = (t_str) ft_calloc((n + 1), sizeof(char));
	i = 0;
	while (i < n)
		tmp[i++] = c;
	return (tmp);
}

t_str text_line(t_str left, t_str right)
{
	t_str line;
	t_str buf;
	int marginleft;
	int marginmid;
	int marginright;
	int marginend;

	line = (t_str) ft_calloc(STDHEADER_LENGTH+1, sizeof(char));
	ft_strlcat(line, start, STDHEADER_MARGIN);
	marginend = STDHEADER_LENGTH - ft_strlen(end);
	marginright = STDHEADER_LENGTH - STDHEADER_MARGIN;
	marginmid = marginright - ft_strlen(right);
	marginleft = STDHEADER_MARGIN + ft_strlen(left);

	buf = crepeat(' ', STDHEADER_MARGIN);
	ft_strlcat(line, buf, STDHEADER_MARGIN+1);
	ft_strlcat(line, left, marginleft+1);
	buf = crepeat(' ', STDHEADER_LENGTH);
	ft_strlcat(line, buf, marginmid+1);
	ft_strlcat(line, right, marginright);
	buf = crepeat(' ', STDHEADER_MARGIN);
	ft_strlcat(line, buf, marginend+1);
	ft_strlcat(line, end, STDHEADER_LENGTH+1);
	ft_strlcat(line, "\n", STDHEADER_LENGTH+2);
	return (line);
}

t_str fill_line()
{
	t_str	line;
	t_str	tmp;
	int		fillwidth;

	line = (t_str) ft_calloc((STDHEADER_LENGTH+2), sizeof(char));
	ft_strlcat(line, start, STDHEADER_MARGIN);
	fillwidth = STDHEADER_LENGTH - ft_strlen(end) - ft_strlen(start) - 2;
	ft_strlcat(line, " ", STDHEADER_LENGTH+1);
	tmp = crepeat(fill, fillwidth);
	ft_strlcat(line, tmp, STDHEADER_LENGTH+1);
	ft_strlcat(line, " ", STDHEADER_LENGTH+1);
	ft_strlcat(line, end, STDHEADER_LENGTH+1);
	ft_strlcat(line, "\n", STDHEADER_LENGTH+2);

	return (line);
}

t_str	stdhd_user()
{
	t_str	tmp;

	tmp = vg_run("echo $USER");
	tmp = ft_strtrim(tmp, "\n");
	if (!tmp)
	{
		tmp = ft_strdup("marvin");
	}
	return (tmp);
}

t_str	stdhd_mail()
{
	t_str	tmp;

	tmp = vg_run("echo $MAIL");
	tmp = ft_strtrim(tmp, "\n");
	if (!ft_strncmp(tmp, "", 2))
		tmp = ft_strdup("marvin@42.fr");
	return (tmp);
}

int		vg_stdheader(t_str filepath)
{
	t_str		header;
	t_str		tmp;
	t_str		filled;
	int c;

	int			fd;
	int			tfd;
	struct stat fst;

	fd = open(filepath, O_RDWR);
	fstat(fd, &fst);
	if (!fd)
	{
		write(2, "An error occured when opening files.\n", 37);
		return (0);
	}

	if (access( filepath, F_OK ) != 0)
	{
    	write(2, "File doesn't exist!\n", 20);
		return (0);
	}
	else if (S_ISDIR(fst.st_mode))
	{
		write(2, "Cannot :Stdheader on a directory\n", 33);
		return (0);
	}
	else
	{
		header = (t_str) ft_calloc(((STDHEADER_LENGTH + 1) * 12) + 1, sizeof(char));
		if (header == NULL)
			return (0);

		tfd = open("vogshipstdheader", O_CREAT | O_RDWR, 0777);
		if (!tfd)
		{
			write(2, "An error occured when opening files.\n", 37);
			return (0);
		}

		while (read(fd, &c, sizeof(char)))
			write(tfd, &c, sizeof(char));
		ftruncate(tfd, lseek(fd, 0, SEEK_CUR));

		filled = fill_line();
		ft_memcpy(header, filled, ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, text_line("", ""), ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, text_line("", ascii_art[0]), ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, text_line(filepath, ascii_art[1]), ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, text_line("", ascii_art[2]), ((STDHEADER_LENGTH + 1) * 12));
		tmp = (char *) ft_calloc(STDHEADER_LENGTH+1, sizeof(char));
		if (tmp == NULL)
			return (0);
		sprintf(tmp, "By: %s <%s>", stdhd_user(), stdhd_mail());
		ft_strlcat(header, text_line(tmp, ascii_art[3]), ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, text_line("", ascii_art[4]), ((STDHEADER_LENGTH + 1) * 12));
		sprintf(tmp, "Created: %s by %s", stdhd_tformat(), stdhd_user());
		ft_strlcat(header, text_line(tmp, ascii_art[5]), ((STDHEADER_LENGTH + 1) * 12));
		sprintf(tmp, "Updated: %s by %s", stdhd_tformat(), stdhd_user());
		ft_strlcat(header, text_line(tmp, ascii_art[6]), ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, text_line("", ""), ((STDHEADER_LENGTH + 1) * 12));
		ft_strlcat(header, filled, ((STDHEADER_LENGTH + 1) * 12));
		lseek(fd, 0, SEEK_SET);
		write(fd, header, ft_strlen(header));
		write(fd, "\n", 1);
		lseek(tfd, 0, SEEK_SET);
		while (read(tfd, &c, sizeof(char)))
			write(fd, &c, sizeof(char));
		close(fd);
		close(tfd);
		remove("vogshipstdheader");
		return (1);
	}
}
