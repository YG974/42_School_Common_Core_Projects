#include "libasm.h"

void		ft_strlen_test(const char *s)
{
	size_t	d;

	d = strlen(s);
	printf("- The input string is : '%s'\n", s);
	printf("1) lib.c strlen function output is: %lu\n", d);
	d = ft_strlen(s);
	printf("2) my ft_strlen function output is: %lu\n", d);
	return ;
}

void		ft_strcpy_test(char *d, const char *s)
{
	printf("- The input string is : '%s'\n", s);
	d = strcpy(d, s);
	printf("1) lib.c strcpy function output is: %s\n", d);
	d = ft_strcpy(d, s);
	printf("2) my ft_strcpy function output is: %s\n", d);
}

void		ft_strcmp_test(const char *s1, const char *s2)
{
	int d;

	printf("- The input string 1 is : '%s'\n", s1);
	printf("- The input string 2 is : '%s'\n", s2);
	d = strcmp(s1, s2);
	printf("1) lib.c strcmp function output is: %d\n", d);
	d = ft_strcmp(s1, s2);
	printf("2) my ft_strcmp function output is: %d\n", d);
}

void	ft_write_test(int fildes, const void *buf, size_t nbyte)
{
	size_t d;

	printf("(fd = %u | ", fildes);
	printf("buffer = '%s' | ", (char *)buf);
	printf("nbyte = %zu)\n", nbyte);
	printf("1) lib.c write function output is:\n");
	errno = 0;
	d = write(fildes, buf, nbyte);
	printf("\nreturn = %d | errno : %d\n", (int)d, errno);
	printf("2) my ft_write function output is:\n");
	errno = 0;
	d = ft_write(fildes, buf, nbyte);
	printf("\nreturn = %d | errno : %d\n", (int)d, errno);
	return ;
}

void	ft_read_test(char *file, size_t nbyte)
{
	size_t	d;
	int		fd;
	char	b1[300];
	char	b2[300];
	int		i;

	i = 0;
	while (i < 300)
		b1[i++] = 0;
	i = 0;
	while (i < 300)
		b2[i++] = 0;
	if (!(fd = open(file, O_RDONLY)))
		return ;
	printf("1) lib.c read function output is:\n");
	errno = 0;
	d = read(fd, &b1, nbyte);
	printf("%s", b1);
	printf("\nreturn = %d | errno : %d\n", (int)d, errno);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return ;
	printf("2) my ft_read function output is:\n");
	errno = 0;
	d = ft_read(fd, &b2, nbyte);
	printf("%s", b2);
	printf("\nreturn = %d | errno : %d\n", (int)d, errno);
	close(fd);
	return ;
}
void		ft_strdup_test(const char *s)
{
	char		*dst;
	char		*dst2;

	printf("src string is :	%s\n", s);
	printf("1) lib.c strdup function output is:\n");
	errno = 0;
	dst = strdup(s);
	printf("%s | errno : %d\n", dst, errno);
	errno = 0;
	dst2 = ft_strdup(s);
	printf("2) my ft_strdup function output is:\n");
	printf("%s | errno : %d\n", dst2, errno);
	free(dst);
	free(dst2);
}

int			main()
{
	char		d[300];
	char		null[300];

	null[0] = '\0';
	printf("----------------------------------------------------\n");
	printf("			TEST OF MY LIBASM FUNCTIONS\n");
	printf("----------------------------------------------------\n");
	printf("			TEST OF FT_STRLEN\n");
	printf("regular string\n");
	ft_strlen_test("salut les copains");
	printf("----------------------------------------------------\n");
	printf("the string is empty, first char = '\\0'\n");
	ft_strlen_test(null);

	printf("----------------------------------------------------\n");
	printf("			TEST OF FT_STRCPY\n");
	printf("regular string\n");
	ft_strcpy_test(d,"salut les copains");
	printf("----------------------------------------------------\n");
	printf("the string is empty, first char = '\\0'\n");
	ft_strcpy_test(d, null);
	printf("----------------------------------------------------\n");

	printf("			TEST OF FT_STRCMP\n");
	printf("equals strings\n");
	ft_strcmp_test("salut les copains","salut les copains");
	printf("----------------------------------------------------\n");
	printf("first string shorter\n");
	ft_strcmp_test("salut les","salut les copains");
	printf("----------------------------------------------------\n");
	printf("second string shorter\n");
	ft_strcmp_test("salut les","sal");
	printf("----------------------------------------------------\n");
	printf("differents strings\n");
	ft_strcmp_test("salut les bogoss","salut les mitos");
	printf("----------------------------------------------------\n");
	printf("first string is '\\0'\n");
	ft_strcmp_test(null,"salut les mitos");
	printf("----------------------------------------------------\n");
	printf("second string is '\\0'\n");
	ft_strcmp_test("salut les mitos",null);
	printf("----------------------------------------------------\n");
	printf("both strings are '\\0'\n");
	ft_strcmp_test(null, null);
	printf("----------------------------------------------------\n");

	printf("			TEST OF FT_WRITE\n");
	printf("regular std out\n");
	ft_write_test(1, "std error first write test", 27);
	printf("----------------------------------------------------\n");
	printf("error std out\n");
	ft_write_test(2, "second write test with sdtout", 30);
	printf("----------------------------------------------------\n");
	printf("negative len\n");
	ft_write_test(1, "len neg", -10);
	printf("----------------------------------------------------\n");
	printf("negative file descriptor\n");
	ft_write_test(-1, "fd neg", 10);

	printf("----------------------------------------------------\n");
	printf("			TEST OF FT_READ\n");
	printf("len > filesize\n");
	ft_read_test("read.txt", 300);
	printf("----------------------------------------------------\n");
	printf("len < filesize\n");
	ft_read_test("read.txt", 30);
	printf("----------------------------------------------------\n");
	printf("len < 0\n");
	ft_read_test("read.txt", -300);
	printf("----------------------------------------------------\n");
	printf("no reading rights\n");
	ft_read_test("norights.txt", 300);
	printf("----------------------------------------------------\n");

	printf("----------------------------------------------------\n");
	printf("			TEST OF FT_STRDUP\n");
	printf("regular string\n");
	ft_strdup_test("I'm testing my ft_strdup");
	printf("----------------------------------------------------\n");
	printf("empty string\n");
	ft_strdup_test(null);
	printf("----------------------------------------------------\n");
	return (0);
}
