#include <bits/stdc++.h> // Library for common data structures and algos
#include <stdio.h>       // Standard IO
#include <unistd.h>
#include <sys/types.h>  // For common syscalls
#include <sys/wait.h>   // For wait
#include <fcntl.h>      // For File handling
#include <sys/stat.h>   // For attributes of file
#include <dirent.h>     // For directory handling
#include <libgen.h>     // General purpose library
#include <sys/poll.h>   // For polling
#include <sys/mman.h>   // For mmap munmap
#include <signal.h>     // For signals
#include <sys/time.h>   // For Timer
#include <netdb.h>      // For socket programming
#include <netinet/in.h> // For socket programming

using namespace std;

void read_example()
{
    cout << "READ EXAMPLE" << endl;
    char *x = (char *)calloc(100, sizeof(char));
    read(STDIN_FILENO, x, 10);
    cout << "Read from file: ";
    write(STDOUT_FILENO, x, 10);
    cout << endl;
}

void poll_example()
{
    cout << "POLL EXAMPLE" << endl;

    struct pollfd fds[3];
    int ret;

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
    ret = poll(fds, 3, 5 * 1000);
    if (ret == -1)
    {
        cout << "Polling timeout!" << endl;
        exit(0);
    }

    if (!ret)
    {
        printf("%d seconds elapsed.\n", 5);
    }

    if (fds[0].revents & POLLIN)
    {
        printf("Read Event Successful\n");
    }
}

void lseek_example()
{
    cout << "LSEEK EXAMPLE" << endl;

    int f_write = open("temp.txt", O_RDONLY);
    int f_read = open("tempt.txt", O_WRONLY);

    int count = 0;
    char arr[100];
    int n;
    n = 5;
    while (read(f_write, arr, 1))
    {
        if (count < n)
        {
            lseek(f_write, n, SEEK_CUR);
            write(f_read, arr, 1);
            count = n;
        }
        else
        {
            count = (2 * n);
            lseek(f_write, count, SEEK_CUR);
            write(f_read, arr, 1);
        }
    }
    close(f_write);
    close(f_read);
    cout << "LSEEK Successful!" << endl;
}

void map_example()
{
    cout << "MAP EXAMPLE" << endl;
    char *addr;
    int fd;
    struct stat sb;
    off_t offset, pa_offset;
    size_t length;
    ssize_t s;

    fd = open("temp.txt", O_RDONLY);
    offset = 2;
    pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
    if (offset >= sb.st_size)
    {
        fprintf(stderr, "offset is past end of file\n");
        exit(EXIT_FAILURE);
    }

    length = 5;

    addr = (char *)mmap(NULL, length + offset - pa_offset, PROT_READ,
                        MAP_PRIVATE, fd, pa_offset);
    if (addr == MAP_FAILED)
        cout << "MAP Error! Error: " << strerror(errno) << endl;

    s = write(STDOUT_FILENO, addr + offset - pa_offset, length);
    cout << endl;

    munmap(addr, length + offset - pa_offset);
    close(fd);
}

void p_example()
{
    cout << "PWRITE EXAMPLE" << endl;
    pwrite64(open("tempt.txt", O_WRONLY), "Hello World", strlen("Hello World"), 0);

    cout << "PREAD EXAMPLE" << endl;
    char *x = (char *)calloc(100, sizeof(char));
    pread64(open("temp.txt", O_RDONLY), x, 10, 0);
    printf("Read Text: %s\n", x);
}

void alarm_example()
{
    cout << "ALARM EXAMPLE" << endl;

    // Setting alarm
    alarm(2);
    for (int i = 1; i < 3; i++)
    {

        printf("%d : Inside main function\n", i);
        sleep(1);
    }
}

void sig_handler(int signum)
{

    printf("ALARM Successful\n");
}

unsigned int x = 0;
void interrupt(int signum)
{
    printf("timer %d!\n", ++x);
}

void timer_example()
{
    cout << "TIMER EXAMPLE" << endl;
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &interrupt;

    // Sigaction handler
    sigaction(SIGPROF, &sa, NULL);

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 5000;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 5000;

    // Set timer example
    setitimer(ITIMER_PROF, &timer, NULL);
}

void kill_example()
{
    cout << "KILL EXAMPLE" << endl;

    cout << "Process will get killed now!" << endl;
    kill(getpid(), 0);
}

void pause_example()
{
    cout << "PAUSE EXAMPLE" << endl;
    int ret = 0;
    ret = pause();
    printf("Pause returned with %d\n", ret);
}

void pipe_example()
{
    cout << "PIPE EXAMPLE" << endl;
    int pipefds[2];
    char *pin;
    char buffer[5];

    if (pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        pin = "4821\0";
        close(pipefds[0]);
        write(pipefds[1], pin, 5);

        printf("Generating data in child and sending to parent...\n");
        sleep(2); // intentional delay
        exit(EXIT_SUCCESS);
    }

    if (pid > 0)
    {
        wait(NULL);
        close(pipefds[1]);
        read(pipefds[0], buffer, 5);
        close(pipefds[0]);

        printf("Parent received data '%s'\n", buffer);
    }
}


int main()
{
    signal(SIGALRM, sig_handler);
    // read_example();
    // poll_example();
    // lseek_example();
    // map_example();
    // p_example();
    // alarm_example();
    // timer_example();
    // kill_example();
    // pause_example();
    // pipe_example();

    return 0;
}