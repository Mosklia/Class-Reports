#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <origin> <target>\n", argv[0]);
        exit(1);
    }

    int origin_desc = open(argv[1], O_RDONLY);
    struct stat origin_stat;
    int origin_err = fstat(origin_desc, &origin_stat);

    if (origin_err != 0)
    {
        fprintf(stderr, "ERROR: Cannot open origin file %s.\n", argv[1]);
        fprintf(stderr, "ERROR: fstat() returned value %d.\n", origin_err);
        fprintf(stderr, "ERROR: Errno set to %d.\n", errno);
        exit(2);
    }
    else if (S_ISDIR(origin_stat.st_mode))
    {
        fprintf(stderr, "ERROR: Origin file %s is a directory.\n", argv[1]);
        exit(3);
    }

    struct stat target_stat;
    int target_err = -1;
    int target_desc;

    if (stat(argv[2], &target_stat) != 0)
    {
        if (errno == ENOENT)
        {
            target_desc = creat(argv[2], origin_stat.st_mode & 07777);
            target_err = fstat(target_desc, &target_stat);
        }
        if (target_err != 0)
        {
            fprintf(stderr, "ERROR: Cannot create target file %s.\n", argv[1]);
            fprintf(stderr, "ERROR: fstat() returned value %d.\n", origin_err);
            fprintf(stderr, "ERROR: Errno set to %d.\n", errno);
            exit(4);
        }
    }
    else // Target file exists
    {
        fprintf(stderr, "ERROR: Target file %s exists.\n", argv[2]);
        exit(5);
        // target_desc = open(argv[2], O_WRONLY);
        // target_err = fstat(target_desc, &target_stat);
        // if (target_err != 0)
        // {
        //     fprintf(stderr, "ERROR: Cannot create target file %s.\n", argv[2]);
        //     fprintf(stderr, "ERROR: fstat() returned value %d.\n", origin_err);
        //     fprintf(stderr, "ERROR: Errno set to %d.\n", errno);
        //     exit(5);
        // }
        // else if (!S_ISDIR(target_stat.st_mode))
        // {
        //     fprintf(stderr, "ERROR: Target file %s exists and is not a directory.\n", argv[2]);
        //     exit(6);
        // }
    }

    size_t buf_size = sizeof(char) * 50;
    void *buf = (void*)malloc(buf_size);
    int read_cnt = 0;

    do
    {
        read_cnt = read(origin_desc, buf, buf_size);
        write(target_desc, buf, read_cnt);
    }
    while (read_cnt == buf_size);

    // printf("%d\n", S_ISDIR(origin_stat.st_mode));

    close(target_desc);
    close(origin_desc);
}