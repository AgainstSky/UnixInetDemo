//
// Created by againstsky on 2022/9/28.
//

#ifndef UNIXINETDEMO_UNP_H
#define UNIXINETDEMO_UNP_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <arpa/inet.h>

namespace sky {
    //名字定义

    using SA = struct sockaddr;



    //常量定义


    extern const int MAXLINE;

    extern const int LISTENQ;



    void test();
}
#endif //UNIXINETDEMO_UNP_H
