/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "stack.c"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int calc()
{
    if(pop() == '+')
        {
            int x = pop();
            int y = pop();
            return (x + y);
        }
        else if(pop() == '-')
        {
           int x = pop();
            int y = pop();
            return (x - y);
        }
        else if(pop() == '*')
        {
          int x = pop();
            int y = pop();
            return (x * y);
        }
        else if(pop() == '/')
        {
            int x = pop();
            int y = pop();
            return (x / y);
        }
        else if(pop() == '%')
        {
            int x = pop();
            int y = pop();
            return (x % y);
        }
        else
        {
           printf("Error: Not a valid operator");
        }
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *)&cli_addr,
                       &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    //stuff from client
    printf("Client: %s\n", buffer);

    /* ----- BEGIN: do the calculations ----- */
    char *token;
    /* get the first token */
    token = strtok(buffer, " ");
    /* walk through other tokens */
    while (token != NULL)
    {
        if( strstr(token, "+") != NULL)
        {
            // old debug code printf("Operate found: %s",token);
            push(43); // ascii for +
        }
        else if ( strstr(token, "-") != NULL)
        {
            // old debug code printf("Operate found: %s",token);
            push(45); // ascii for -
        }
        else if ( strstr(token, "*") != NULL)
        {
            // old debug code printf("Operate found: %s",token);
            push(42); // ascii for *
        }
        else if ( strstr(token, "/") != NULL)
        {
            // old debug code printf("Operate found: %s",token);
            push(47); // ascii for /
        }
        else if ( strstr(token, "%") != NULL)
        {
            // old debug code printf("Operate found: %s",token);
            push(37); // ascii for %
        }
        else
        {
            push(atoi(token));
        }
        
        // old debug code printf(" %s\n", token);
        token = strtok(NULL, " ");
    }
    /* ----- END: do the calculations ----- */
    // old debug code display();
    int result = calc();
    char result_arr [64];
    // old debug code printf("Result: %d \n",result);
    sprintf(result_arr, "%d",result);
    // message to sent back to client
    n = write(newsockfd,"Server: ",8);
    n = write(newsockfd,result_arr,64);

    if (n < 0)
        error("ERROR writing to socket");
    close(newsockfd);
    close(sockfd);
    return 0;
}