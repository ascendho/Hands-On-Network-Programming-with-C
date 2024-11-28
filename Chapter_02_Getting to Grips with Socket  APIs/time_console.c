/*
 * 编译：gcc time_console.c -o time_console
 * 运行：./time_console
 */

#include <stdio.h>
#include <time.h>

int main()
{
    time_t timer;
    time(&timer);

    printf("Local time is: %s", ctime(&timer));

    return 0;
}
