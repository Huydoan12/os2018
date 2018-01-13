#include <stdio.h>
#include <unistd.h>

int main()
{
printf("Main before!\n");
char *ps[] = {"/bin/ps", "-ef", NULL};
char *fr[] = {"free", "-h", NULL};
int pid,child;
printf("I am parent after fork()!");
pid=fork();

if (pid==0)
{
child=fork();
if (child==0)
{
execvp("free",fr);
}
else execvp("/bin/ps",ps);
}
}

