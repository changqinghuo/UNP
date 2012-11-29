#include <unp.h>
int main(int argc, char** argv)
{
	int listenfd, connfd;
    pid_t childpid;
	socklen_t child;
    struct sockaddr_in serv_addr, cli_addr;
    listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(listenfd == -1)
    {
        printf("Socket error!\n");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
   if( bind(listenfd, (__CONST_SOCKADDR_ARG)&serv_addr, sizeof(serv_addr))== -1)
   {
       printf("bind error\n");
       return 1;
   }
   if( listen(listenfd, 5)== -1)
   {
       printf("listen erro\n");
       return 1;
   }
   printf("Listening on port 8888\n");

    while(1)
    {
        int clilen = sizeof(cli_addr);
        connfd = accept(listenfd,( __SOCKADDR_ARG)&cli_addr, &clilen);
        if(connfd < 0)
        {
            printf("connect error\n");
            return 1;
        }

        if((childpid = fork())== 0 )
        {
            printf("calling str_echo!\n");
            str_echo(connfd);
            return 0;
         //   char readbuf[1024];
         //   int n = 0;
         //   while((n=read(connfd, readbuf, sizeof(readbuf))) >= 0)
         //   {
         //   if(n < 0)
         //       return 1;
         //   readbuf[n] = '\0';
    //   //     printf("%s\n", readbuf);
         //   write(1, readbuf, strlen(readbuf));
         ////   sleep(100);
         //   }
         //   //char strout[1024];
         //  // inet_ntop(AF_INET, readbuf, strout, sizeof(strout));
         //  // printf("%s\n", strout);
         //   close(listenfd);
         //   exit(0);
        }

        close(connfd);
    }
    

    return 0;
}


    



    



    



