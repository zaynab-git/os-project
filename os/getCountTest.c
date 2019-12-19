#include "types.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
    printf(1, "initial fork count %d\n", getcount(SYS_fork,getpid()));
    if (fork() == 0) {
        printf(1, "child fork count %d\n", getcount(SYS_fork,getpid()));
        printf(1, "child write count %d\n", getcount(SYS_write,getpid()));
    } else {
        wait();
        printf(1, "parent fork count %d\n", getcount(SYS_fork,getpid()));
        printf(1, "parent write count %d\n", getcount(SYS_write,getpid()));
    }
    printf(1, "wait count %d\n", getcount(SYS_wait,getpid()));
    exit();
}
