#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char buf[128];

    memset(buf, 0, sizeof(buf));

    int fd = open("/sys/class/i2c-adapter/i2c-0/name", 0);

    read(fd, buf, sizeof(buf));

    printf("buf = %s\r\n", buf);

    close(fd);

    return 0;
}
