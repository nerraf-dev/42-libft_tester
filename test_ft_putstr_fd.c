#include "tests.h"
#include <fcntl.h>
#include <sys/stat.h>

void test_ft_putstr_fd()
{
    // Test case 1: Writing an empty string to a file
    char *str1 = "";
    int fd1 = open("test1.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd(str1, fd1);
    close(fd1);

    // Test case 2: Writing a non-empty string to a file
    char *str2 = "Hello, world!";
    int fd2 = open("test2.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd(str2, fd2);
    close(fd2);

    // Now, read the files and check if the contents match the expected strings
    char buffer[100];
    ssize_t numRead;

    fd1 = open("test1.txt", O_RDONLY);
    numRead = read(fd1, buffer, strlen(str1));
    buffer[numRead] = '\0';  // Add null terminator
    printf("buffer: %s\n", buffer);
    printf("str1: %s\n", str1);
    assert(strcmp(buffer, str1) == 0);
    close(fd1);

    fd2 = open("test2.txt", O_RDONLY);
    numRead = read(fd2, buffer, strlen(str2));
    buffer[numRead] = '\0';  // Add null terminator
    assert(strcmp(buffer, str2) == 0);
    close(fd2);

    printf("ft_putstr_fd passed successfully!\n");
}