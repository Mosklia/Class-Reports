#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define MAX_SEQUENCE_SIZE 25

typedef struct shared_data_t
{
    size_t sequence_size;
    long fib_sequence[MAX_SEQUENCE_SIZE + 1];
} shared_data_t;

void print_seq(shared_data_t *const data_ptr);
void child_task(const int shm_fd);

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fputs("Arguments too few.\n", stderr);
        return 1;
    }
    const size_t sequence_size = atoi(argv[1]);
    // 命令行参数不正确
    if (sequence_size > MAX_SEQUENCE_SIZE || sequence_size < 1)
    {
        fputs("Incorrect arguments.\n", stderr);
        return 1;
    }

    // 创建并配置共享内存
    const char *const shm_name = "fibonacci";
    const int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(shared_data_t));

    // 写入队列大小
    shared_data_t *const data_ptr = (shared_data_t *)mmap(
        0, sizeof(shared_data_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    data_ptr->sequence_size = sequence_size;

    const pid_t pid = fork();

    if (pid == 0)
    {
        child_task(shm_fd);
    }
    else if (pid > 0)
    {
        wait(0);
        print_seq(data_ptr);
        shm_unlink(shm_name);
    }
    else
    {
        return 1;
    }
}

void child_task(const int shm_fd)
{
    shared_data_t *const data_ptr = (shared_data_t *)mmap(
        0, sizeof(shared_data_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    data_ptr->fib_sequence[0] = 0;
    data_ptr->fib_sequence[1] = 1;
    for (size_t i = 2; i <= data_ptr->sequence_size; ++i)
    {
        data_ptr->fib_sequence[i] = data_ptr->fib_sequence[i - 1] + data_ptr->fib_sequence[i - 2];
    }

    print_seq(data_ptr);
}

// 输出一个序列的值
void print_seq(shared_data_t *const data_ptr)
{
    for (size_t i = 1; i <= data_ptr->sequence_size; ++i)
    {
        printf("%ld ", data_ptr->fib_sequence[i]);
    }
    putchar('\n');
}