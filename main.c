#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

void	test0(void);
void	test1(void);
void	test2(void);
void	test3(void);
void	test4(void);
void	test5(void);
void	test6(void);
void	test7(void);
void	test8(void);
void	test9(void);
void	test10(void);
void	test11(void);

int	main(void)
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	//test11();

	return (0);
}

void	test0(void)
{
	char	filename[] = "./test_text_files/non_existing.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 0 ###");
	puts("Read from a nonexisting file.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test1(void)
{
	char	filename[] = "./test_text_files/empty.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 1 ###");
	puts("Read from an empty file.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');
                          

	return ;
}

void	test2(void)
{
	char	filename[] = "./test_text_files/newlines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 2 ###");
	puts("Read from a file with newlines only.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test3(void)
{
	char	filename[] = "./test_text_files/test.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 3 ###");
	puts("Read from a file with some short text.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test4(void)
{
	char	filename[] = "./test_text_files/no_access.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 4 ###");
	puts("Read from a file without reading or writing permissions.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test5(void)
{
	char	filename[] = "./test_text_files/short_lines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 5 ###");
	puts("Read from a file with short lines.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test6(void)
{
	char	filename[] = "./test_text_files/normal_text.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 6 ###");
	puts("Read from a file with \"normal\" line lengths.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test7(void)
{
	char	filename[] = "./test_text_files/longer_and_shorter_lines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 7 ###");
	puts("Read from a file with longer and shorter line lengths.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test8(void)
{
	char	filename[] = "./test_text_files/single_long_line.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 8 ###");
	puts("Read from a file with one very long line.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test9(void)
{
	char	filename[] = "./test_text_files/short_lines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 9 ###");
	puts("After 5 lines, \"close\" the file.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);

		if (line_counter == 5)
			close(fd);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test10(void)
{
	char	filename[] = "NO FILE, '42' AS FILE DESCRIPTOR";
	char	*line = NULL;
	int		fd = 42;
	int		line_counter = 0;

	puts("### TEST 10 ###");
	puts("No file has been opened, file descriptor set to an int value.");
	printf("filename\t->\t'%s'\n", filename);

	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	putchar('\n');

	return ;
}

void	test11(void)
{
	char	filename[] = "STDIN";
	char	*line = NULL;
	int		fd = 0;
	int		line_counter = 0;

	puts("### TEST 11 ###");
	puts("Read from the standard input.");
	printf("filename\t->\t'%s'\n", filename);

	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	putchar('\n');

	return ;
}
