// Below code is from: http://blog.sina.com.cn/s/blog_67b7d7e401018dvz.html
#include<stdio.h>
#include <unistd.h>
 
int main(void)
{
    int fd[2];
    char buf[256];
    pid_t pid;
 
    if(pipe(fd) != 0) {
        puts("Pipe failed!");
    }
    else {
        puts("Pipe ok!");
    }
 
    if((pid=fork()) == 0) { // child process
        puts("Child");
        close(fd[0]);
        char str[]="Jack";
        write(fd[1], str, sizeof(str));
    }
    else {                  // father process
        puts("Father");
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        puts(buf);
    }
 
    return 0;
}
/* 
$ ./a.out 
Pipe ok!
Father
Child
Jack
 
 * */
