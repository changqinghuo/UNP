#include "unp.h"
int main(int argc, char** argv)
{
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char buf[BUFSIZE];
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (__SOCKADDR_ARG) &servaddr, sizeof(servaddr));

    listen(listenfd, 5);

    maxfd = listenfd;
    maxi = -1;
    for(i = 0; i < FD_SETSIZE; i++)
    {
        client[i] = -1;
    }
    FD_ZERO(&allset);
    FD_ZERO(&rset);
    
    while(1)
    {
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);

        if(FD_ISSET(listenfd, &rset))
        {
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (__SOCKADDR_ARG)&cliaddr, clilen);

            for(i = 0; i < FD_SETSIZE; i++)
            {
                if(client[i] < 0)
                {
                    client[i] = connfd;
                    printf("new client arrives\n");
                    break;
                }
            
            }
            if(i == FD_SETSIZE)
            {
                printf("Too many clients for setsize\n");
            }
            FD_SET(connfd, &allset);
            if(connfd > maxfd)
                maxfd = connfd;
            if(i > maxi)
                maxi = i;
            
            if(--nready <= 0)   // no more readable descriptors
                continue;
        }

        for(i = 0; i <= maxi; i++)
        {
            if((sockfd = client[i]) < 0)
                continue;
            
            if(FD_ISSET(sockfd, &rset))
            {
                if((n = read(sockfd, buf, BUFSIZE)) == 0) //connection closed by client
                {
                    close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                }
                else
                {
                    printf("Got data from client: %s\n", buf);
                    write(sockfd, buf, n);
                }
                
                if (--nready <=0)
                    break;
            }
        }

        
    }
    
}
