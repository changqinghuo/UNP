#include "math.h"
#include "unp.h"
const int SERV_PORT = 8888;
const int BUFSIZE = 1024;
void str_cli(FILE* fp, int sockfd)
{

    int maxfdp1, stdineof;
    fd_set  rset;
    char buf[BUFSIZE];
    int n = 0;
    stdineof = 0;
    FD_ZERO(&rset);
    while(1)
    {
        if(stdineof == 0)
            FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdp1 = max(fileno(fp), sockfd) +1;
        select(maxfdp1, &rset, NULL, NULL, NULL);
        
        if(FD_ISSET(sockfd, &rset))
        {
            if ((n = read(sockfd,buf, BUFSIZE) == 0))
            {
                if(stdineof == 1)
                {
                    return;
                }
                else
                {
                    printf("Due to server terminated!\n");
                    return;
                }
                write(fileno(stdout), buf, n);

            }
        }

        if(FD_ISSET(fileno(stdin), &rset))
        {
            if((n = read(fileno(stdin), buf, BUFSIZE)) == 0)
            {
                stdineof = 1;
                shutdown(sockfd, SHUT_WR);
                FD_CLR(fileno(stdin), &rset);
                continue;
            }
            write(sockfd, buf, n);
        }







    }
}

