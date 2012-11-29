#include "unp.h"
const int MAXSIZE = 1024;

void str_echo(int sockfd)
{
    int n;
    char buf[MAXSIZE];
    while((n = read(sockfd, buf, MAXSIZE)) > 0)
    {
        write(1, buf, n);
    }
}
