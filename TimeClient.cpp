//
// Created by againstsky on 2022/9/28.
//

#include "lib/unp.h"


int main() {

    using namespace sky;

    int sockFd, n;

    char receiveLine[MAXLINE + 1];
    if ((sockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "can't open socket");
        exit(0);
    }
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(13);
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) < 0) {
        fprintf(stderr, "can't set server address");
        exit(0);
    }

    if (connect(sockFd, (SA *) &serverAddr, sizeof(serverAddr)) < 0) {
        fprintf(stderr, "can't connect server");
        exit(0);
    }

    while ((n = read(sockFd, receiveLine, MAXLINE)) > 0) {
        receiveLine[n] = 0;
        if (fputs(receiveLine, stdout) == EOF) {
            fprintf(stderr, "read failed");
            exit(0);
        }
    }
    if (n < 0) {
        fprintf(stderr, "read failed");
    }
    exit(0);
}