/* 编译: gcc win_list.c -o win_list.exe -liphlpapi -lws2_32
 * 运行: ./win_list
 */

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

#define ERROR_BUFFER_OVERFLOW -1
#define ERROR_SUCCESS 0

int main()
{
    WSADATA d;
    if (WSAStartup(MAKEWORD(2, 2), &d))
    {
        printf("Failed to initialize.\n");
        return -1;
    }

    // 适配器地址缓冲区的大小
    DWORD asize = 20000;
    PIP_ADAPTER_ADDRESSES adapters;
    do
    {
        // 分配内存
        adapters = (PIP_ADAPTER_ADDRESSES)malloc(asize);

        if (!adapters)
        {
            printf("Couldn't allocate %ld bytes for adapters.\n", asize);
            WSACleanup();
            return -1;
        }

        // AF_UNSPEC包括IPv4和IPv6地址
        int r = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, 0,
                                     adapters, &asize);

        // 缓冲区不够大，返回错误并将缓冲区大小设置为需要的大小
        if (r == ERROR_BUFFER_OVERFLOW)
        {
            printf("GetAdaptersAddresses wants %ld bytes.\n", asize);
            free(adapters);
        }
        else if (r == ERROR_SUCCESS)
        {
            break;
        }
        else
        {
            printf("Error from GetAdaptersAddresses: %d\n", r);
            free(adapters);
            WSACleanup();
            return -1;
        }
    }
    while (!adapters);

    // 返回成功的adapters是一个链表结构，包含各个适配器的地址信息
    PIP_ADAPTER_ADDRESSES adapter = adapters;

    // adapter遍历到链表末尾时，值为0
    while (adapter)
    {
        printf("\nAdapter name: %S\n", adapter->FriendlyName);

        // address也是链表结构
        PIP_ADAPTER_UNICAST_ADDRESS address = adapter->FirstUnicastAddress;
        while (address)
        {
            printf("\t%s",
                   address->Address.lpSockaddr->sa_family == AF_INET ? "IPv4" : "IPv6");

            // 存储地址的文本表示
            char ap[100];

            getnameinfo(address->Address.lpSockaddr,
                        address->Address.iSockaddrLength,
                        ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
            printf("\t%s\n", ap);

            address = address->Next;
        }

        adapter = adapter->Next;
    }


    // 释放内存
    free(adapters);
    WSACleanup();

    return 0;
}
