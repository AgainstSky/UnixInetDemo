//
// Created by againstsky on 2022/9/28.
//



#include "lib/unp.h"

int main() {
    using namespace sky;
    int serverFd, clientFd;
    time_t times;
    char buff[sky::MAXLINE];
    struct sockaddr_in serverAddr;

    bzero(&serverAddr, sizeof(serverAddr));
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(13);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(serverFd, (SA *) &serverAddr, sizeof(serverAddr));
    listen(serverFd, LISTENQ);

    while (1) {
        clientFd = accept(serverFd, (SA *) NULL, NULL);
        times = time(NULL);
        snprintf(buff, sizeof(buff),"%.24s\r\n", ctime(&times));
        write(clientFd,buff, strlen(buff));
        close(clientFd);
    }
    exit(0);
}