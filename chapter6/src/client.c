#include "unp.h"
int main(int arc, char** argv)
{
   if(arc != 2)
   {
       printf("Argument error!\n");
       return 1;
   }
   int sockfd = 0;
   struct sockaddr_in servaddr;
   struct in_addr addr;
   
   bzero(&servaddr, sizeof(servaddr));

   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(SERV_PORT);
   inet_aton(argv[1], &servaddr.sin_addr.s_addr);
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if(connect(sockfd, (__CONST_SOCKADDR_ARG)&servaddr, sizeof(servaddr)) == -1)
   {
       printf("connect error!\n");
       return 1;
   }
   
   str_cli(stdin, sockfd);
   return 0;



}

