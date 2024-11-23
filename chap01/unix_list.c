/* 编译: gcc unix_list.c -o unix_list
 * 运行: ./unix_list
 */

#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct ifaddrs* addresses;

    // 分配内存并写入地址信息
    if (getifaddrs(&addresses) == -1)
    {
        printf("getifaddrs call failed\n");
        return -1;
    }

    struct ifaddrs* address = addresses;

    // 遍历地址
    while (address)
    {
        if (address->ifa_addr == NULL)
        {
            address = address->ifa_next;
            continue;
        }
        int family = address->ifa_addr->sa_family;

        if (family == AF_INET || family == AF_INET6)
        {
            printf("%s\t", address->ifa_name);
            printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

            // 存储地址的文本表示
            char ap[100];
            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);

            getnameinfo(address->ifa_addr,
                        family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);

            printf("\t%s\n", ap);
        }

        address = address->ifa_next;
    }

    // 释放内存
    freeifaddrs(addresses);

    return 0;
}
