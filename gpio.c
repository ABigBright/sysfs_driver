#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define GPIO_ROOT "/sys/class/gpio/"

int gpio_export(int gpio)
{
    char buf[128];
    int fd = open(GPIO_ROOT"export", O_WRONLY);
    if (fd < 0) {
        perror("open export failed");
        return fd;
    }
    int len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len + 1);
    close(fd);
   return 0;
}

int gpio_unexport(int gpio)
{
    char buf[128];
    int fd = open(GPIO_ROOT"unexport", O_WRONLY);
    if (fd < 0) {
        perror("open unexport failed");
        return fd;
    }
    int len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len + 1);
    close(fd);
   return 0;

}

/* 1: out */
/* 0: in */
int gpio_dir(int gpio, int dir)
{
    char buf[128];

    snprintf(buf, sizeof(buf), GPIO_ROOT"gpio%d/direction", gpio);

    int fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("open direction failed");
        return fd;
    }

    if (dir)
        write(fd, "out", strlen("out") + 1);
    else
        write(fd, "in", strlen("in") + 1);

    close(fd);

   return 0;
}

int gpio_pullup(int gpio)
{
    char buf[128];

    snprintf(buf, sizeof(buf), GPIO_ROOT"gpio%d/value", gpio);

    int fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("open gpio value failed");
        return fd;
    }
    write(fd, "1", 2);
    close(fd);

   return 0;
}

int gpio_pulldown(int gpio)
{
    char buf[128];

    snprintf(buf, sizeof(buf), GPIO_ROOT"gpio%d/value", gpio);

    int fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("open gpio value failed");
        return fd;
    }
    write(fd, "0", 2);
    close(fd);

   return 0;
}
