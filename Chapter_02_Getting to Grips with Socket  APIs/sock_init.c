/*
 * 编译（Windows）：gcc sock_init.c -o sock_init.exe -lws2_32
 * 编译（Linux）：  gcc sock_init.c -o sock_init
 * 运行：          ./sock_init
 */

// include在Windows平台上所需要的头文件
#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

// 否则include伯克利的socket接口
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#endif

#include <stdio.h>

int main()
{
#if defined(_WIN32)
    WSADATA d;

    // 初始化Winsock
    if (WSAStartup(MAKEWORD(2, 2), &d))
    {
        fprintf(stderr, "Failed to initialize.\n");
        return 1;
    }
#endif

    // 伯克利socket接口不需要特别的初始化
    printf("Ready to use socket API.\n");

#if defined(_WIN32)
    WSACleanup();
#endif

    return 0;
}
