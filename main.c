#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define POSITION_FILE ".position"  // File to store last read position

// int get_last_position()
// {
//     int position = 0;
//     FILE *file = fopen(POSITION_FILE, "r");
//     if (file)
//     {
//         fscanf(file, "%d", &position);
//         fclose(file);
//     }
//     return position;
// }

// void save_position(int position)
// {
//     FILE *file = fopen(POSITION_FILE, "w");
//     if (file)
//     {
//         fprintf(file, "%d", position);
//         fclose(file);
//     }
// }

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int last_position;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    fd = open("read_error.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Get last position and seek to it
    //last_position = get_last_position();
    //lseek(fd, last_position, SEEK_SET);

    // Read one line
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    close(fd);
    printf("fd is:%d\n", fd);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
 /*   if (line)
    {
        printf("%s", line);
        save_position(last_position + ft_strlen(line));  // Update position
        free(line);
    }
    else
    {
        printf("End of file reached.\n");
        remove(POSITION_FILE);  // Reset when EOF
    }
*/
    return (0);
}
