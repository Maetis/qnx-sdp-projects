#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <fcntl.h>
#include <string.h>

int main() {

    // Connect to the GPIO server
    int fd_red = open("/dev/gpio/18", O_RDWR);
    if (fd_red == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    int fd_yellow = open("/dev/gpio/23", O_RDWR);
    if (fd_yellow == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    int fd_green = open("/dev/gpio/24", O_RDWR);
    if (fd_green == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Set pins as output
    const char *message = "out";
    ssize_t bytes_written = write(fd_red, message, strlen(message));
    if (bytes_written == -1) {
        perror("write");
        close(fd_red);
        return 1;
    }

    bytes_written = write(fd_yellow, message, strlen(message));
    if (bytes_written == -1) {
        perror("write");
        close(fd_yellow);
        return 1;
    }

    bytes_written = write(fd_green, message, strlen(message));
    if (bytes_written == -1) {
        perror("write");
        close(fd_green);
        return 1;
    }

    // Set pins to high
    printf("LEDs on\n");
    const char *message_high = "on";
    bytes_written = write(fd_red, message_high, strlen(message_high));
    if (bytes_written == -1) {
        perror("write");
        close(fd_red);
        return 1;
    }

    bytes_written = write(fd_yellow, message_high, strlen(message_high));
    if (bytes_written == -1) {
        perror("write");
        close(fd_yellow);
        return 1;
    }

    bytes_written = write(fd_green, message_high, strlen(message_high));
    if (bytes_written == -1) {
        perror("write");
        close(fd_green);
        return 1;
    }

    // sleep for 1 second
    printf("Waiting for one second\n");
    sleep(1);

    // Set pins to low
    printf("LEDs off\n");
    const char *message_low = "off";
    bytes_written = write(fd_red, message_low, strlen(message_low));
    if (bytes_written == -1) {
        perror("write");
        close(fd_red);
        return 1;
    }

    bytes_written = write(fd_yellow, message_low, strlen(message_low));
    if (bytes_written == -1) {
        perror("write");
        close(fd_yellow);
        return 1;
    }

    bytes_written = write(fd_green, message_low, strlen(message_low));
    if (bytes_written == -1) {
        perror("write");
        close(fd_green);
        return 1;
    }

    close(fd_green);
    close(fd_yellow);
    close(fd_red);
    
    return 0;
}